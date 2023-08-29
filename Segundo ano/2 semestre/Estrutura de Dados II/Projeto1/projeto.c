#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//0 - desatualizado
//1 - atualizado

int main()
{
     int flagp, flags, i = 0, j = 0;
     char aux[192], *token;
     FILE *fd, *fp, *fs;
     Iprimario vetp[1000];
     Isecundario vets[1000];

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
               while(!feof(fp))
               {
                    fscanf(fp, " %[^#]s", aux);
                    fgetc(fp);
                    token = strtok(aux, "@");
                    strcpy(vetp[i].first_key, token);
                    token = strtok(NULL, "@");
                    vetp[i].RNN = atoi(token);
                    i++;
               }
          }
          else
          {

          }

          if(flags == 1)
          {
               while(!feof(fs))
               {
                    fscanf(fs, " %[^#]s", aux);
                    fgetc(fs);
                    token = strtok(aux, "@");
                    strcpy(vets[j].titulo, token);
                    token = strtok(NULL, "@");
                    strcpy(vets[j].first_key, token);
                    j++;
               }
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

          while(!feof(fd))
          {
               fread(aux, 192, 1, fd);
               token = strtok(aux, "@");
               strcpy(vetp[i].first_key, token);
               strcpy(vets[j].first_key, token);
               token = strtok(NULL, "@");
               strcpy(vets[j].titulo, token);
               vetp[i].RNN = i;
               i++;
               j++;
          }
          //ordenar pela chave
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