#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra
{
    char palavra[100];
    struct palavra *prox;
} Palavra;

Palavra *insere(Palavra *h, Palavra *p);
Palavra *alocar(char *p);
void remover(Palavra **h, char *p);
void imprimir(Palavra *h);

int main()
{
    int N, M, i, op;
    char p[100];
    Palavra *head=NULL, *aux;

    scanf("%d", &N);
    scanf("%d", &M);

    for(i=0; i<N; i++)
    {
        scanf(" %s ", p);
        aux = alocar(p);
        head = insere(head, aux);
    }

    for(i=0; i<M; i++)
    {
        scanf("%d", &op);
        if(op==0)
        {
            scanf(" %s", p);
            remover(&head, p);
            if(head==NULL)
            printf("NULL\n");
            else
            imprimir(head);
        }
        else
        {
            scanf(" %s", p);
            aux = alocar(p);
            head = insere(head, aux);
        }
    }

    return 0;
}

Palavra *insere(Palavra *h, Palavra *p)
{
    Palavra *aux, *antes;

    if(!h)
    {
    return p;
    }
    aux = antes = h; //todo mundo aponta p onde a cabeça tá apontando
    while(aux->prox && strcmp(p->palavra, aux->palavra)>0) //se não cheguei no final da lista e a palavra que será inserida é maior que a atual, continua
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h) //insere como primeiro elemento
    {
        if(strcmp(p->palavra, h->palavra)<0)
        {
            p->prox = h;
            return p;
        }
        else if(strcmp(p->palavra, h->palavra)>0)
        {
            p->prox = h->prox;
            h->prox = p;
            return h;
        }
        else
        return h;
    }
    if(strcmp(p->palavra, aux->palavra)<0) //insere antes do último elemento
    {
        antes->prox = p;
        p->prox = aux;
        return h;
    }
    else if(strcmp(p->palavra, aux->palavra)>0) //insere como ultimo elemento
    {
        p->prox = aux->prox;
        aux->prox = p;
        return h;
    }
    else
    return h;
}

void remover(Palavra **h, char *p)
{
    Palavra *aux, *antes;
    aux = *h;
    
    if(aux!=NULL && strcmp(aux->palavra, p)==0)
    {
        *h = aux->prox;
        free(aux);
        return;
    }
    while(aux!=NULL && strcmp(aux->palavra, p)!=0)
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        return;
    }

    antes->prox = aux->prox;
    free(aux);
}

Palavra *alocar(char *p)
{
    Palavra *nova;
    nova = malloc(sizeof(Palavra));
    strcpy(nova->palavra, p);
    nova->prox = NULL;
    return(nova);
}

void imprimir(Palavra *h)
{
    Palavra *aux = h;

    while(aux!= NULL)
    {
        printf("%s ", aux->palavra);
        aux = aux->prox;
    }
    printf("\n");
}

