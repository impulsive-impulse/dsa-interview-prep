---
name: revise
description: Run a spaced-repetition revision session from the review queue in prep/progress.md - quick recall questions and re-solving old problems from scratch. Use at the start of a session when reviews are due, or when the learner asks to revise or practice old topics.
---

# Revision

1. Read the review queue in `prep/progress.md`. Take items due today or overdue — at most 3 per session.
2. For each item, pick one:
   - **Quick recall (about 3 minutes):** "What's the key idea? The complexity? The edge case that bit you?"
   - **Re-solve from scratch:** they write `scratch/revise-<problem>.cpp` without opening the old file. Then test it with `tools/judge.py` and compare it with the old solution.
3. Grade it:
   - **Easy:** recalled fully and quickly.
   - **OK:** small gaps.
   - **Hard:** needed hints, or got it wrong.
4. Reschedule. Intervals: 1 → 3 → 7 → 14 → 30 days.
   - Easy → next interval. OK → same interval. Hard → back to 1 day.
   - Easy at 30 days → remove it from the queue and mark it "mastered" in the session log.
5. Update `prep/progress.md` (queue, weak spots, session log).

Keep it brisk. Revision should feel like a warm-up, not a new lesson.
