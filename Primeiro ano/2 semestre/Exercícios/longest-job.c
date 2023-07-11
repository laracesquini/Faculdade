#include <stdio.h>
#include <stdlib.h>

typedef struct programas 
{
    int sub;
    int Te;
    struct programas *prox;
}Tprog;

Tprog *insere(Tprog *h, Tprog *p);
Tprog *aloca(int sub, int Te);
void retira (Tprog **h, int Tempo);
int busca(Tprog *h, int i);

int main()
{
    int i, N, inicio = 10001, maior, *resp, sub, Te;
    Tprog *head = NULL, *aux;

    scanf("%d", &N);

    resp = malloc(N*sizeof(int));

    for(i=0; i<N; i++)
    {
        scanf("%d %d", &sub, &Te);
        aux = aloca(sub, Te);
        if(aux->sub < inicio)
        inicio = aux->sub;
        head = insere(head, aux);
    }
    
    i=0;

    while(head)
    {
        maior = busca(head, inicio);
        if(maior == 0)
        {
            inicio = head->sub;
            maior = busca(head, inicio);
        }
        retira(&head, maior);
        resp[i] = maior;
        i++;
        inicio = inicio + maior;
    }

    for(i=0; i<N; i++)
    {
        printf("%d ", resp[i]);
    }
    printf("\n");

    return 0;
}

void retira (Tprog **h, int Tempo)
{
    Tprog *aux = *h, *antes;

    if(aux != NULL && aux->Te == Tempo)
    {
        *h = aux->prox;
        free(aux);
        return;
    }

    while(aux != NULL && aux->Te != Tempo)
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

Tprog *insere(Tprog *h, Tprog *p)
{
    Tprog *aux, *antes;

    if(!h)
    return p;
    aux = antes = h;
    while(aux->prox && aux->sub < p->sub)
    {
        antes = aux;
        aux = aux->prox;
    }

    if(aux == h)
    {
        if(h->sub < p->sub)
        {
            p->prox = h->prox;
            h->prox = p;
            return h;
        }
        else if(h->sub > p->sub)
        {
            p->prox = h;
            return p;
        }
    }

    if(aux->sub > p->sub)
    {
        antes->prox = p;
        p->prox = aux;
    }
    else if(aux->sub < p->sub)
    {
        p->prox = aux->prox;
        aux->prox = p;
    }
    return h;
}

Tprog *aloca(int sub, int Te)
{
    Tprog *aux;

    aux = malloc(sizeof(Tprog));
    aux->sub = sub;
    aux->Te = Te;
    aux->prox = NULL;
    return aux;
}

int busca(Tprog *h, int i)
{
    Tprog *aux = h;
    int maior = 0;
    while(aux && aux->sub <= i)
    {
        if(aux->Te > maior)
        maior = aux->Te;
        aux = aux->prox;
    }
    return maior;
}