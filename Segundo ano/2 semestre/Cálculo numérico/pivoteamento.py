#Sistema -> Ax = b
n = 3
stt = 0
#declaração da matriz
A = [ ] #matriz
for i in range(0, n+1):
    A.append([ ])
    for j in range(0, n+1):
        A[i].append(0.0)

#declaração dos vetores usados
b = [ ] #vetor de resultados do sistema
x = [ ] #vetor de incógnitas
for i in range(0, n+1):
    b.append(0.0)
    x.append(0.0)

#inicialização
A[1][1] = 2.0; A[1][2] = 1.0;  A[1][3] = -1.0
A[2][1] = 1.0; A[2][2] = -0.5; A[2][3] = 2.0
A[3][1] = -1;  A[3][2] = -4.5; A[3][3] = 1.0

b[1] = 7.0; b[2] = 4.0; b[3] = -11.0

#printando a matriz antes do processo
print("Matriz:")
for i in range(1, n+1):
    for j in range(1, n+1):
        print(A[i][j], end=' ' )
    print()
print("\n")
    
k = 1
while k < n: #percorre toda a matriz
    pp = input() #lê o enter
    print(end = ' ')

    #ver o maior elemento, em módulo, da coluna e colocá-lo na primeira posição. Evita divisão por 0
    max = k #define o primeiro como maior
    for i in range(k+1, n+1):
        if abs(A[i][k]) > abs(A[max][k]): #se achar um maior, atualiza ele
            max = i
    if max > k: #ou seja, achou um novo maior, é preciso trocar as linhas
        for j in range(k, n+1):
            temp = A[k][j]
            A[k][j] = A[max][j]
            A[max][j] = temp
            stt = 1
        temp = b[k]
        b[k] = b[max]
        b[max] = temp
    
    #matriz depois da mudança de linha
    if stt == 1:
        print("Mudança de linha:")
        for i in range(1, n+1):
            for j in range(1, n+1):
                print(A[i][j], end=' ')
            print()
    
    #calcular o multiplicador e simplificar o sistema
    for i in range(k+1, n+1):
        mult = A[i][k]/A[k][k]
        for j in range(k+1, n+1):
            A[i][j] = A[i][j] - mult * A[k][j] #atualiza as linhas com os novos valores
        b[i] = b[i] - mult*b[k]
        print("Multiplicador:", mult)
    
    #matriz atualizada 
    print("\nMatriz atualizada:")   
    for i in range(1, n+1):
        for j in range(1, n+1):
            print(A[i][j], end=' ')
        print()
    k = k+1
    stt = 0

print("\n")
#resolução do sistema   
x[n] = b[n]/A[n][n]
for i in range(n-1, 0, -1):
    sum = 0
    for j in range(i+1, n+1): #realiza a multiplicação entra a matriz com os valores e a matriz com as incógnitas
        sum = sum +  A[i][j]*x[j]
    x[i] = (b[i] - sum)/A[i][i]

for i in range(1, n+1):
    print("Valor de x{}: {}" .format(i, x[i]))
        
    
        
            