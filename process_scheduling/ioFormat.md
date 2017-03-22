## Process Scheduling

### Process structure

struct process                       
  {
    int at,bt,pt,rt,ct,inq,p
    }

/* at-: Arrival time
    bt: burst time
     pt: process number
     rt: remaining time
     ct: completion time
     inq: variable to check whether the process is inside the queue in round robin and priority scheduling
     p:priority
*/

### Input format

```
N T
IDi ATi BTi PTi
```

N   - Number of processes
T   - Time Quantum
IDi - Process ID of ith process
ATi - Arrival Time of ith process
BTi - Burst Time of ith process
PTi - Priority of ith process

### Output format

```
IDi CTi TTi WTi
Average TT : ATT
Average WT : AWT
```
IDi - Process ID of ith process
CTi - Completion Time of ith process
TTi - Turn Around Time of ith process
WTi - Waiting of ith process
ATT - Average Turn Around Time
AWT - Average Waiting Time

### Sample

#### Input

```
2 1
1 1 2 1
2 2 1 1
```

#### Output (Assuming FCFS)

```
1 3 2 0
2 4 2 1
Average TT : 2.000000
Average WT : 0.500000
```