#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

#define ordem 6

int main()
{
    
    node *teste;
    FILE *fp = fopen("ibtree.idx", "w");

    teste = cria_no();
    escreve_no(0, teste, fp);

    insere_folha(teste, "ALU12", 1);
    escreve_no(1, teste, fp);

    insere_folha(teste, "BLU12", 1);
    escreve_no(2, teste, fp);

    insere_folha(teste, "ELU12", 1);
    escreve_no(3, teste, fp);

    insere_folha(teste, "DLU12", 1);
    escreve_no(4, teste, fp);
}

