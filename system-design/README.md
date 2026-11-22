# System design

One file per design, e.g. `system-design/url-shortener.md`. You write it; the coach reviews it (the `review-design` skill).
The list of designs to practice is in `prep/roadmap.md`.

Interview time split (45–60 min): requirements and estimates ~10 min, API and data model ~10 min, high-level design ~15 min, deep dive and trade-offs ~15 min.

## Template

Copy this into a new file:

```markdown
# <System name>

## 1. Requirements
- Functional (what it does):
- Non-functional (scale, latency, availability, consistency):
- Out of scope:

## 2. Estimates
- Daily active users, read:write ratio
- QPS (average and peak)
- Storage per year, bandwidth

## 3. API
- `POST /...` →
- `GET /...` →

## 4. Data model
- Tables / collections and key fields
- Database choice, and why

## 5. High-level design
(Mermaid diagram or a list of boxes and arrows)

## 6. Deep dives (pick 1–2)
-

## 7. Scaling, failures, and trade-offs
- Bottlenecks and how to fix them
- What happens when <part> fails?
- Trade-offs I chose, and the alternatives

## 8. Open questions for the interviewer
-
```
