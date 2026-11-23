# Problems

Every problem in this repo and its status. The coach keeps this file up to date.

**Status:** ✅ solid · ⚠️ wrong answer · 💥 crashes · 🐢 too slow · ❌ doesn't compile · 🚧 unfinished · 📘 notes

Hints below use the judge's input format: `\n` means a new line. Try one yourself:

```
python tools/judge.py run dsa/greedy/kadane.cpp --stdin "3\n-2 -1 -3" --expect "-1"
```

## Needs work — start here

First audit: 22 Nov 2026. Every claim below was checked by compiling and running the code.
Each row gives you a **first hint**: a test that fails. Find the bug yourself first.
Stuck? Ask the coach for the next hint. The spoilers at the bottom are the last resort.

| # | File | Status | First hint |
|---|---|---|---|
| 1 | `dsa/sorting/merge-sort.cpp` | ❌ | Compile it: `python tools/judge.py check dsa/sorting/merge-sort.cpp` |
| 2 | `dsa/greedy/k-concatenation-max-sum.cpp` | ❌ ⚠️ | 2 compile errors. After you fix them: `3 3\n5 -20 5` → `10`, and `2 2\n-1 -2` → `-1` |
| 3 | `dsa/greedy/kadane.cpp` | ⚠️ | `5\n1 2 3 -2 5` → `9` (you print `0`). Then `3\n-2 -1 -3` → `-1`. Two different bugs. |
| 4 | `dsa/heap/hussain-set.cpp` | ⚠️ 💥 | `3 3\n8 5 3\n1\n2\n5` → `8 5 2` (you print `8 5 3`). And `1 1\n8\n4` → `1` (crashes). |
| 5 | `dsa/sorting/quick-sort.cpp` | 🚧 ⚠️ | `main()` is empty. Add one, then sort `2 3 1`. |
| 6 | `dsa/arrays-hashing/mind-bending-product.cpp` | ⚠️ | `3\n100000 100000 100000` → `10000000000` three times (you print `1410065408`) |
| 7 | `dsa/intervals/chef-restaurant.cpp` | 🐢 ⚠️ | The brute force takes over 5 s for 100,000 intervals and 100,000 queries. The fast version (commented out) is wrong: intervals `[5,10)` and `[20,30)`, query `7` → should be `[5, 10)` |
| 8 | `dsa/arrays-hashing/longest-consecutive-sequence.cpp` | 🚧 🐢 | No `main` yet. Then time it on 50,000 copies of `1` followed by `2..50001`: about 5 s here. It should take milliseconds. |
| 9 | `dsa/sorting/inversion-count.cpp` | 💥 | Correct on 300 random small tests, but crashes (stack overflow) when n = 1,000,000 |
| 10 | `dsa/binary-search/aggressive-cows.cpp` | 🚧 | Only the statement so far |
| 11 | `dsa/intervals/warm-reception.cpp` | 🚧 | No `main`. Decide: one guest leaves at time 5 and another arrives at 5 — 1 chair or 2? And what if n = 0? |
| 12 | `dsa/recursion/string-length-and-remove-x.cpp` | 🚧 | No `main` or tests |
| 13 | `dsa/backtracking/subsequences-of-string.cpp` | 🚧 | No `main` or tests |
| 14 | `dsa/math-geometry/area-of-rectangles.cpp` | 🚧 | No `main` (the logic passes the sample) |
| 15 | `dsa/backtracking/rat-in-a-maze.cpp` | ❌ ⚠️ | Kept as a record with FIX comments. Re-solve it from scratch (it's in the review queue) and test `2\n1 1\n1 0` → no output |
| 16 | `dsa/backtracking/crossword-puzzle.cpp` | 🚧 | Coach gave the full solution as FIX comments. Re-solve it from scratch (it's in the review queue) and pass the HackerRank samples |

## All problems

"Same as" links your problem to the LeetCode version. **NC** = it's in NeetCode 150, so it counts toward the roadmap.

| Topic | File | Was called | Same as | Status | Level-up question |
|---|---|---|---|---|---|
| basics | `dsa/basics/stl-functions.cpp` | stl-functions.cpp | — | 📘 | — |
| basics | `dsa/basics/2d-arrays.cpp` | 2d-arrays.cpp | — | 📘 | — |
| sorting | `dsa/sorting/merge-sort.cpp` | MergeSort.cpp | LC 912 | ❌ | Is your merge sort stable? Why does that matter? |
| sorting | `dsa/sorting/quick-sort.cpp` | QuickSort.cpp | LC 912 | 🚧 ⚠️ | What is the worst case with the first element as pivot? |
| sorting | `dsa/sorting/inversion-count.cpp` | InversionCount.cpp | ≈ LC 315 | 💥 | Why is `count += mid - i` correct? |
| recursion | `dsa/recursion/fibonacci.cpp` | fibionacci-numbers.cpp | LC 509 | ✅ 🐢 | n = 47 takes over 5 s. Why? Make it O(n). And what does `1LL *` do here? |
| recursion | `dsa/recursion/string-length-and-remove-x.cpp` | AdvancedRecursion-1.cpp | — | 🚧 | What is the time complexity of `removeX`? |
| arrays-hashing | `dsa/arrays-hashing/mind-bending-product.cpp` | MindBendingProblem.cpp | LC 238 · NC | ⚠️ | Can you do it with O(1) extra space? |
| arrays-hashing | `dsa/arrays-hashing/longest-consecutive-sequence.cpp` | LongestConsecutiveSum.cpp | LC 128 · NC | 🚧 🐢 | Why is the set-based solution O(n)? |
| arrays-hashing | `dsa/arrays-hashing/permutation-and-palindrome.cpp` | PermutationAndPalindrome.cpp | CodeChef | ✅ | `int ans[n]` is a variable-length array. Why avoid it in C++? |
| two-pointers | `dsa/two-pointers/total-variation-count.cpp` | ZonalComputingOlympiad.cpp | ZCO | ✅ | What is the largest possible answer? Does it fit in `int`? |
| sliding-window | `dsa/sliding-window/buy-low-sell-high.cpp` | BuyLowSellHigh.cpp | LC 121 · NC | ✅ | Why pass `prices` by `const&`? What if you may trade many times? |
| binary-search | `dsa/binary-search/aggressive-cows.cpp` | AggressiveCows.cpp | ≈ LC 1552 | 🚧 | What makes "binary search on the answer" work here? |
| heap | `dsa/heap/hussain-set.cpp` | HasanHussain.cpp | CodeChef | ⚠️ 💥 | Why can a plain queue replace the heap here? |
| intervals | `dsa/intervals/warm-reception.cpp` | WarmReception.cpp | ≈ LC 253 · NC | 🚧 | How would you solve it with a min-heap instead? |
| intervals | `dsa/intervals/chef-restaurant.cpp` | ChefRestaurant.cpp | CodeChef | 🐢 ⚠️ | What does `lower_bound` return exactly? |
| greedy | `dsa/greedy/kadane.cpp` | kadane.cpp | LC 53 · NC | ⚠️ | Return the start and end index too. |
| greedy | `dsa/greedy/k-concatenation-max-sum.cpp` | largestSumSubarray.cpp | LC 1191 | ❌ ⚠️ | Why are at most 2 copies enough when the total is negative? |
| dp-1d | `dsa/dp-1d/max-product-subarray.cpp` | maxProductSubarray.cpp | LC 152 · NC | ✅ | The unused `maxSubArrayProduct2` is buggy — delete dead code. Why track the minimum? |
| backtracking | `dsa/backtracking/n-queens.cpp` | BackTracking-1.cpp | LC 51 · NC | ✅ | It ignores input (n = 4 is fixed). Can `isPossible` be O(1)? |
| backtracking | `dsa/backtracking/subsequences-of-string.cpp` | SubSequencesOfString.cpp | ≈ LC 78 · NC | 🚧 | How many subsequences are there, and what is the total time? |
| backtracking | `dsa/backtracking/rat-in-a-maze.cpp` | RatMaze.cpp | ≈ GfG Rat in a Maze | ❌ ⚠️ | Why is the depth n², not n? How would you return the paths as strings like "DRDR"? |
| backtracking | `dsa/backtracking/keypad-combinations.cpp` | KeypadCombination.cpp | LC 17 · NC | ✅ | What should input `21` print? |
| backtracking | `dsa/backtracking/crossword-puzzle.cpp` | Crossword.cpp | HackerRank Crossword Puzzle | 🚧 | Find all slots first, then match words to slots of the same length. Why is that faster? |
| math-geometry | `dsa/math-geometry/area-of-rectangles.cpp` | area-of-rectangles.cpp | LC 223 | 🚧 | Can `x2 - x1` overflow before the `1LL *`? |

## Spoilers — coach notes

Open these only after you've really tried. The coach uses them to choose your next hint.

<details>
<summary>1. merge-sort.cpp</summary>

Line 18: `< =` has a space in it. It must be `<=`. Lesson: always compile before calling it done.
</details>

<details>
<summary>2. k-concatenation-max-sum.cpp</summary>

- Compile error 1: `max(currSum + x, x)` mixes `long long` and `int`. `std::max` needs both sides to be the same type.
- Compile error 2: `curr_prefix_Sum` vs `curr_prefix_sum` (typo).
- Logic 1: the same bug as kadane.cpp. `maxSum = 0` is wrong when every number is negative.
- Logic 2: when the total sum is negative, the best subarray can still cross ONE boundary (suffix of one copy + prefix of the next, no middle copies). Your formula always adds `(k - 2) * total`.
</details>

<details>
<summary>3. kadane.cpp</summary>

- `arr` is never read from input, so it is all zeros.
- `maxSum = 0` returns 0 for an all-negative array, but the subarray must have at least one element. Start from `arr[0]` (or `LLONG_MIN`).
</details>

<details>
<summary>4. hussain-set.cpp</summary>

- Between queries you reset `iterator` but not `q`, so the state is half reset. The queue trick only works in ONE continuous simulation.
- When the sorted array runs out (`iterator < 0`), the code still reads `input[iterator]`, which is out of bounds.
- Restarting from move 1 for every query is slow. If queries come in increasing order (check the statement), continue from where the last query stopped.
- Check the constraints: do your `int` types fit `A[i]` and the answers?
</details>

<details>
<summary>5. quick-sort.cpp</summary>

After `swap(arr[start], arr[pivotIndex])`, the value now at `start` can be bigger than the pivot. Your scan starts at `start + 1`, so that value is never checked.
</details>

<details>
<summary>6. mind-bending-product.cpp</summary>

`leftProduct` is `long long`, but `product` is a `vector<int>`, so big values get cut when stored. Also check the real constraints: can the product overflow even `long long`?
</details>

<details>
<summary>7. chef-restaurant.cpp</summary>

- The brute force is O(N·M), too slow for 10^5 × 10^5.
- `lower_bound(..., {q, INT_MIN})` finds the first interval that starts at or after `q`. It skips the interval that *contains* `q`, because that one starts before `q`. Use `upper_bound`, then also check the interval just before it.
- Double-check the original statement. I believe the CodeChef version asks for the *waiting time* (0 if open now, -1 if never), not the interval.
</details>

<details>
<summary>8. longest-consecutive-sequence.cpp</summary>

You loop over `nums`, not over the set. With many copies of a sequence start, the same sequence is walked again and again, which is O(n²). Loop over the set instead. You also don't need to build `currentSeq` each time; track the start and the length.
</details>

<details>
<summary>9. inversion-count.cpp</summary>

`int temp[right - left + 1]` is a variable-length array. It is not standard C++, and it lives on the stack (usually only 1–8 MB). For n = 10^6 the top-level call needs 4 MB, so the stack overflows. Use a `vector<int>` (heap memory) instead.
</details>
