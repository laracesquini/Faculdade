#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

int main()
{
    node *teste = cria_no(), *aux;
    FILE *fp;
    
    /*fp = fopen("ibtree.idx", "w");
    fputc('0', fp);
    fclose(fp);
    escreve_no(0, teste, fp);
    escreve_no(1, teste, fp);*/

    //att_raiz(10, fp, 1);



    aux = le_no(0, fp);
    printf("RRN: %d, Num chaves: %d, Prox: %d, Pai: %d, Folha: %d\n", aux->RRN, aux->numeroChaves, aux->prox, aux->pai, aux->folha);
        printf("Chaves: ");
        for(int i = 0; i < ordem - 1; i++)
        {
            printf("%s ", aux->chaves[i]);
        }
        printf("\nFilhos: ");
        for(int i = 0; i < ordem; i++)
        {
            printf("%d ", aux->filhos[i]);
        }
        printf("\n\n");

}