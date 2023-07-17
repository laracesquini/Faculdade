//Inclusão das bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//DUPLA: Lara Cesquini Stopa e Laiza Lima Peria

int main()
{
    //Declaração das variáveis
    int a, op, i;
    boolean b;
    lista L[MAX];
    tipo_elem x;

    Definir(L); //Criando a lista

    do{
        do{
            printf("Tabela de operações: \n"); //Tabela de operações posíveis na lista
            printf("[1].Inserir elemento.\n");
            printf("[2].Buscar elemento.\n");
            printf("[3].Remover elemento.\n");
            printf("[4].Imprimir lista.\n");
            printf("[5].Tamanho da lista.\n");
            printf("[6].Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &op);
            if(op < 1 || op > 6)
            {
                printf("Opção inválida!");
            }
        } while(op < 1 || op > 6);
        
        if(op == 1) //Inserção de um elemento na lista
        {
            //pede as informações necessárias ao usuário
            printf("Digite o nome do aluno: ");
            scanf("%s", x.info.nome);
            printf("Digite a idade do aluno: ");
            scanf("%d", &x.info.idade);
            printf("Digite a média final do aluno: ");
            scanf("%f", &x.info.media_final);
            printf("Insira a chave: ");
            scanf("%d", &x.chave);
            b = Inserir_ord(x, L); //Chama a função de inserção
            if(b == TRUE) //Verifica se foi possível realizar a inserção
            printf("O elemento foi inserido com sucesso!\n");
            else 
            printf("Não foi possível realizar a inserção\n");
        }
        else if(op == 2) //Busca de um elemento na lista
        {
            printf("Adicione uma chave: ");
            scanf("%d", &i);
            a = Buscar(i, L); //Chama a função de busca
            if(a != -1) //Verifica se o elemento foi encontrado
            {
                printf("Elemento encontrado!\n");
                printf("O elemento está na posição: %d\n", a);
            }
            else
            printf("Elemento não encontrado.\n");

        }
        else if(op == 3) //Remoção de um elemento da lista
        {
            printf("Adicione uma chave: ");
            scanf("%d", &i);
            b = Remover_ch(i, L); //Chama a função de remoção
            if(b == TRUE) //Verifica se foi possível remover
            printf("Elemento removido!\n");
            else
            printf("Não foi possível remover o elemento.\n");

        }
        else if(op == 4) //Imprime a lista
        {
            if(Vazia(L)) //Verifica se está vazia ou não
            printf("A lista está vazia! \n");
            else
            Imprimir(L);
        }
        else if(op == 5) //Imprime o tamanho da lista
        {
            i = Tamanho(L);
            printf("Tamanho da lista: %d\n", i);
        }
    }while(op != 6);

}