#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

#define ordem 6

int main()
{
    char vetor[5][6];

    strcpy(vetor[0], "ola");
    strcpy(vetor[1], "sla");

    int tam = sizeof(vetor)/sizeof(vetor[0]);

    printf("%d", tam);
}