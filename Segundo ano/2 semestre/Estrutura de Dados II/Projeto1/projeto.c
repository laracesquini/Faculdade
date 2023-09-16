#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//0 - desatualizado
//1 - atualizado
int menu();
Tdados insercao();
char *remocao();
char *modificacao();
int busca_filme();

int main()
{
     int flagp, flags, op, op_busca;
     FILE *fd, *fp, *fs;
     Iprimario *vetp = NULL, *auxp;
     Isecundario *vets = NULL, *auxs;
     Tdados aux;
     char *dados;
     
     if(file_exists("movies.txt") == 0)
     {
        printf("Olá! Essa é sua primeira interação com o programa.\n");
        printf("Logo, somente a operação de inserção está disponível.\n");
        printf("A partir das outras interações, as outras opções estarão disponíveis\n");
        printf("Aperte enter para iniciar ");
        getchar();

        fd = fopen("movies.txt", "a+");
        do{
          do{
               op = menu();
          }while(op < 1 || op > 2);

          if(op == 1)
          {
               aux = insercao();
               dados = formata_dados(aux);
               fprintf(fd, "%s", dados);   
          }
          else
          fclose(fd);
        }while(op != 2);
     }
     else
     {
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
                    flags = 1;
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

          do{
               do{
               op = menu();
               }while(op < 1 || op > 6);
               
               if(op == 1)
               {
                    aux = insercao();
                    dados = formata_dados(aux);
                    fd = fopen("movies.txt", "a+");
                    fprintf(fd, "%s", dados);
                    fclose(fd); 
                    
                    auxp = alocarP(aux.first_key, novo_RRN(fd));
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

                    printf("\nFilme inserido!\n");
               }
               else if(op == 2)
               {
                    if(vetp == NULL && vets == NULL)
                    {
                         printf("Lista vazia! Nenhum filme disponível para a remoção!\n");
                    }
                    else
                    {
                         
                         dados = remocao();
                         auxp = busca(vetp, dados);

                         if(auxp == NULL)
                         printf("Filme não encontrado. Tente novamente!\n");
                         else
                         {
                              remove_arquivo(auxp, fd);
                              vetp = removerP(vetp, dados);
                              vets = removerS(vets, dados);
                         
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
                              
                              printf("\nFilme removido!\n");
                         }
                    }
               }
               else if(op == 3)
               {
                    dados = modificacao();
                    auxp = busca(vetp, dados);

                    if(auxp == NULL)
                    {
                         printf("Esse filme não existe! Tente novamente.\n");
                    }
                    else
                    {
                         printf("Digite a nova nota: ");
                         scanf(" %s", dados);
                         att_arquivo(fd, auxp->RRN, dados);
                         printf("Nota atualizada!\n");
                    }
               }
               else if(op == 4)
               {
                    op_busca = busca_filme();
                    if(op_busca == 1)
                    {
                         char chave[6];

                         printf("Digite a chave do filme buscado: ");
                         scanf(" %s", chave);
                         auxp = busca(vetp, chave);
                         if(auxp == NULL)
                         printf("Filme não encontrado!");
                         else
                         {
                              imprime_filme(auxp, fd);
                         }
                    }
                    else if(op_busca == 2)
                    {
                         char titulo[62];

                         printf("Digite o título: ");
                         scanf(" %s", titulo);
                         auxp = busca_secundario(vetp, vets, titulo);
                         if(auxp == NULL)
                         printf("Filme não encontrado!");
                         else
                         {
                              imprime_filme(auxp, fd);
                         }
                    }
               }
               else if(op == 5)
               {
                    catalogo(fd);
               }
               else
               {
                    if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
                    salvar(fp, fs, vetp, vets, 0, 0);
               }

          }while(op != 6);
     }
}

int menu()
{
     int op;

     if(file_exists("iprimary.idx"))
     {
          printf("Bem-vindo!!\n");
          printf("Escolha uma opção: \n");
          printf("[1]Inserir um novo filme no catálogo\n");
          printf("[2]Remover um filme\n");
          printf("[3]Modificar a nota de um filme\n");
          printf("[4]Buscar filmes\n");
          printf("[5]Ver catálogo\n");
          printf("[6]Sair\n");
          scanf("%d", &op);
          if(op < 1 || op > 6)
          printf("Opção inválida\n");
     }
     else
     {
          printf("[1]Inserir um novo filme no catálogo\n");
          printf("[2]Sair\n");
          scanf("%d", &op);
          if(op < 1 || op > 2)
          printf("Opção inválida\n");
     }
     
     return op;
}

Tdados insercao()
{
     Tdados aux;
     
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

     return aux;
}

char *remocao()
{
     char *chave;
     chave = (char *)malloc(6);

     printf("Adicione a chave do filme que será removido: ");
     scanf(" %s", chave);

     return chave;
}

char *modificacao()
{
     char *chave;
     chave = (char *)malloc(6);

     printf("Adicione a chave do filme que será modificado: ");
     scanf(" %s", chave);

     return chave;
}

int busca_filme()
{
     int op;

     printf("Escolha uma opção: \n");

     do{
          printf("[1]Buscar pela chave\n");
          printf("[2]Buscar pelo título em português\n");
          printf("[3]Voltar\n");
          scanf("%d", &op);
          if(op < 1 || op > 3)
          printf("Opção Inválida!\n");
     }while(op < 1 || op > 3);

     return op;
}