//bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//declaração das funções utilizadas
int menu(int flag);
Tdados insercao();
char *modificacao();
int busca_filme();
int menu_catalogo();

int main()
{
     Isecundario *vets = NULL, *auxs;
     int stt, flags, op, op_busca;
     FILE *fd, *fp, *fs;
     node *raiz;
     Tdados aux;
     char *dados;
     
     //verificar se o arquivo de filmes existe. Se não existir, cria ele e permite que o usuário insira novos filmes.
     if(file_exists("movies.dat") == 0)
     {
        printf("Olá! Essa é sua primeira interação com o programa. Leia as regras para melhor entendimento de seu funcionamento.\n");
        printf("\t*Nessa interação, somente a operação de inserção está disponível.\n\t*A partir das outras interações, as outras opções estarão disponíveis também.\n");
        printf("\t*Evite usar acentos e caracteres especiais.\n");
        printf("\t*O atributo nota só permite números de 0 a 9.\n");
        printf("\tAperte enter para iniciar ");
        getchar();

        //definir a raiz na primeira inserção, setando seu RRN como 0 e escrevendo-o no arquivo que contém a árvore B+
        raiz = cria_no();
        raiz->folha = 1;
        att_raiz(0, fp, 0);
        /*fp = fopen("ibtree.idx", "w");
        fputc('0', fp);
        fclose(fp);*/

        /*raiz = cria_no();
        raiz->folha = 1;
        int RRN_raiz = 0;
        fp = fopen("ibtree.idx", "w");
        fwrite(&RRN_raiz, sizeof(int), 1, fp);
        fclose(fp);*/
        
        do{
          do{
               op = menu(0);
          }while(op < 1 || op > 2);

          if(op == 1)
          {
               //insere o filme na árvore B+ e no arquivo de dados
               aux = insercao();
               stt = inserir(aux.first_key, novo_RRN(fd), &raiz, fp); 
               if(stt == 1)
               {
                    fd = fopen("movies.dat", "a+");
                    dados = formata_dados(aux);
                    fprintf(fd, "%s", dados);
                    fclose(fd);
               }    
          }
        }while(op != 2);
     }
     else //caso o arquivo de filmes já exista
     {
          /*int raiz_RRN;
          fp = fopen("ibtree.idx", "r");
          fread(&raiz_RRN, sizeof(int), 1, fp); //lê o RRN da raiz no arquivo que contém a árvore B+
          fclose(fp);
          raiz = le_no(raiz_RRN, fp);*/

          fp = fopen("ibtree.idx", "r");
          char c[6];
          fscanf(fp, " %[^#]s", c);
          fclose(fp);
          int raiz_RRN = atoi(c);
          raiz = le_no(raiz_RRN, fp);

          //verifica se o arquivo de índice secundário existe. Se existir, verifica a flag
          if(file_exists("ititle.idx"))
          {
               fs = fopen("ititle.idx", "r");

               fscanf(fs, "%d", &flags);

               fclose(fs);
               
               if(flags == 1) //se a flag for 1, o arquivo está atualizado, carrega os índices para a RAM
               vets = carrega_indicesS(fs, vets);
               else //caso contrário, reconstroi os índices e carrage eles para RAM
               {
                    cria_indices(fd, fs, vets, flags);

                    vets = carrega_indicesS(fs, vets);
                    flags = 1;
               }
          }
          else //se o arquivo de índice secundário não existe, criar o índice com base no arquivo de dados e carregar ele para a memória RAM
          {
               cria_indices(fd, fs, vets, 0);

               vets = carrega_indicesS(fs, vets);
               flags = 1;
          }

          do{
               //menu de opções
               do{
               op = menu(1);
               }while(op < 1 || op > 5);
               
               if(op == 1)
               {
                    //insere na lista de índice secundário, na árvore B+ e no arquivo de dados. Atualizando a flag se necessário
                    aux = insercao();
                    dados = formata_dados(aux);
                    stt = inserir(aux.first_key, novo_RRN(fd), &raiz, fp);
                    if(stt == 1)
                    {
                         fd = fopen("movies.dat", "a+");
                         fprintf(fd, "%s", dados);
                         fclose(fd); 
                         
                         auxs = alocarS(aux.first_key, aux.titulo_portugues);
                         vets = insereS(vets, auxs);

                         if(flags == 1)
                         {
                              atualiza_flag(fs, "ititle.idx");
                              flags = 0;
                         }

                         printf("\nFilme inserido!\n");
                    }
               }
               else if(op == 2)
               {
                    //modifica a nota de determinado filme, buscando ele pelo RRN e acessando sua posição no arquivo de dados
                    dados = modificacao();
                    int RRN_buscado = busca(raiz, dados, fp);

                    if(RRN_buscado == -1)
                    {
                         printf("Esse filme não existe! Tente novamente.\n");
                    }
                    else
                    {
                         printf("Digite a nova nota: ");
                         scanf(" %s", dados);
                         att_arquivo(fd, RRN_buscado, dados);
                         printf("Nota atualizada!\n");

                         if(flags == 1)
                         {
                              atualiza_flag(fs, "ititle.idx");
                              flags = 0;
                         }
                    }
               }
               else if(op == 3)
               {
                    //busca um filme pela chave primária ou o título em português
                    op_busca = busca_filme();
                    if(op_busca == 1)
                    {
                         char chave[6];

                         printf("Digite a chave do filme buscado: ");
                         scanf(" %s", chave);
                         int RRN_buscado = busca(raiz, chave, fp);

                         if(RRN_buscado == -1)
                         {
                              printf("Esse filme não existe! Tente novamente.\n");
                         }
                         else
                         {
                              imprime_filme(RRN_buscado, fd);
                         }
                    }
                    else if(op_busca == 2)
                    {
                         char titulo[62];

                         printf("Digite o título: ");
                         scanf(" %[^\n]s", titulo);
                         busca_secundario(raiz, vets, titulo, fd, fp);
                    }
               }
               else if(op == 4)
               {
                    //imprimir os filmes
                    int op_catalogo;
                    node *no_inicio;

                    op_catalogo = menu_catalogo();

                    if(op_catalogo == 1) //imprime todos os filmes a partir de uma chave digitada pelo usuário
                    {
                         char chave_inicio[6];

                         printf("Digite a chave:");
                         scanf(" %s", chave_inicio);

                         printf("chega aqui");
                         no_inicio = busca_no(raiz, chave_inicio, fp);
                         catalogo(fd, fp, no_inicio->RRN, 1, chave_inicio);
                    }
                    else if(op_catalogo == 2) //imprime todos os filmes disponíveis
                    {
                         no_inicio = busca_inicio(raiz, fp);
                         catalogo(fd, fp, no_inicio->RRN, 2, NULL);
                    }
               }
               else
               {
                    //salva as alterações no arquivo de índice secundário se ele existire
                    if(file_exists("ititle.idx"))
                    salvar(fs, vets, 0);
               }
          }while(op != 5);
     }
}

//função que imprime o menu de opções, retornando a opção escolhida pelo usuário
int menu(int flag)
{
     int op;

     if(flag == 1)
     {
          printf("\nBem-vindo!!\n");
          printf("Escolha uma opção: \n");
          printf("[1]Inserir um novo filme no catálogo\n");
          printf("[2]Modificar a nota de um filme\n");
          printf("[3]Buscar filmes\n");
          printf("[4]Ver catálogo\n");
          printf("[5]Sair\n");
          scanf("%d", &op);
          if(op < 1 || op > 5)
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

//função para que o usuário escolha se deseja ver todos os filmes disponíveis ou somente os filmes a partir de uma chave, retornando a opção escolhida
int menu_catalogo()
{
     int op;

     printf("Escolha uma opção: \n");

     do{
          printf("[1]Listar filmes a partir de uma chave\n");
          printf("[2]Listar todos os filmes\n");
          printf("[3]Voltar\n");
          scanf("%d", &op);
          if(op > 3 || op < 1)
          printf("Opção Inválida!\n");
     }while(op < 1 || op > 3);

     return op;
}