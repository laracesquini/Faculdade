n = 4
#declaração da matriz
A = [ ] #matriz
for i in range(0, n+1):
    A.append([ ])
    for j in range(0, n+1):
        A[i].append(0.0)

U =[ ]
for i in range(0, n+1):
    U.append([ ])
    for j in range(0, n+1):
        U[i].append(0.0)
        
L = [ ]
for i in range(0, n+1):
    L.append([ ])
    for j in range(0, n+1):
        L[i].append(0.0)

#inicialização
A[1][1] = 1.0; A[1][2] = -1.5;  A[1][3] = 1.5; A[1][4] = 0.5
A[2][1] = -1.0; A[2][2] = -4.5; A[2][3] = 1.0; A[2][4] = 2.0
A[3][1] = 2.0;  A[3][2] = 1.0; A[3][3] = 0.0; A[3][4] = -3.0
A[4][1] = -2.0; A[4][2] = 1.0; A[4][3] = 1.5; A[4][4] = 2.0

for j in range(1, n+1):
    U[1][j] = A[1][j]
for i in range(2, n+1):
    L[i][1] = A[i][1]/U[1][1]

for k in range(2, n):
    for j in range(k, n+1):
        sj = 0.0
        for ir in range(1, k):
            sj = sj + L[k][ir]*U[ir][j]
        U[k][j] = A[k][j] - sj
    for i in range(k+1, n+1):
        si = 0.0
        for ir in range(1, k):
            si = si + L[i][ir]*U[ir][k]
        L[i][k] = (A[i][k] - si)/U[k][k]
sj = 0.0
for ir in range(1, n):
    sj = sj + L[n][ir]*U[ir][n]
U[n][n] = A[n][n] - sj

print("Matriz L: ")
for i in range(1, n+1):
    for j in range(1, n+1):
        print("{:.3}".format(L[i][j]), end=' ')
    print()

print("\nMatriz U: ")     
for i in range(1, n+1):
    for j in range(1, n+1):
        print("{:.3}".format(U[i][j]), end=' ')
    print()