## Multitasking Memory Management

### Input

```
N S
F
Ci
```

N  - Number of partitions (0 for MVT)

S  - Total size of Memory

F  - Fitting Strategy, 1 for First Fit, 2 for Best Fit and 3 for Worst Fit

Ci - ith Command, continously take commands

Command can be 0, 1, 2, or 3

#### Command `1`

Add Program to Memory

##### Input

```
Ps
```

Ps - Program size

##### Output

```
R
```

R - Result: 1 if succesfull allocation, 0 otherwise

#### Command `2`

Delete Program from Memory

##### Input

```
I
```

I - Index of program to delete

Delete the Ith allocated program in Memory

#### Command `3`

Diplay Memory

##### Input

**NO INPUT**

##### Output

```
Bi Si A
```

Bi - Beginning of ith partition

Si - Size of the ith partition

Ai - Status: 1 if allocated, 0 otherwise

#### Command `0`

Exit/Stop the program

**NO INPUT AND OUTPUT**

##### Note

Don't print intermediate texts ('Enter size', 'Choose', etc), just the ones mentioned above
