#!/usr/bin/env python3
"""judge.py - compile, run, and stress-test C++ practice solutions.

Commands
  check  FILE.cpp                Compile only (works even without main). Shows warnings.
  run    FILE.cpp [options]      Compile and run.
           --input PATH ...        Input files (globs OK, e.g. "scratch/kadane/*.in").
                                   If NAME.out sits next to NAME.in, the output is compared.
           --stdin TEXT            Inline input. A literal \\n becomes a newline.
           --expect TEXT           Expected output for --stdin (compared token by token).
           (no input option)       Type the input yourself.
  stress SOL.cpp BRUTE.cpp GEN   Compare SOL with a simple, trusted BRUTE on random inputs.
           --runs N (default 300), --seed S (default 1)
           GEN is a .py or .cpp file. It is called as "GEN <seed>" and prints one test input.

Common options
  --time-limit SEC (default 5)   Per-run limit. Slower runs get TIME LIMIT EXCEEDED.
  --fast                         Skip the debug checks (-D_GLIBCXX_DEBUG). Use it to time big inputs.

Exit code: 0 = all good, 1 = a test failed, 2 = compile error or bad usage.
"""

import argparse
import glob
import os
import shutil
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUILD = ROOT / "build"
SCRATCH = ROOT / "scratch"
IS_WINDOWS = os.name == "nt"
EXE_SUFFIX = ".exe" if IS_WINDOWS else ""

BASE_FLAGS = ["-std=c++20", "-O2", "-Wall", "-Wextra", "-Wshadow"]
# Turns silent out-of-range access on STL containers into a clear error message.
DEBUG_FLAGS = ["-D_GLIBCXX_DEBUG", "-D_GLIBCXX_DEBUG_PEDANTIC"]
# Static linking avoids "missing DLL" crashes with MinGW on Windows.
LINK_FLAGS = ["-static"] if IS_WINDOWS else []

CRASH_CODES = {
    0xC00000FD: "stack overflow - recursion too deep, or a big local array",
    0xC0000005: "access violation - bad pointer or index out of range",
    0xC0000094: "integer division by zero",
    0xC0000409: "program aborted - often a failed debug check like an index out of range; read the error output",
    0xC0000135: "a DLL was not found",
    3: "abort() was called - read the error message above",
}
SIGNALS = {
    6: "abort() was called - read the error message above",
    8: "arithmetic error (division by zero?)",
    11: "segmentation fault - bad pointer, index out of range, or stack overflow",
}

MAX_LINES = 40
MAX_CHARS = 3000


def rel(path):
    try:
        return os.path.relpath(path)
    except ValueError:
        return str(path)


def trunc(text):
    lines = text.splitlines()
    shown = "\n".join(lines[:MAX_LINES])
    if len(shown) > MAX_CHARS:
        shown = shown[:MAX_CHARS]
    if len(lines) > MAX_LINES or len(shown) < len("\n".join(lines)):
        shown += f"\n... ({len(lines)} lines total, truncated)"
    return shown


def compiler():
    cxx = os.environ.get("CXX", "g++")
    if shutil.which(cxx) is None:
        print(f"error: C++ compiler '{cxx}' not found. Install g++ or set the CXX environment variable.")
        sys.exit(2)
    return cxx


def compile_cpp(src, fast=False, syntax_only=False):
    """Compile src. Returns the executable path (or src for syntax_only), or None on error."""
    src = Path(src)
    if not src.exists():
        print(f"error: file not found: {src}")
        sys.exit(2)
    flags = BASE_FLAGS + ([] if fast else DEBUG_FLAGS)
    if syntax_only:
        out = src
        cmd = [compiler(), *flags, "-fsyntax-only", str(src)]
    else:
        BUILD.mkdir(exist_ok=True)
        out = BUILD / f"{src.stem}{'-fast' if fast else ''}{EXE_SUFFIX}"
        cmd = [compiler(), *flags, str(src), "-o", str(out), *LINK_FLAGS]
    print(f"Compiling {rel(src)}{' (fast mode)' if fast else ''} ...", flush=True)
    proc = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    messages = (proc.stdout + proc.stderr).strip()
    if proc.returncode != 0:
        print("COMPILE ERROR")
        print(messages)
        return None
    if messages:
        print("Compiler warnings (these are often real bugs):")
        print(messages)
    return out


def explain_exit(code):
    if code < 0:
        return f"signal {-code}: {SIGNALS.get(-code, 'crash')}"
    unsigned = code & 0xFFFFFFFF
    if unsigned in CRASH_CODES:
        shown = hex(unsigned) if unsigned > 255 else str(unsigned)
        return f"exit code {shown}: {CRASH_CODES[unsigned]}"
    return f"exit code {code} - main() should return 0"


def run_exe(exe, data, time_limit):
    """Run exe with data on stdin. Returns (stdout, stderr, seconds, problem or None)."""
    start = time.perf_counter()
    try:
        proc = subprocess.run([str(exe)], input=data, capture_output=True, timeout=time_limit)
    except subprocess.TimeoutExpired:
        return "", "", time_limit, f"TIME LIMIT EXCEEDED (more than {time_limit:g}s)"
    seconds = time.perf_counter() - start
    out = proc.stdout.decode(errors="replace")
    err = proc.stderr.decode(errors="replace")
    if proc.returncode != 0:
        return out, err, seconds, f"RUNTIME ERROR ({explain_exit(proc.returncode)})"
    return out, err, seconds, None


def expected_for(input_path):
    for suffix in (".out", ".ans"):
        candidate = input_path.with_suffix(suffix)
        if candidate.exists() and candidate != input_path:
            return candidate.read_text(errors="replace")
    return None


def collect_cases(args):
    cases = []
    if args.stdin is not None:
        cases.append(("--stdin", args.stdin.replace("\\n", "\n").encode(), args.expect))
    for pattern in args.input or []:
        matches = sorted(glob.glob(pattern)) or [pattern]
        for match in matches:
            path = Path(match)
            if path.suffix in (".out", ".ans"):
                continue
            if not path.is_file():
                print(f"error: input file not found: {match}")
                sys.exit(2)
            cases.append((rel(path), path.read_bytes(), expected_for(path)))
    return cases


def cmd_check(args):
    if compile_cpp(args.file, args.fast, syntax_only=True) is None:
        return 2
    print("OK: compiles.")
    return 0


def cmd_run(args):
    exe = compile_cpp(args.file, args.fast)
    if exe is None:
        return 2
    cases = collect_cases(args)
    if not cases:
        print("No input given. Type it now, then press Ctrl+Z and Enter (Windows) or Ctrl+D (Mac/Linux).")
        return subprocess.call([str(exe)])

    failed = 0
    for name, data, expected in cases:
        out, err, seconds, problem = run_exe(exe, data, args.time_limit)
        if problem:
            verdict = problem
        elif expected is None:
            verdict = "DONE (no expected output to compare)"
        elif out.split() == expected.split():
            verdict = "PASS"
        else:
            verdict = "FAIL (wrong answer)"
        if problem or verdict.startswith("FAIL"):
            failed += 1
        print(f"\n=== {name} | {verdict} | {seconds:.2f}s")
        if verdict != "PASS":
            print("Input:")
            print(trunc(data.decode(errors="replace")))
            print("Output:")
            print(trunc(out) if out.strip() else "(no output)")
            if expected is not None and verdict.startswith("FAIL"):
                print("Expected:")
                print(trunc(expected))
        if err.strip():
            print("Error output (stderr):")
            print(trunc(err))

    total = len(cases)
    print(f"\nSummary: {total - failed}/{total} OK")
    return 1 if failed else 0


def cmd_stress(args):
    solution = compile_cpp(args.solution, args.fast)
    brute = compile_cpp(args.brute, args.fast)
    if solution is None or brute is None:
        return 2
    generator = Path(args.generator)
    if generator.suffix == ".py":
        gen_cmd = [sys.executable, str(generator)]
    else:
        gen_exe = compile_cpp(generator, fast=True)
        if gen_exe is None:
            return 2
        gen_cmd = [str(gen_exe)]

    print(f"Running {args.runs} random tests ...", flush=True)
    for i in range(args.runs):
        seed = args.seed + i
        gen = subprocess.run(gen_cmd + [str(seed)], capture_output=True, timeout=args.time_limit)
        if gen.returncode != 0:
            print(f"Generator failed on seed {seed}:")
            print(gen.stderr.decode(errors="replace"))
            return 2
        data = gen.stdout
        expected, brute_err, _, brute_problem = run_exe(brute, data, args.time_limit)
        if brute_problem:
            print(f"The brute force failed on seed {seed}: {brute_problem}")
            print(trunc(brute_err))
            print("Input:")
            print(trunc(data.decode(errors="replace")))
            return 2
        got, err, _, problem = run_exe(solution, data, args.time_limit)
        if problem or got.split() != expected.split():
            SCRATCH.mkdir(exist_ok=True)
            saved = SCRATCH / "stress-fail.in"
            saved.write_bytes(data)
            print(f"\nFAILED on test {i + 1} (seed {seed}).")
            print("Input:")
            print(trunc(data.decode(errors="replace")))
            print("Expected (brute force):")
            print(trunc(expected))
            if problem:
                print(f"Your program: {problem}")
                if err.strip():
                    print(trunc(err))
            else:
                print("Your output:")
                print(trunc(got))
            print(f"\nSaved this input to {rel(saved)}. Re-run it with:")
            print(f"  python tools/judge.py run {args.solution} --input {rel(saved)}")
            return 1
    print(f"OK: all {args.runs} random tests passed.")
    return 0


def quiet_crashes():
    """On Windows, the crash reporter can hold a crashed program for 20+ seconds (it then looks
    like a time limit). Child processes inherit this error mode, so crashes end immediately."""
    if IS_WINDOWS:
        import ctypes

        sem_failcriticalerrors, sem_nogpfaulterrorbox, sem_noopenfileerrorbox = 0x0001, 0x0002, 0x8000
        ctypes.windll.kernel32.SetErrorMode(sem_failcriticalerrors | sem_nogpfaulterrorbox | sem_noopenfileerrorbox)


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(errors="replace")
    quiet_crashes()
    parser = argparse.ArgumentParser(
        description="Compile, run, and stress-test C++ practice solutions.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    common = argparse.ArgumentParser(add_help=False)
    common.add_argument("--time-limit", type=float, default=5.0, help="seconds per run (default 5)")
    common.add_argument("--fast", action="store_true", help="skip debug checks, for timing big inputs")
    sub = parser.add_subparsers(dest="command", required=True)

    p_check = sub.add_parser("check", parents=[common], help="compile only")
    p_check.add_argument("file")
    p_check.set_defaults(func=cmd_check)

    p_run = sub.add_parser("run", parents=[common], help="compile and run")
    p_run.add_argument("file")
    p_run.add_argument("--input", nargs="+", help="input files (globs OK)")
    p_run.add_argument("--stdin", help=r"inline input; a literal \n becomes a newline")
    p_run.add_argument("--expect", help="expected output for --stdin")
    p_run.set_defaults(func=cmd_run)

    p_stress = sub.add_parser("stress", parents=[common], help="compare with a brute force on random inputs")
    p_stress.add_argument("solution")
    p_stress.add_argument("brute")
    p_stress.add_argument("generator")
    p_stress.add_argument("--runs", type=int, default=300)
    p_stress.add_argument("--seed", type=int, default=1)
    p_stress.set_defaults(func=cmd_stress)

    args = parser.parse_args()
    sys.exit(args.func(args))


if __name__ == "__main__":
    main()
