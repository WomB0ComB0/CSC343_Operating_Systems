### Q1 - Effective Instruction Time Calculation

Let's break this down step by step:

1. Base instruction time = 1 microsecond
2. Page switch cost = 1 microsecond
3. Drum characteristics:
   - 3,000 RPM = 50 rotations/second
   - Average rotation wait = 1/(2×50) = 0.01 seconds = 10,000 microseconds
   - Transfer rate = 1M words/second
   - Page size = 1,000 words
   - Page transfer time = 1,000/1,000,000 = 0.001 seconds = 1,000 microseconds

Let's calculate for 100 instructions:

1. 99 instructions access current page: 99 × 1 = 99 microseconds
2. 1 instruction accesses another page:
   - 80% (0.8) find page in memory: 0.8 × (1 + 1) = 1.6 microseconds
   - 20% (0.2) need new page:
     - 50% need to write back modified page
     - Page fault cost = rotation wait + transfer out (if modified) + transfer in
     - 0.2 × [1 + (10,000 + 1,000 × 1.5)] = 2,600 microseconds

Total time for 100 instructions = 99 + 1.6 + 2,600 = 2,700.6 microseconds
Effective instruction time = 2,700.6/100 = 27.006 microseconds
