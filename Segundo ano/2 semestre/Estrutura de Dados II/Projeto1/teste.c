#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

int main()
{
    Iprimario *vetp = NULL, *auxp;
    FILE *fp;
    char aux[20];
    int i = 0, a;
    char t[192] = "LAR75@Dels e o Dialo na larra do Ssl@Idem@Rocha, Glauber@1964@Brasil@8@######################################################################################################################";

    printf("%d", sizeof(t));

    fp = fopen("teste.txt", "r");
    char *token;

    while(!feof(fp))
    {
        fscanf(fp, "%[^#]s", aux);
        fgetc(fp);

        //printf("%s\n", aux);
        token = strtok(aux, "@");
        auxp = malloc(sizeof(Iprimario));
        strcpy(auxp->first_key, token);
        //printf("First key: %s\n", auxp->first_key);
        token = strtok(NULL, "@");
        //printf("TOken: %s\n", token);
        auxp->RNN = atoi(token);
        //printf("RNN: %d\n", auxp->RNN);
        auxp->prox = NULL;
        vetp = insereP(vetp, auxp);
    }

    auxp = vetp;
    while(auxp != NULL)
    {
        //printf("0: %s, %d\n", auxp->first_key, auxp->RNN);
        auxp = auxp->prox;
    }
    
    //printf("1: %s, %d", vetp[1].first_key, vetp[1].RNN);
}