## Page Replacement Algorithms

### Input format

```
S
N
Pi
```

S  - Size of Main Memory (in frames)
N  - Number of Pages
Pi - ith Page number

### Output format
```
H
```

H - Hit Ratio (in %)

A[1..N] - Order in which request are served

ST - Total Seek Time

### Sample

#### Input

```
2
3
1 2 1 2
```

### Output (Assuming FCFS Replacement)

```
50.000000
'''