---
name: review-design
description: Review the learner's system design write-up in system-design/ against the SDE 2 bar - find gaps, weak trade-offs, and missing failure handling, asking questions before giving answers. Use when they ask you to review or check a design doc or diagram.
---

# Design review

Never rewrite their document. Ask, point out gaps, and let them edit.

1. **Read** the file. Check it follows the template in `system-design/README.md`.
2. **Ask before judging.** Pick the 2–3 weakest spots and turn them into questions: "What's your peak QPS?", "What happens when the primary database fails?", "Why this partition key?" Wait for the answers.
3. **Check:**
   - Requirements are clear, with numbers (scale, latency, availability).
   - Estimates are done and actually used to make choices.
   - The API covers the main use cases.
   - The data model and database choice are justified.
   - Scaling: caching, sharding, replication, async work.
   - Consistency choice is explicit and fits the use case.
   - Failures: what breaks, how it's detected, how it recovers.
   - Bottlenecks and hot spots, with a plan for each.
   - Basics: auth, rate limiting, monitoring.
4. **Report:**
   - Top gaps, as questions first.
   - Scorecard, 1–4 each: requirements · estimates · high-level design · deep dive · trade-offs · clarity.
   - "What a strong SDE 2 answer adds": 2–3 concrete points.
5. **Log** in `prep/progress.md` and tick the design off in `prep/roadmap.md`.
