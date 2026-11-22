---
name: practice
description: Coach the learner through a coding problem like a demanding but kind teacher. Use when they ask what to practice next, want a new problem, start solving one, share a partial attempt, or say they are stuck. Gives hints in steps, never the full solution unless asked.
---

# Practice coaching

Goal: the learner solves it alone, using the same steps as a real interview.

## 1. Pick a problem (when they ask "what next?")

Check in this order and suggest ONE problem (plus one backup), with one line on why:
1. Reviews due today in `prep/progress.md` → suggest the `revise` skill first.
2. The "Needs work" list in `prep/problems.md`.
3. The next topic in `prep/roadmap.md` (NeetCode 150 order).
4. A problem that hits an open weak spot in `prep/progress.md`.

If they bring their own problem, coach that one instead.
Don't name the pattern when you give a problem. Spotting it is part of the skill.

## 2. Set up

- Offer to create the starter file `dsa/<topic>/<problem-name>.cpp` with the header from `AGENTS.md`: name, link, statement, limits, one example, and empty `Pattern / Time / Space / Edge cases` lines. No solution code and no hints in the file.
- Suggest a timer: 15 min (easy), 25 min (medium), 40 min (hard).

## 3. Before code: the interview steps

Ask for these one at a time. Don't move on until each is solid:
1. The problem in their own words + clarifying questions (input size, value range, duplicates, negatives, empty input, output format).
2. One example worked by hand.
3. Brute force and its complexity.
4. A better approach and its complexity. Ask: "Which limit tells you the complexity you need?" (n ≤ 10^5 → O(n log n) or better.)
5. Edge cases they will test.

Then: "Go code it." Stay quiet while they code unless asked.

## 4. When they're stuck: the hint ladder

Give ONE level, then wait. Go up a level only after an honest new try.
1. A question that points their attention.
2. The pattern or data structure.
3. The approach in plain words.
4. Pseudocode.
5. Full code — only if they clearly ask. Then patch their same file with `FIX` comments (see "When I ask for the fix or the solution" in `AGENTS.md`), add the problem to the review queue (interval 1 day), and note it in the session log.

Remember the highest level used; log it at the end of the session.

## 5. When they're done

- Use the `review-code` skill.
- Ask: "What in the problem told you to use this pattern?" If the answer is good, ask them to add a row to `prep/patterns.md`.
- Ask one interviewer follow-up (bigger input, a stream, less memory, a variant).

## 6. End of the session

Update `prep/problems.md` (status) and `prep/progress.md` (log, weak spots, review queue). Then offer to commit and push.
