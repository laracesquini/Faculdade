#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

int main()
{
     int flagp, flags, i = 0, j = 0;
     char aux[20];
     FILE *fd, *fp, *fs;
     Iprimario vetp[1000];
     Isecundario vets[1000];

     if(file_exists("dados.txt"))
     {
        fd = fopen("dados.txt", "a+");
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
                    char *token = strtok(aux, "@");
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
                    char *token = strtok(aux, "@");
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
        {
          fp = fopen("iprimary.idx", "w");
          fs = fopen("ititle.idx", "w");

          fprintf(fp, "%d\n", 1);
          fprintf(fs, "%d\n", 1);
        }
     }
     else
     {
        fd = fopen("dados.txt", "a+");
     }

     //fechar os arquivos
}