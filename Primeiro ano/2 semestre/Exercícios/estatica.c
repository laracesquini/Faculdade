#include <stdio.h>

typedef struct num
{
    int n;
    int prox;
}Tlista;

void insere(Tlista num[200], int N, int *h)
{
    int i=1, j, antes;
    while(num[i].prox != -1 && i<200)
    i++;
    if(i==200)
    return; //não tem espaço;

    num[i].n = N;
    j = *h;
    while(j>0 && num[j].n<N)
    {
        antes = j;
        j = num[i].prox;
    }
    num[i].prox = j;
    if(j==*h)
    *h = i;
    else
    num[antes].prox = i;
}

void remover(Tlista num[200], int N, int *h)
{
    int i = *h, j, antes;

    while(i>0 && num[i].n < N)
    {
        antes = i;
        i = num[i].prox;
    }
    

    if(num[i].n == N)
    {
        printf("\nNão existe");
        return;
    }
    num[antes].prox = num[i].prox;

    if(i==*h)
    *h = num[i].prox;

    num[i].prox = -1;
}

void imprime(Tlista num[200])
{
    int i;

    for(i=0; i<200; i++)
    {
        printf("%d ", num[i].n);
    }
}

int main()
{
    int i, op=0, NUM, *head;
    Tlista Num[200];

    *head = 0;

    for(i=0; i<200; i++)
    {
        Num[i].prox = -1;
    }

    while(op<3)
    {
        printf("\nDigite uma opção: [1]Inserir [2]Remover");
        scanf("%d", &op);
    

    if(op == 1)
    {
        printf("\nQue número você deseja inserir na lista? ");
        scanf("%d", &NUM);
        insere(Num, NUM, head);
    }
    else if(op == 2)
    {
        printf("\nDigite o número de deseja retirar: ");
        scanf("%d", &NUM);
        remover(Num, NUM, head);
    }
    else if(op>=3)
    {
        imprime(Num);
    }
    }
    


}