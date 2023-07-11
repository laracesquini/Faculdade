#include <stdio.h>

int fibo(int n);

int main()
{
    int num, valor;

    printf("Digite o termo que gostaria saber: ");
    scanf("%d", &num);

    valor = fibo(num);

    printf("%d", valor);
}

int fibo(int n)
{
    int a;

    if(n==1)
    return 1;
    if(n==2)
    return 1;
    else
    return (fibo(n-2)+fibo(n-1));

    
}