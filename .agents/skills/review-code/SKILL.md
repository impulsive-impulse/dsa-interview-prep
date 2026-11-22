---
name: review-code
description: Review the learner's C++ solution like a strict interviewer. Compile it, test edge cases, stress-test it against a brute force, score it against the SDE 2 bar, and give hints instead of fixes. Use when they ask to review, check, test, or judge a solution ("is this correct?", "is this optimal?").
---

# Code review, interviewer style

Never edit their solution file. Never paste the fixed code unless they clearly ask for it.

## Steps

1. **Read** the file and the problem statement in the header. If limits are missing, ask for them.
2. **Ask first** (skip if they already said it): "What's your time and space complexity? Which edge cases did you test?" Wait for the answer.
3. **Compile:** `python tools/judge.py check <file>`. Read the warnings — they often point to real bugs.
4. **Test.** Put inputs in `scratch/<problem>/` as `1.in`, `1.out`, ... and run `python tools/judge.py run <file> --input "scratch/<problem>/*.in"`. Cover:
   - The samples from the statement.
   - Smallest input, all equal values, all negative, zeros, duplicates, sorted and reverse sorted.
   - Biggest values (overflow) and biggest size (time; use `--fast`).
   Only write a `.out` file when you are sure of the answer.
   If the file has no `main`, write a driver in `scratch/` that `#include`s it.
5. **Stress test** when a brute force is easy: write `scratch/<problem>/brute.cpp` and `gen.py` (called as `gen.py <seed>`, prints one input), then run `python tools/judge.py stress <file> scratch/<problem>/brute.cpp scratch/<problem>/gen.py`. Show the smallest failing input.
6. **Report** — short:
   - **Verdict:** ✅ accepted · ⚠️ wrong answer · 💥 crash · 🐢 too slow · ❌ doesn't compile.
   - **Each issue as a hint**, starting with the failing input or a question. Give the cause only if they are stuck after trying (hint ladder from `AGENTS.md`).
   - **Scorecard (1–4):** correctness · complexity · edge cases · code quality · explanation.
   - **SDE 2 bar:** yes / almost / not yet — and the ONE most important thing to improve.
   - **One follow-up** an interviewer would ask.
7. **Log:** update `prep/problems.md` and `prep/progress.md` (weak spots, review queue).

## C++ checklist

- Overflow: `long long` for big sums and products; write `1LL * a * b`, not `a * b`.
- Uninitialized variables. Off-by-one in loops and binary search bounds.
- Index out of range: negative index, `i <= n`, empty container.
- `v.size()` is unsigned: `v.size() - 1` wraps around when `v` is empty.
- Pass big containers by `const&`, not by value.
- `int a[n]` (variable-length array) is not standard C++ and can overflow the stack. Use `vector`.
- Deep recursion (depth around 10^5 or more) can overflow the stack.
- State not reset between test cases or queries.
- Input: is everything actually read? Multiple test cases?
- Output format: spaces, new lines, `-1` cases.
- `endl` flushes every time; use `'\n'` for big outputs.

## Code quality at SDE 2

- Clear names, small functions, no magic numbers.
- No dead or duplicate code left in the file.
- Could they explain every line, out loud, in an interview?
