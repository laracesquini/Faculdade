#include <stdio.h>

void binario(int n);

int main()
{
    int N;

    printf("\nDigite um número decimal: ");
    scanf("%d", &N);
    binario(N);

    return 0;
}

void binario(int n)
{
    if((n/2)==0)
    printf("%d", (n%2));
    else
    {
        binario(n/2);
        printf("%d", (n%2));
    }
}