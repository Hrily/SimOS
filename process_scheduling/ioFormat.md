## Process Scheduling

### Process structure

```
	struct process {
		int at,     // Arrival time
		    bt,     // Burst time
		    pt,     // Process Number
		    rt,     // Remaining Time
		    ct,     // Completion time
		    inq,    // Check whether process is in queue
		    p,      // Priority
		    tat,    //turnaround time
		    wt;     // waiting time
    }
 ```


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
Average TT: 2.000000
Average WT: 0.500000
```
