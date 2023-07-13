#include <stdio.h>
#include <stdlib.h>

void procura(int **m, int A, int B, int n);

int main()
{
    int N, M, i, j, **mat, A, B;

    scanf("%d %d", &N, &M);

    mat = malloc(N*sizeof(int*));

    for(i=1; i<=N; i++)
    mat[i] = malloc(N*sizeof(int));

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for(i=0; i<M; i++)
    {
        scanf("%d %d", &A, &B);
        procura(mat, A, B, N);
    }
    
    return 0;
}

void procura(int **m, int A, int B, int n)
{
    int menor = 2*n*n, i, j;

    for(i=A; i<=B; i++)
    {
        for(j=A; j<=B; j++)
        {
            if(m[i][j]<menor)
            menor = m[i][j];
        }
    }

    printf("%d\n", menor);

    return;
}
