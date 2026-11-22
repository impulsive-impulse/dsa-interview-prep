# DSA interview prep

My practice repo for SDE 2 interviews: DSA in C++ and system design.

## What's here

| Folder | What |
|---|---|
| `dsa/<topic>/` | My solutions, one problem per file. Topics follow NeetCode 150. |
| `system-design/` | My system design write-ups, plus a template. |
| `prep/` | Roadmap, progress log, problem list, and pattern notebook. |
| `tools/judge.py` | Compile, run, and stress-test C++ solutions. |

Start with [`prep/problems.md`](prep/problems.md) to see what needs work.

## AI interview coach

AI coding agents that read [`AGENTS.md`](AGENTS.md) — GitHub Copilot, Codex, Cursor, and others — act as a demanding but kind interview coach here:

- Hints in steps, not answers. Full code only when I ask for it.
- Reviews my code like an interviewer: compiles, tests edge cases, stress-tests, and gives a scorecard.
- Mock interviews (coding and system design) with an honest hire / no-hire.
- Tracks weak spots and schedules revision in `prep/progress.md`.

Detailed playbooks are in [`.agents/skills/`](.agents/skills). Things to try:

- "What should I practice next?"
- "Review `dsa/greedy/kadane.cpp`"
- "Explain binary search on the answer"
- "Mock interview: coding" or "Mock interview: system design, URL shortener"
- "Let's revise"

## Run code

Needs g++ (C++20) and Python 3.

```
python tools/judge.py check dsa/sorting/merge-sort.cpp
python tools/judge.py run dsa/greedy/kadane.cpp --stdin "5\n1 2 3 -2 5" --expect "9"
python tools/judge.py run dsa/greedy/kadane.cpp --input "scratch/kadane/*.in"
python tools/judge.py stress my.cpp brute.cpp gen.py
```

`run` compares the output with a matching `.out` file when there is one. Add `--fast` to time big inputs.
