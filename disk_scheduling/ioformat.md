## Disk Scheduling

### Input format

```
N
H P
C
Ni
```

N  - Number of requests
H  - Current Location of Head
P  - Previous request
C  - Total number of cylinders
Ni - N requests

### Output format
```
A[1..N]
Seek Time: ST
```

A[1..N] - Order in which request are served

ST - Total Seek Time

### Sample

#### Input

```
2
10 5
20
15 12
```

### Output (Assuming FCFS Scheduling)

```
10 15 12
Seek Time:8
