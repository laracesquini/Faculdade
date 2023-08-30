#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//0 - desatualizado
//1 - atualizado

int main()
{
     //fazer tudo isso em funções 
     
     int flagp, flags;
     char aux[192], *token;
     FILE *fd, *fp, *fs;
     Iprimario *vetp = NULL, *auxp;
     Isecundario *vets = NULL, *auxs;

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
                    auxp = malloc(sizeof(Iprimario));
                    strcpy(auxp->first_key, token);
                    token = strtok(NULL, "@");
                    auxp->RNN = atoi(token);
                    auxp->prox = NULL;
                    vetp = insereP(vetp, auxp);
                    //inserir vetp = inserir(, vetp, aux)
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
                    auxs = malloc(sizeof(Isecundario));
                    strcpy(auxs->titulo, token);
                    token = strtok(NULL, "@");
                    strcpy(auxs->first_key, token);
                    auxs->prox = NULL;
                    vets = insereS(vets, auxs);
                    //vets = inserir(vets, aux)
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
          int count = 0;

          while(!feof(fd))
          {
               fread(aux, 192, 1, fd);
               token = strtok(aux, "@");
               //mallos e inserir ordenado
               auxp = malloc(sizeof(Iprimario));
               auxs = malloc(sizeof(Isecundario));
               strcpy(auxp->first_key, token);
               strcpy(auxs->first_key, token);
               token = strtok(NULL, "@");
               strcpy(auxs->titulo, token);
               auxp->RNN = count;
               count++;
               
               vetp = insereP(vetp, auxp);
               vets = insereS(vets, auxs);
               //inserir auxp e auxs
          }
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