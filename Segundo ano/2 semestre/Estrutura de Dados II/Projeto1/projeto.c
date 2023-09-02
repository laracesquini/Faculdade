#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//0 - desatualizado
//1 - atualizado

int main()
{
     
     int flagp, flags;
     char aux[193];
     FILE *fd, *fp, *fs;
     Iprimario *vetp = NULL, *auxp;
     Isecundario *vets = NULL, *auxs;

     if(file_exists("movies.txt"))
     {
        fd = fopen("movies.txt", "a+");
        if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
        {
          fp = fopen("iprimary.idx", "a+");
          fs = fopen("ititle.idx", "a+");

          fscanf(fp, "%d", &flagp);
          fscanf(fs, "%d", &flags);
          if(flagp == 1)
          {
               vetp = carrega_indicesP(fp, vetp);
          }
          else
          {

          }

          if(flags == 1)
          {
               vets = carrega_indicesS(fs, vets);
          }
          else
          {

          }
        }
        else
        { //criar os indices nos vetores e salvar no arquivo -> ainda vou ter os indices em RAM, e em qualquer alteração, muda a flag para 0.
          fp = fopen("iprimary.idx", "w");
          fs = fopen("ititle.idx", "w");
          fd = fopen("movies.txt", "r");
          int count = 0;
          char *token;

          while(fread(aux, 192, 1, fd) == 1)
          {
               token = strtok(aux, "@");
               auxp = malloc(sizeof(Iprimario));
               auxs = malloc(sizeof(Isecundario));
               strcpy(auxp->first_key, token);
               strcpy(auxs->first_key, token);
               token = strtok(NULL, "@");
               strcpy(auxs->titulo, token);
               auxp->RNN = count;
               auxp->prox = NULL;
               auxs->prox = NULL;
               count++;

               vetp = insereP(vetp, auxp);
               vets = insereS(vets, auxs);
          }
          

          fprintf(fp, "%d\n", 1);
          fprintf(fs, "%d\n", 1);
          
          auxp = vetp;
          while(auxp != NULL)
          {
               fprintf(fp, "%s@%d@#", auxp->first_key, auxp->RNN);
               auxp = auxp->prox;
          }
          
          auxs = vets;
          while(auxs != NULL)
          {
               fprintf(fs, "%s@%s@#", auxs->titulo, auxs->first_key);
               auxs = auxs->prox;
          }
          
          fclose(fp);
          fclose(fs);
        }
     }
     else
     {
        fd = fopen("movies.txt", "a+");
     }

     //fechar os arquivos
}