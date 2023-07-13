#include <stdio.h>
#include <stdlib.h>

int verifica(int N, int lin, int col, int **matriz);
void solucao(int lin, int col, int passos, int N, int C, int **matriz);

int primeira = 0;

int main()
{
    int N, I, C, i, j, passos = 0, **matriz;

    scanf("%d", &N);
    scanf("%d", &I);
    scanf("%d", &C);

    matriz = malloc(N*sizeof(int*));

    for(i=0; i<N; i++)
    {
        matriz[i] = malloc(N*sizeof(int));
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    solucao(0, I, passos, N, C, matriz);
    printf("-1\n");
    return 0;
}

int verifica(int N, int lin, int col, int **matriz)
{
    if(lin >= 0 && col >= 0 && lin < N && col < N && matriz[lin][col] == 0)
    return 1;
    else
    return 0;
}

void solucao(int lin, int col, int passos, int N, int C, int **matriz)
{
    if(lin == N-1 && col == C && matriz[lin][col] == 0)
    {
        printf("%d\n", passos);
        exit(0);
    }
    if(!verifica(N, lin, col, matriz))
    {
        return;
    }
    matriz[lin][col] = 1;
    solucao(lin+1, col, passos+1, N, C, matriz);
    solucao(lin, col+1, passos+1, N, C, matriz);
    solucao(lin, col-1, passos+1, N, C, matriz);

    return;

}