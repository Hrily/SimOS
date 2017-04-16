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
Si
H
```

Hi - 1 if Pi is hit, else 0

H  - Hit Ratio (in %)

### Sample

#### Input

```
2
3
1 2 1 2
```

### Output (Assuming FCFS Replacement)

```
0 0 1 1
50.000000
```