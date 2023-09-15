#GRUPO:
#Lara Cesquini Stopa
#Ana Beatriz Gomes Takehara
#Heloisa Silveira Bula

#tamanho da matriz
n = 3

#declaração e inicialização das matrizes utilizadas
A = [ ]  
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

#interação com o usuário
while True:
    #usuário tem opção de inserir a matriz ou pegar uma pronta
    op = int(input("\nEscolha uma opção: \n1 - Entar com os valores das matrizes 3x3\n2 - Utilizar uma matriz 3x3 já pronta\n3 - Sair\n"))
    
    if op == 1 or op == 2:
        #caso o usuário escolha inserir a matriz, lê os dados inseridos
        if op == 1:
            for i in range(1, n+1):
                linha = []
                for j in range(1, n+1):
                    elemento = float(input(f"Digite o valor para a posição A[{i}][{j}]: "))
                    A[i][j] = elemento
            print("\n")
        
        #caso o usuário escolha usar uma matriz pronta, pega o exemplo definido abaixo
        if op == 2:
            A[1][1] = 3.0
            A[1][2] = 2.0
            A[1][3] = 4.0
            A[2][1] = 1.0
            A[2][2] = 1.0
            A[2][3] = 2.0
            A[3][1] = 4.0
            A[3][2] = 3.0
            A[3][3] = -2.0
        
        #imprimindo matriz
        print("\nMatriz A: \n")
        for i in range(1, n+1):
            for j  in range(1, n+1):
                print("{:.3}    " .format(A[i][j]), end= ' ')
            print()
        #definindo L inicialmente como uma matriz indentidade nxn
        for i in range (1, n+1):
            L[i][i] = 1.0

        #percorrendo a matriz
        k = 1
        while k < n:
            for i in range(k+1, n+1):
                #definindo o multipicador e guardando seus valores na matriz L
                mult = A[i][k]/A[k][k]
                L[i][k] = mult
                for j in range(k+1, n+1):
                    #escalonamento da matriz A pelo método de Gauss
                    A[i][j] = A[i][j] - mult * A[k][j]
            
            k = k+1
        
        #salvando em U o resultado da matriz A
        for i in range(1, n+1):
            for j in range(i, n+1):
                U[i][j] = A[i][j]
                
        #printando os resultados
        print("\nMatriz L: \n")
        for i in range(1, n+1):
            for j in range(1, n+1):
                print("{:.3}    ".format(L[i][j]), end=' ')
            print()

        print("\nMatriz U: \n")     
        for i in range(1, n+1):
            for j in range(1, n+1):
                print("{:.3}    ".format(U[i][j]), end=' ')
            print()
    if op != 1 and op != 2 and op != 3:
        print("Opção inválida\n")
    if op == 3:
        break