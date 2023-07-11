#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shellshort(char vet[][100], int N);

int main()
{
    int n, i;
    
    scanf("%d", &n);
    char v[n][100];
    
    for(i=0; i<n; i++)
    {
        scanf(" %s", v[i]);
    }
    
    shellshort(v, n);

    return 0;
}

void shellshort(char vet[][100], int N)
{
    int i, j, k, L;
    char palavra[100];

    k = 1;
    while(k <= N/4)
    k = k*2;

    while(k != 1)
    {
        k = k/2;
        for(L=0; L<k; L++)
        {
            for(i=L+k; i<N; i = i+k)
            {
            strcpy(palavra, vet[i]);
            j = i;
            while(j-k >= 0 && strcmp(vet[j-k], palavra) > 0)
            {
                strcpy(vet[j], vet[j-k]);
                j = j-k;
            }
            strcpy(vet[j], palavra);
            }
        }
        for(i=0; i<N; i++)
        {
            printf("%s ", vet[i]);
        }
        printf("\n");
    }
    return;
}

