#GRUPO:
#Lara Cesquini Stopa
#Ana Beatriz Gomes Takehara
#Heloisa Silveira Bula

#tamanho da matriz
n = 3

#declaração das matrizes e variáveis usadas 
sinalDet = 1
det = 1
A = [ ]
b = [ ]
x = [ ]

#inicialização das matrizes
for i in range (0, n+1): 
    A.append([ ]) 
    for j in range(0, n+1):
        A[i].append(0.0) 


for i in range (0, n+1):
    b.append(0.0)
    x.append(0.0)

#interação com o usuário
while True:
    #usuário tem opção de inserir a matriz ou pegar uma pronta
    op = int(input("\nEscolha uma opção: \n1 - Entrar com os valores das matrizes 3X3\n2 - Utilizar uma matriz 3x3 já pronta\n3 - Sair\n"))

    if op == 1 or op == 2:
        #caso o usuário escolha inserir a matriz, lê os dados inseridos
        if op == 1:
            for i in range(1, n + 1):
                linha = []
                for j in range (1, n + 1):
                    elemento = float(input(f"Digite o valor para a posição A[{i}][{j}]: "))
                    A[i][j] = elemento
            
            print("\n")
            
            for i in range(1, n+1):
                elemento = float(input(f"Digite o valor para a posição b[{i}]: "))
                b[i] = elemento
            
            print("\n")
            
        #caso o usuário escolha usar uma matriz pronta, pega o exemplo definido abaixo
        if op == 2:
            A[1][1] = 1.0  
            A[1][2] = 1.0  
            A[1][3] = 1.0 
            A[2][1] = -3.5
            A[2][2] = 2.0 
            A[2][3] = 1.0 
            A[3][1] = 1.5  
            A[3][2] = 2.0 
            A[3][3] = -1.0 
            b[1] = 0.0 
            b[2] = 0.0 
            b[3] = 1.0 

        #imprimindo a matriz A
        print("\nMatriz A: \n")
        for i in range(1, n+1):
            for j  in range(1, n+1):
                print("{:.3}    " .format(A[i][j]), end= ' ')
            print()

        #imprimindo a matriz B
        print("\nMatriz b: \n")
        for i in range (1, n+1):
            print("{:.3}" .format(b[i]))
        
        #percorrendo a matriz
        k = 1
        while k < n:
            pp = input()

            #pivoteamento parcial
            max = k
            for i in range(k+1, n+1):
                if abs(A[i][k]) > abs(A[max][k]):
                    max = i
            if max > k:
                #se encontrar um valor maior, em módulo, naquela coluna, trocar as linhas de forma que esse valor seja o pivô
                for j in range (k, n+1):
                    temp = A[k][j]
                    A[k][j] = A[max][j]
                    A[max][j] = temp 
                temp = b[k]; b[k] = b[max]; b[max]= temp
                sinalDet = - sinalDet
            
            #Eliminação de Gauss
            for i in range(k+1, n+1):
                print("\nELIMINAÇÃO DA LINHA {} USANDO A LINHA {}\n".format(i, k))
                #define o multiplicador
                mult = A[i][k]/A[k][k]
                #faz a modificação na matriz
                for j in range(k+1, n+1):
                    A[i][j] = A[i][j] - mult * A[k][j]
                b[i] = b[i] - mult * b[k]
                print("Multiplicador: {:.3}" .format(mult))
                #imprime a matriz
                for i in range(1, n+1):
                    for j  in range(1, n+1):
                        print("{:.3}    " .format(A[i][j]), end= ' ')
                    print()   
            k = k+1
            
        #cálculo do sistema usando a matriz A escalonada e a matriz B permutada
        x[n] = b[n]/A[n][n]
        for i in range(n-1, 0, -1):
            sum = 0 
            for j in range (i+1, n+1):
                sum = sum + A[i][j]*x[j]
            x[i] = (b[i] - sum)/A[i][i]   

        #printando o resultado 
        print("\n")
        for i in range(1, n+1):
            print("Valor de x: ", x[i])
            
        print("\n")
        
        #cálculo do determinante
        for i in range(1, n+1):
            for j in range(1, n+1):
                if j == i:
                    det = det*A[i][j]

        print("Determinante da matriz A: {:.3}\n" .format(det))


    if op != 1 and op != 2 and op != 3:
        print("Opção inválida\n")

    if op == 3:
        break

