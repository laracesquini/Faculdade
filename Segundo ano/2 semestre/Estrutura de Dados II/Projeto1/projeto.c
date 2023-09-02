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

     if(file_exists("movies.dat"))
     {
        fd = fopen("movies.dat", "a+");
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
          fp = fopen("iprimary.idx", "a+");
          fs = fopen("ititle.idx", "a+");
          fd = fopen("movies.dat", "a+");
          int count = 0;

          //tentar colocar isso em uma função -> possivelmente vai ser ponteiro duplo para alterar vetp e vets em uma única função
          cria_indices(fd, &vetp, &vets);
          fprintf(fp, "%d\n", 1);
          fprintf(fs, "%d\n", 1);
          //salvar no arquivo
        }
     }
     else
     {
        fd = fopen("movies.dat", "a+");
     }

     //fechar os arquivos
}