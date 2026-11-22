# Progress

The coach updates this file at the end of every practice session. Keep it short and current.

## Current focus

- **Now:** clear the "Needs work" list in `problems.md`, alongside your current problems.
- **In progress:** Rat in a Maze — `RatMaze.cpp` in the repo root. When it's done, move it to `dsa/backtracking/rat-in-a-maze.cpp` and add it to `problems.md`.
- **Next:** NeetCode 150, starting with Arrays & Hashing (see `roadmap.md`).
- **Interview date:** not fixed yet. Target: 1–3 months (by late Feb 2027).

## Weak spots

Repeated mistakes. A weak spot is "fixed" after 3 clean problems in a row on it.

| Weak spot | Evidence | Drill | Status |
|---|---|---|---|
| Calling it done without compiling and running | 2 files don't compile; `quick-sort.cpp` was never run; 6 files have no `main` | Before moving on: compile, run the samples, run 2 edge cases | suspected (first audit) |
| Edge cases: all-negative input, empty input | `kadane.cpp`, `k-concatenation-max-sum.cpp` | Before coding, list 3 edge cases. Test them after. | suspected (first audit) |
| Integer types and overflow | `mind-bending-product.cpp` | For every variable, ask: what is the biggest value it can hold? | suspected (first audit) |
| Checking complexity against the limits | `chef-restaurant.cpp`, `longest-consecutive-sequence.cpp`, `hussain-set.cpp` | Before coding, write: max n, then the complexity you need | suspected (first audit) |
| Stack vs heap memory | `inversion-count.cpp` | Never use `int a[n]`; use `vector`. Big inputs mean no deep recursion | suspected (first audit) |

## Review queue (spaced repetition)

Re-solve from scratch or explain from memory. Intervals: 1 → 3 → 7 → 14 → 30 days.
Easy → next interval. Some gaps → same interval. Needed hints → back to 1 day.

| Problem | File | Last done | Next review | Interval | Notes |
|---|---|---|---|---|---|
| Buy low sell high | `dsa/sliding-window/buy-low-sell-high.cpp` | 2026-11-15 | 2026-11-24 | 3 | |
| Max product subarray | `dsa/dp-1d/max-product-subarray.cpp` | 2026-11-16 | 2026-11-24 | 3 | Explain why we track the minimum |
| Total variation count | `dsa/two-pointers/total-variation-count.cpp` | 2026-11-19 | 2026-11-25 | 3 | |
| Permutation and palindrome | `dsa/arrays-hashing/permutation-and-palindrome.cpp` | 2026-11-18 | 2026-11-26 | 3 | |
| Keypad combinations | `dsa/backtracking/keypad-combinations.cpp` | 2026-11-21 | 2026-11-27 | 3 | |
| N-Queens | `dsa/backtracking/n-queens.cpp` | 2026-11-22 | 2026-11-28 | 3 | Try the O(1) safety check |

## Mock interviews

| Date | Type | Problem / system | Result | Top thing to fix |
|---|---|---|---|---|

## Session log

Newest first. 3–5 bullets per session.

### 2026-11-22 — Setup
- Repo organized into `dsa/<topic>/` folders. The coach setup was added (`AGENTS.md`, skills, `prep/`, `tools/judge.py`).
- First audit of all 23 files, backed by real test runs: 7 solid, 14 need work, 2 are notes. See `problems.md`.
- Weak spots above come from that audit. They are "suspected" until confirmed in practice.
