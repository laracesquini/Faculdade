#include <stdio.h>

int main()
{
    int M, N, tabuleiro;

    scanf("%d %d", &M, &N);

    tabuleiro = M*N;

    printf("%d", tabuleiro/2);


    return 0;
}