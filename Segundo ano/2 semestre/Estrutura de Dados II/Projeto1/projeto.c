#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//0 - desatualizado
//1 - atualizado

int main()
{
     
     int flagp, flags;
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
          fp = fopen("iprimary.txt", "a+");
          fs = fopen("ititle.txt", "a+");
          fd = fopen("movies.txt", "r");

          cria_indices(fd, &vetp, &vets);
          fprintf(fp, "%d\n", 1);
          fprintf(fs, "%d\n", 1);
          //salvar no arquivo
          auxp = vetp;
          /*while(auxp != NULL)
          {
               fprintf(fp, "%s@%s@#", auxp->first_key, auxp->RNN);
               auxp = auxp->prox;
          }

          auxs = vets;
          while(auxs != NULL)
          {
               fprintf(fs, "%s@%s@#", auxs->titulo, auxs->first_key);
               auxs = auxs->prox;
          }*/

          printf("Vetp: %s %d", vetp->first_key, vetp->RNN);

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