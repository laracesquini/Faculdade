#include <stdio.h>
#include <stdlib.h>

void crescente(double *vet, int k);
void decrescente(double *vet, int k, int N);

int main()
{
    int N, K, i;
    double *v;

    scanf("%d %d", &N, &K);

    v = malloc(N*sizeof(double));

    for(i=0; i<N; i++)
    {
        scanf("%lf", &v[i]);
    }

    crescente(v, K);
    decrescente(v, K, N);

    for(i=0; i<N; i++)
    {
        printf("%.3lf ", v[i]);
    }

    return 0;
}

void crescente(double *vet, int k)
{
    int i, j; 
    double aux;

    for(i=1; i<=k; i++)
    {
        aux = vet[i];
        j = i;
        while(j>0 && vet[j-1]>aux)
        {
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = aux;
    }

    return;
}

void decrescente(double *vet, int k, int N)
{
    int i, j;
    double aux;

    for(i=k+1; i<N; i++)
    {
        aux = vet[i];
        j = i;
        while(j>k && vet[j-1] < aux)
        {
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = aux;
    }
    return;
}