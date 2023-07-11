#include <stdio.h>

int fat(int n);

int main()
{
    int N, fatorial;

    scanf("%d", &N);
    fatorial = fat(N);

    printf("\nO fatorial de %d é %d", N, fatorial);
}

int fat(int n)
{
    if(n==1 || n==0)
    return 1;
    else
    return(n*(fat(n-1)));
}