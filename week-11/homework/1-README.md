{{REWRITTEN_CODE}}
## Q1. Explain the difference between preemptive and non-preemptive scheduling.

## Q2. Consider the following set of processes, with the length of the CPU burst time given in milliseconds:

| Process | Burst Time | Priority |
|---|---|---|
| P1 | 2 | 2 |
| P2 | 1 | 1 |
| P3 | 8 | 4 |
| P4 | 4 | 2 |
| P5 | 5 | 3 |

The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.

**a.** Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, non-preemptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).

**b.** What is the turnaround time of each process for each of the scheduling algorithms in part a?

**c.** What is the waiting time of each process for each of these scheduling algorithms?

**d.** Which of the algorithms results in the minimum average waiting time (over all processes)?

## Q3. Consider two processes, P1 and P2, where p1 = 50, t1 = 25, p2 = 75, and t2 = 30.

**a.** Can these two processes be scheduled using rate-monotonic scheduling? Illustrate your answer using a Gantt chart such as the ones in Figure 5.21–Figure 5.24.

**b.** Illustrate the scheduling of these two processes using earliest-deadline-first (EDF) scheduling.

## Q4. Write a program (C++ or Java) that computes turnaround time and average wait time for the processes listed in Q2 for FCFS and SJF scheduling. Upload your solution to GitHub and submit the link to your program.

**Example Output:**

```
----------------- FCFS -----------------

Process ID | Waiting Time | Turnaround Time
------- | -------- | --------
     1           |      0                 |        8    
     2            |      0                |        5    
     3            |      5                |        8    
     4            |      7                |        13
```