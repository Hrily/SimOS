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
`Order in which requests are served`
`Seek Time: ST`
```
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

`Seek Time: 8`
