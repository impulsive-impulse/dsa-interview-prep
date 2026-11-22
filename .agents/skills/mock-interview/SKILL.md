---
name: mock-interview
description: Run a realistic mock interview at the SDE 2 bar - either a 45-minute DSA coding round or a 45-60 minute system design round - and finish with an honest scorecard and hire/no-hire signal. Use when the learner asks for a mock, interview practice, or "test me".
---

# Mock interview

Ask first: "Coding or system design?" and "Any topic, or should I surprise you?"
Stay in character as the interviewer until the debrief. Don't teach during the mock. Note things for the debrief instead.

## Coding round (45 minutes)

- Pick a problem they haven't solved, matching the roadmap and their weak spots. Mediums first, hards later.
- Give it like a real interviewer: short, and a bit vague on purpose. They should ask clarifying questions. Don't name the pattern.
- Ask them to say "start" and to tell you the time at each checkpoint:
  - ~5 min: clarifications and examples done
  - ~15 min: approach and complexity agreed
  - ~35 min: code done
  - ~45 min: tested by hand, plus one follow-up
- They code in `scratch/mock-<date>-<problem>.cpp`.
- If they're stuck for a while, give a small nudge — as a real interviewer would. Note each nudge; it lowers the score a little.
- After the code: ask them to dry-run it on an example. Then ask one follow-up (bigger input, a stream, a variant).
- Then run their code with `tools/judge.py` on edge cases you didn't share.

## System design round (45–60 minutes, SDE 2)

Use a design from `prep/roadmap.md` they haven't done, or their choice.
Let them drive. Step in only if they skip something important:
1. Requirements: functional and non-functional (scale, latency, availability, consistency).
2. Estimates: users, QPS, storage, bandwidth. Rough is fine.
3. API.
4. Data model and database choice — and why.
5. High-level design: clients, load balancer, services, cache, database, queue, CDN.
6. Deep dive into 1–2 parts. You pick.
7. Bottlenecks, failures, trade-offs, monitoring.

Probe like a real interviewer: "What happens if this cache goes down?", "Traffic grows 10x — what breaks first?", "Why SQL here?"

## Debrief (always)

Scorecard, 1–4 each, with one line of evidence:
- **Coding:** problem solving · coding · testing · complexity · communication
- **System design:** requirements · estimates · high-level design · deep dive · trade-offs · communication

Then:
- **Overall at the SDE 2 bar:** strong hire / hire / lean no hire / no hire. Be honest; a kind "no" now beats a real one later.
- **Top 3 things to fix**, each with one concrete drill.
- **1–2 things they did well.**

Log it in `prep/progress.md`: the "Mock interviews" table, weak spots, and the session log.
