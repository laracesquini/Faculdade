#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//declaração das funções utilizadas
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
     
     //verificar se o arquivo de filmes existe. Se não existir, cria ele e permite que o usuário insira novos filmes. Se existir, verifica se o arquivo de índices existe
     if(file_exists("movies.dat") == 0)
     {
        printf("Olá! Essa é sua primeira interação com o programa. Leia as regras para melhor entendimento de seu funcionamento.\n");
        printf("\t*Nessa interação, somente a operação de inserção está disponível.\n\t*A partir das outras interações, as outras opções estarão disponíveis também.\n");
        printf("\t*Evite usar acentos e caratceres especiais.\n");
        printf("\t*O atributo nota só permite números de 0 a 9.\n");
        printf("\tAperte enter para iniciar ");
        getchar();

        fd = fopen("movies.dat", "a+");
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
          //verifica se os arquivos de índices existem. Se existir, verifica as flags
          if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
          {
               fp = fopen("iprimary.idx", "r");
               fs = fopen("ititle.idx", "r");

               fscanf(fp, "%d", &flagp);
               fscanf(fs, "%d", &flags);

               fclose(fp);
               fclose(fs);
               
               //se a flag for 1, o arquivo de índices está atualizado, carrega os índices para a memória RAM. Se for 0, o arquivo está desatualizado, recria os índices com base no arquivo de dados
               if(flagp == 1)
               vetp = carrega_indicesP(fp, vetp);
               else
               {
                    cria_indices(fd, fp, fs, vetp, vets, flagp, flags);
                    
                    vetp = carrega_indicesP(fp, vetp);
                    flagp = 1;
                    flags = 1;
               }

               if(flags == 1)
               vets = carrega_indicesS(fs, vets);
               else
               {
                    cria_indices(fd, fp, fs, vetp, vets, flagp, flags);

                    vets = carrega_indicesS(fs, vets);
                    flags = 1;
               }
          }
          else //se os arquivos de índices não existem, criar os índices com base no arquivo de dados e carregar eles para a memória RAM
          {
               cria_indices(fd, fp, fs, vetp, vets, 0, 0);

               vetp = carrega_indicesP(fp, vetp);
               vets = carrega_indicesS(fs, vets);

               flagp = 1;
               flags = 1;
          }

          do{
               //menu de opções
               do{
               op = menu();
               }while(op < 1 || op > 7);
               
               if(op == 1)
               {
                    //insere nas listas de índices e no arquivo de dados. Atualizando a flag se necessário
                    aux = insercao();
                    dados = formata_dados(aux);
                    fd = fopen("movies.dat", "a+");
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
                    //busca e remove um elemento das listas de índices e do arquivo de dados, atualizando a flag se necessário
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
                    //modifica a nota de determinado filme, buscando ele pelo RRN e acessando sua posição no arquivo de dados
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
               }
               else if(op == 4)
               {
                    //busca um filme pela chave primária ou o título em português
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
                         scanf(" %[^\n]s", titulo);
                         busca_secundario(vetp, vets, titulo, fd);
                    }
               }
               else if(op == 5)
               {
                    //imprime o catálogo dos filmes disponíveis
                    catalogo(fd);
               }
               else if(op == 6)
               {    //compacta o arquivo de dados, refazendo os índices
                    vetp = NULL;
                    vets = NULL;
                    compactar(fd);
                    cria_indices(fd, fp, fs, vetp, vets, 0, 0);
                    vetp = carrega_indicesP(fp, vetp);
                    vets = carrega_indicesS(fs, vets);

                    flagp = 1;
                    flags = 1;
               }
               else
               {
                    //salva as alterações nos arquivos de índices se eles existirem
                    if(file_exists("iprimary.idx") && file_exists("ititle.idx"))
                    salvar(fp, fs, vetp, vets, 0, 0);
               }
          }while(op != 7);
     }
}

//função que imprime o menu de opções, retornando a opção escolhida pelo usuário
int menu()
{
     int op;

     if(file_exists("iprimary.idx"))
     {
          printf("\nBem-vindo!!\n");
          printf("Escolha uma opção: \n");
          printf("[1]Inserir um novo filme no catálogo\n");
          printf("[2]Remover um filme\n");
          printf("[3]Modificar a nota de um filme\n");
          printf("[4]Buscar filmes\n");
          printf("[5]Ver catálogo\n");
          printf("[6]Compactar arquivo de dados\n");
          printf("[7]Sair\n");
          scanf("%d", &op);
          if(op < 1 || op > 7)
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

//função para que o usuário insira as informações necessárias para a inserção de um filme, retornando um registro com os dados
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

//função para que o usuário insira a chave primária necessária para a remoção de um filme, retornando a chave
char *remocao()
{
     char *chave;
     chave = (char *)malloc(6);

     printf("Adicione a chave do filme que será removido: ");
     scanf(" %s", chave);

     return chave;
}

//função para que o usuário insira a chave primária necessária para a alteração da nota, retornando a chave
char *modificacao()
{
     char *chave;
     chave = (char *)malloc(6);

     printf("Adicione a chave do filme que será modificado: ");
     scanf(" %s", chave);

     return chave;
}

//função para que o usuário escolha a forma de busca desejada, retornando a opção escolhida
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