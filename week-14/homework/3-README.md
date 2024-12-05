### Q3 - Page Fault Calculations

Let's calculate page faults for each algorithm with different frame sizes. I'll show the calculation for 3 frames as an example:

LRU (3 frames):
1,2,3 (3 faults) → 4 (fault) → 2,1 (2 faults) → 5 (fault) → 6 (fault) → 2,1 (no faults) → 2,3 (1 fault) → 7 (fault) → 6,3 (1 fault) → 2,1 (2 faults) → 2,3 (1 fault) → 6 (fault)
Total: 12 faults

Complete results:
LRU:

- 1 frame: 20 faults
- 2 frames: 18 faults
- 3 frames: 12 faults
- 4 frames: 10 faults
- 5 frames: 8 faults
- 6 frames: 6 faults
- 7 frames: 6 faults

FIFO:

- 1 frame: 20 faults
- 2 frames: 18 faults
- 3 frames: 15 faults
- 4 frames: 10 faults
- 5 frames: 8 faults
- 6 frames: 6 faults
- 7 frames: 6 faults

Optimal:

- 1 frame: 20 faults
- 2 frames: 15 faults
- 3 frames: 11 faults
- 4 frames: 8 faults
- 5 frames: 7 faults
- 6 frames: 6 faults
- 7 frames: 6 faults
