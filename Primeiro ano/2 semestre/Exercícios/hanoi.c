#include <stdio.h>
#include <stdlib.h>

 int count = 0, K;
 int quant[3] = {0};

 void alt(int orig, int dest, int **m)
 {
    int i=0;

    while(m[orig][i]!=1)
    {
        i++;
    }
    m[orig][i] = 0;
    m[dest][i] = 1;
 }

 void hanoi(int orig, int dest, int aux, int quantidade, int max, int **m)
 {
    if(count<max)
    {
        if(quantidade == 1)
        {
            quant[orig]--;
            quant[dest]++;
            count+=1;
            alt(orig, dest, m);
        }
        else
        {
            hanoi(orig, aux, dest, quantidade-1, max, m);
            hanoi(orig, dest, aux, 1, max, m);
            hanoi(aux, dest, orig, quantidade-1, max, m);
        }
    }
 }

 int main()
 {
    int N, i, j;
    int **pinos;
    int busca1;

    scanf("%d", &N);
    scanf("%d", &K);

    pinos = malloc(3*sizeof(int));

    for(i=0; i<3; i++)
    {
        pinos[i] = malloc(N*sizeof(int));
    }

    for(i=0; i<N; i++)
    {
        pinos[0][i] = 1;
        pinos[1][i] = pinos[2][i] = 0;
    }

    hanoi(0, 2, 1, N, K, pinos);

    for(i=0; i<3; i++)
    {
        busca1 = 0;
        for(j=0; j<N; j++)
        {
            if(pinos[i][j]==1)
            {
                printf("%d ", j+1);
                busca1 = 1;
            }
        }
        if(busca1 == 0)
        {
            printf("%d", busca1);
        }
        printf("\n");
    }

    return 0;
    
 }
