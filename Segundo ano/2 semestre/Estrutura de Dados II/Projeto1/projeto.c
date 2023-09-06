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
     Iprimario *vetp = NULL;
     Isecundario *vets = NULL;

     if(file_exists("movies.txt"))
     {
        fd = fopen("movies.txt", "r");
        if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
        {
          fp = fopen("iprimary.idx", "r");
          fs = fopen("ititle.idx", "r");

          fscanf(fp, "%d", &flagp);
          fscanf(fs, "%d", &flags);

          if(flagp == 1)
          {
               vetp = carrega_indicesP(fp, vetp);
          }
          else
          {
               fclose(fp);
               
               cria_indices(fd, fp, fs, vetp, vets, flagp, flags);
          }

          if(flags == 1)
          {
               vets = carrega_indicesS(fs, vets);
          }
          else
          {
               fclose(fs);

               cria_indices(fd, fp, fs, vetp, vets, flagp, flags);
          }
        }
        else
        { //criar os indices nos vetores e salvar no arquivo -> ainda vou ter os indices em RAM, e em qualquer alteração, muda a flag para 0.
          cria_indices(fd, fp, fs, vetp, vets, 0, 0);
        }
     }
     else
     {
        fd = fopen("movies.txt", "a+");
     }

     //fechar os arquivos
}