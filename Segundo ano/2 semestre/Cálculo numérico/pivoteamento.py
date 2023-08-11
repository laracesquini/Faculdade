n = 3
A = [ ]

for i in range(0, n+1):
    A.append([ ])
    for j in range(0, n+1):
        A[i].append(0.0)
b = [ ]
x = [ ]

for i in range(0, n+1):
    b.append(0.0)
    x.append(0.0)

A[0][0] = 1
A[0][1] = 1
A[0][2] = 1
A[1][0] = -3.5
A[1][1] = 2
A[1][2] = 1
A[2][0] = 1.5
A[2][1] = 2
A[2][2] = -1

for i in range(0, n+1):
    for j in range(0, n+1):
        print(A[i][j])