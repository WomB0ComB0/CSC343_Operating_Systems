# Memory Management Simulator Program

### Problem Description:
Write a memory management simulator program that assumes your computer has a memory size of **16 GB**, divided into **100 pages**. Each page has a size of **160 MB**. Your program will create an array of 100 elements, where each element holds the **processor number**. You will implement the `userMemoryAllocation` method to create processes until all memory pages are occupied by process numbers.

Before the program terminates, you will generate a report showing the jobs/processes status in memory. The process allocation starts from **memory address 2000** upwards.

### Summary Report Format Example:

| Process Id | Starting Memory Address | Size of the Process (MB) | Unused Space (MB) |
|------------|--------------------------|--------------------------|-------------------|
| 4          | 2000                     | 2500                     | 60                |

### Method: `userMemoryAllocation`

By using a random number generator, you will create a loop until the memory is fully allocated.

- **Generate a number** between **1 to 30** to determine the size of a process.
- The **loop index** value will be used as the process number, and the generated number determines the number of pages that will be allocated.
- **Each number represents 80 MB.**
- The **size of the process** is computed by multiplying the number of pages by 80.

### Example:

- **Random Number** = 25 (number of pages)
- **Process size** = 25 × 80 = **2000 MB**

### Steps:

1. **Calculate the number of memory pages required**:
   - \( \frac{2000}{160} = 12.5 \)
   - Round up to the nearest integer, so **13 memory pages** are required to store the process in memory.

2. **Find the unused memory space**:
   - Total memory allocated by 13 pages = \( 13 \times 160 = 2080 \) MB
   - Unused memory space = \( 2080 - 2000 = 80 \) MB

3. **Calculate the next process starting address**:
   - \( 2000 + 2080 = 4080 \)

Continue the process allocation until the memory array is fully occupied by process numbers.
