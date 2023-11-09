#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

#define ordem 6

int main()
{
    
    node *teste;
    FILE *fp;

    teste = le_no(0, fp);
    printf("RRN do nó: %d\n", teste->RRN);
    printf("É folha: %d\n", teste->folha);
    printf("Número de chaves do nó: %d\n", teste->numeroChaves);
    printf("Pai do nó: %d\n", teste->pai);
    printf("Prox nó: %d\n", teste->prox);
    printf("Chaves:");
    for(int i = 0; i< teste->numeroChaves; i++)
    {
        printf("%s,", teste->chaves[i]);
    }
    printf("\nRNN dos dados:");
    for(int i = 0; i< teste->numeroChaves; i++)
    {
        printf("%d,", teste->dadosRRN[i]);
    }
    printf("\nFilhos:");
    for(int i = 0; i< teste->numeroChaves; i++)
    {
        printf("%d,", teste->filhos[i]);
    }

    
}
