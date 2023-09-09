#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//0 - desatualizado
//1 - atualizado

int main()
{
     int flagp, flags, op;
     FILE *fd, *fp, *fs;
     Iprimario *vetp = NULL, *auxp;
     Isecundario *vets = NULL, *auxs;
     Tdados aux;
     char *dados;
     
     if(file_exists("movies.txt"))
     {
        fd = fopen("movies.txt", "a+");
        if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
        {
          fp = fopen("iprimary.idx", "r");
          fs = fopen("ititle.idx", "r");

          fscanf(fp, "%d", &flagp);
          fscanf(fs, "%d", &flags);

          if(flagp == 1)
          vetp = carrega_indicesP(fp, vetp);
          else
          {
               fclose(fp);
               
               cria_indices(fd, fp, fs, vetp, vets, flagp, flags);
               
               vetp = carrega_indicesP(fp, vetp);
               flagp = 1;
          }

          if(flags == 1)
          vets = carrega_indicesS(fs, vets);
          else
          {
               fclose(fs);
               
               cria_indices(fd, fp, fs, vetp, vets, flagp, flags);

               vets = carrega_indicesS(fs, vets);
               flags = 1;
          }
        }
        else
        {
          cria_indices(fd, fp, fs, vetp, vets, 0, 0);
     
          vetp = carrega_indicesP(fp, vetp);
          vets = carrega_indicesS(fs, vets);

          flagp = 1;
          flags = 1;
        }
        
     }
     else
     fd = fopen("movies.txt", "a+");
     
     do{
          do{
               printf("Bem-vindo!!\n");
               printf("Escolha uma opção: \n");
               printf("[1]Inserir um novo filme no catálogo\n");
               printf("[2]Remover um filme\n");
               printf("[3]Modificar um campo\n");
               printf("[4]Buscar filmes\n");
               printf("[5]Ver catálogo\n");
               printf("[6]Sair\n");
               scanf("%d", &op);
               if(op < 1 || op > 6)
               printf("Opção inválida\n");
          }while(op < 1 || op > 6);

          if(op == 1)
          {
               printf("Adicione as informações necessárias: \n");
               printf("Título em português: ");
               scanf(" %[^\n]s", aux.titulo_portugues);
               printf("Título original: ");
               scanf(" %[^\n]s", aux.titulo_original);
               printf("Diretor(Sobrenome, Nome): ");
               scanf(" %[^\n]s", aux.diretor);
               printf("Ano de lançamento: ");
               scanf(" %s", aux.ano);
               printf("País: ");
               scanf(" %[^\n]s", aux.pais);
               printf("Nota: ");
               scanf(" %s", aux.nota);
               strcpy(aux.first_key, cria_chave(aux));
               dados = formata_dados(aux);
               fprintf(fd, "%s", dados);
               if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
               {
                    auxp = alocarP(aux.first_key, novo_RRN(vetp) + 1);
                    auxs = alocarS(aux.first_key, aux.titulo_portugues);
                    vetp = insereP(vetp, auxp);
                    vets = insereS(vets, auxs);

                    if(flagp == 1)
                    {
                         atualiza_flag(fp, "iprimary.idx");
                         flagp = 0;
                    }
                    if(flags == 1)
                    {
                         atualiza_flag(fs, "ititle.idx");
                         flags = 0;
                    }
               }
              

               //lembrar de: alterar flag no arquivo de indices quando fizer a alteração, salvar na lista em RAM e salvar no arquivo de indices quando fechar.
          }
          else
          {
               fclose(fd);
               if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
               salvar(fp, fs, vetp, vets);
          }

     }while(op != 6);

     
}