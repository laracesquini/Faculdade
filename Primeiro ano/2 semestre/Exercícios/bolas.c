#include <stdio.h>
#include <math.h>

int bolas(int n);

int main()
{
    int N, valor;

    scanf("%d", &N);
    valor = bolas(N);

    printf("\nA pirâmide tem %d bolas", valor);

    return 0;
}

int bolas(int n)
{
    if(n==1)
    return 1;
    else
    return(pow(n,2)+bolas(n-1));

}