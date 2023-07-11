#include <stdio.h>
#include <math.h>

float expoente(float b, float e);
float negativo(float b, float e);

int main()
{
    float base, expo, result, n;

    printf("\nDigite um número para a base: ");
    scanf("%f", &base);
    printf("\nDigite um número para o expoente: ");
    scanf("%f", &expo);

    if(expo<0)
    {
        n = fabs(expo);
        result = negativo(base, n);
        printf("\nO resultado é: %.4f", result);
    }
    else if(expo>0)
    {
        result = expoente(base, expo);
        printf("\nO resultado é: %.0f", result);
    }
    
}

float expoente(float b, float e)
{
    if(e==0) //ou quando e==1, retorna b;
    return 1;
    else
    return (b*(expoente(b, e-1)));
}

float negativo(float b, float e)
{
    if(e==0)
    return 1;
    else
    return ((1/b)*(expoente((1/b), e-1)));
    
}
