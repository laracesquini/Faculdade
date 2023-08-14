#Ax = b
n = 3
tolerance = 0.0000001
teste = 0
A = [ ] #matriz

for i in range(0, n+1):
    A.append([ ])
    for j in range(0, n+1):
        A[i].append(0.0)
b = [ ] #vetor de resultados do sistema
x = [ ] #vetor de incógnitas

for i in range(0, n+1):
    b.append(0.0)
    x.append(0.0)

A[1][1] = 1.0
A[1][2] = 1.0
A[1][3] = 1.0
A[2][1] = -3.5
A[2][2] = 2.0
A[2][3] = 1.0
A[3][1] = 1.5
A[3][2] = 2.0
A[3][3] = -1.0

b[1] = 0
b[2] = 0
b[3] = 1

for i in range(1, n+1):
    for j in range(1, n+1):
        print(A[i][j], end=' ' )
    print()
    
k = 1
while k < n:
    pp = input() #lê o enter
    print(end = ' ')

    max = k
    for i in range(k+1, n+1):
        if abs(A[i][k]) > abs(A[max][k]):
            max = i
    if max > k:
        for j in range(k, n+1):
            temp = A[k][j]
            A[k][j] = A[max][j]
            A[max][j] = temp
        temp = b[k]
        b[k] = b[max]
        b[max] = temp
    
    for i in range(k+1, n+1):
        mult = A[i][k]/A[k][k]
        for j in range(k+1, n+1):
            A[i][j] = A[i][j] - mult * A[k][j]
        b[i] = b[i] - mult*b[k]
        print("Multiplicador:", mult)
        
    for i in range(1, n+1):
        for j in range(1, n+1):
            print(A[i][j], end=' ')
        print()
    k = k+1
    
x[n] = b[n]/A[n][n]
for i in range(n-1, 0, -1):
    sum = 0
    for j in range(i+1, n+1):
        sum = sum +  A[i][j]*x[j]
    x[i] = (b[i] - sum)/A[i][i]

for i in range(1, n+1):
    print("Valor de x: ", x[i])
        
    
        
            