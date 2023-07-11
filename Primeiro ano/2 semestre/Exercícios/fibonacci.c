#include <stdio.h>

int fibonacci(int n);

int main()
{
    int num, i;

    printf("\nDigite a quantidade de termos que a sequencia terá: ");
    scanf("%d", &num);
    for(i=1; i<=num; i++)
    {
        printf("%d ", fibonacci(i));
    }
}
 int fibonacci(int n)
 {
    if(n==1)
    return 1;
    if(n==2)
    return 1;
    else
    return (fibonacci(n-1) + fibonacci (n-2));
}