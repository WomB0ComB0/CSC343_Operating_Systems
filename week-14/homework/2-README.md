### Q2 - Virtual to Physical Address Translation

For a 256-byte page size:

- Offset bits = 8 (log₂256)
- Page number bits = 4 (12-8)

Let's solve each address:

1. 9EF:
   - Page number = 9
   - Offset = EF
   - Page frame = 0
   - Physical address = 0EF

2. 111:
   - Page number = 1
   - Offset = 11
   - Page frame = 2
   - Physical address = 211

3. 700:
   - Page number = 7
   - Offset = 00
   - Not in memory (page fault)

4. 0FF:
   - Page number = 0
   - Offset = FF
   - Not in memory (page fault)
