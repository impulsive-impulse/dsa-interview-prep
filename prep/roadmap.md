# Roadmap — SDE 2 in 1–3 months

**Goal:** pass SDE 2 coding rounds (DSA in C++) and the system design round.
**Start:** Monday 23 Nov 2026. **Finish line:** about 12 weeks, so late Feb 2027.

The coach follows this plan, checks items off, and adjusts the pace in `progress.md`.
If your interview date gets fixed sooner, tell the coach. It will switch to the fast track below.

## Phase 0 — Clean up (week of 23 Nov)
- [ ] Clear the "Needs work" list in `problems.md` (14 items)
- [ ] Keep going with your current problems (Rat in a Maze, etc.)

## Phase 1 — DSA: NeetCode 150

Problem list: https://neetcode.io/practice (pick "NeetCode 150"). Folder names in `dsa/` match these topics.
Easy problems: move fast. Mediums: this is where the SDE 2 bar is. Hards: try them, but don't get stuck.

| Week | Dates | Topics | Done |
|---|---|---|---|
| 1 | 30 Nov – 6 Dec | Arrays & Hashing, Two Pointers | [ ] |
| 2 | 7 – 13 Dec | Sliding Window, Stack | [ ] |
| 3 | 14 – 20 Dec | Binary Search, Linked List | [ ] |
| 4 | 21 – 27 Dec | Trees | [ ] |
| 5 | 28 Dec – 3 Jan | Tries, Heap / Priority Queue, Intervals | [ ] |
| 6 | 4 – 10 Jan | Backtracking, Greedy | [ ] |
| 7 | 11 – 17 Jan | Graphs | [ ] |
| 8 | 18 – 24 Jan | Advanced Graphs, 1-D DP | [ ] |
| 9 | 25 – 31 Jan | 2-D DP, Bit Manipulation, Math & Geometry | [ ] |
| 10–12 | 1 – 21 Feb | Mixed problems, mocks, revision | [ ] |

## Phase 2 — System design (from week 2, about 3 sessions a week)

### Fundamentals (weeks 2–5)
- [ ] Back-of-the-envelope estimates (QPS, storage, bandwidth)
- [ ] Scaling: vertical vs horizontal, stateless services, load balancers
- [ ] Caching: where to cache, cache-aside vs write-through, eviction, invalidation
- [ ] Databases: SQL vs NoSQL, indexes, replication, sharding
- [ ] Consistency: CAP, strong vs eventual consistency
- [ ] Async work: message queues, pub/sub, retries, idempotency
- [ ] CDN and blob storage
- [ ] API design: REST, pagination, rate limiting
- [ ] Unique ID generation, consistent hashing
- [ ] Reliability: failover, monitoring, alerting

### Practice designs (weeks 5–12, 1–2 a week)
- [ ] URL shortener
- [ ] Rate limiter
- [ ] Distributed cache / key-value store
- [ ] Notification system
- [ ] News feed
- [ ] Chat app
- [ ] File storage and sync (like Dropbox)
- [ ] Typeahead / autocomplete
- [ ] Web crawler
- [ ] Ticket booking (seat reservation)
- [ ] Video streaming (like YouTube)
- [ ] Ride sharing (like Uber)

### Low-level design (weeks 8–11)
Many SDE 2 loops also have an object-oriented design round. Ask your recruiter.
- [ ] OOP and SOLID basics. Common patterns: Strategy, Factory, Observer, Singleton
- [ ] Practice: parking lot, LRU cache, elevator, Splitwise, library system

## Phase 3 — Interview ready (weeks 10–12)
- [ ] 2 coding mocks and 1 system design mock every week
- [ ] Re-solve everything in the review queue
- [ ] Every solution in this repo: you can explain the approach, complexity, and trade-offs

## "Ready" checklist
- [ ] Solve a new medium in 25 minutes or less, 4 times out of 5
- [ ] At least 120 of the NeetCode 150 solved, every topic touched
- [ ] 3 coding mocks in a row at "Hire" or better
- [ ] 2 system design mocks at "Hire" or better

## Fast track (if the interview is 4–6 weeks away)
- DSA: Arrays & Hashing, Two Pointers, Sliding Window, Binary Search, Trees, Graphs, Heap, Intervals, 1-D DP. Skip the rest at first.
- System design: fundamentals in week 1, then one practice design every 2–3 days.
- Mocks from week 2: 2 coding and 1 system design every week.
