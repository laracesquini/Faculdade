n = 4

A = [ ] #matriz
for i in range(0, n+1):
    A.append([ ])
    for j in range(0, n+1):
        A[i].append(0.0)

G = [ ]
for i in range(0, n+1):
    G.append([ ])
    for j in range(0, n+1):
        G[i].append(0.0)
        
A[1][1] = 4.0; A[1][2] = 1.0;  A[1][3] = 0.0; A[1][4] = -1.0
A[2][1] = 1.0; A[2][2] = 8.0; A[2][3] = 2.0; A[2][4] = 1.0
A[3][1] = 0.0;  A[3][2] = 2.0; A[3][3] = 4.0; A[3][4] = 1.0
A[4][1] = -1.0; A[4][2] = 1.0; A[4][3] = 1.0; A[4][4] = 6.0

teste = 1
k = 1

val = A[k][k]
if val > 0:
    G[k][k] = val**(1/2)
    if k == n:
        teste = 0
else:
    teste = -k
while teste > 0:
    for i in range(k+1, n+1):
        ss = 0.0
        for j in range(1, k):
            ss = ss + G[k][j]*G[i][j]
        G[i][k] = (A[i][k] - ss)/G[k][k]
    k = k+1
    ss = 0.0
    for j in range(1, k):
        ss = ss + G[k][j]*G[k][j]
    val = A[k][k] - ss
    if val > 0:
        G[k][k] = val**(1/2)
        if k == n:
            teste = 0
    else:
        teste = -k

for i in range(1, n+1):
    for j in range(1, n+1):
        print("{:.5}".format(G[i][j]), end=' ')
    print()