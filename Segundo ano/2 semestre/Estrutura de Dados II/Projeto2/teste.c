#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

#define ordem 6

int main()
{
    
    node *teste, *raiz;
    FILE *fp;
    int RRN = 2, lido;

    
    //raiz = le_no(0, fp);
    //escreve_no(0, raiz, fp);
    //teste = le_no(2, fp);
    
    teste = le_no(0, fp);
    
    //fp = fopen("ibtree.idx", "w");
    printf("RRN: %d, Num chaves: %d, Prox: %d, Pai: %d, Folha: %d\n", teste->RRN, teste->numeroChaves, teste->prox, teste->pai, teste->folha);
    printf("Chaves: ");
    for(int i = 0; i < teste->numeroChaves; i++)
    {
        printf("%s ", teste->chaves[i]);
    }
    printf("\nFilhos: ");
    for(int i = 0; i < teste->numeroChaves; i++)
    {
        printf("%d ", teste->filhos[i]);
    }

   
    /*teste->folha = 1;
    inserir("ABV12", 0, &teste, fp);
    inserir("OLU23", 1, &teste, fp);
    inserir("RLU23", 2, &teste, fp);
    inserir("SLU23", 3, &teste, fp);
    inserir("BLU23", 4, &teste, fp);
    inserir("FLU23", 5, &teste, fp);
    inserir("CBV12", 6, &teste, fp);
    inserir("DBV12", 7, &teste, fp);
    inserir("ELU23", 8, &teste, fp);
    inserir("GLU23", 9, &teste, fp);
    inserir("HLU23", 8, &teste, fp);
    inserir("ILU23", 5, &teste, fp);

    inserir("TLU23", 9, &teste, fp);
    inserir("ULU23", 8, &teste, fp);
    inserir("VLU23", 5, &teste, fp);

    inserir("WLU23", 9, &teste, fp);
    inserir("XLU23", 8, &teste, fp);
    inserir("YLU23", 5, &teste, fp);

    inserir("WVU23", 9, &teste, fp);
    inserir("XXU23", 8, &teste, fp);
    inserir("YFU23", 5, &teste, fp);*/
}

