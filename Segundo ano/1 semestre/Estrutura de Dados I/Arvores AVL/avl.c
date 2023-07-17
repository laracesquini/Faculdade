#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int altura(no *raiz)
{
    if(raiz == NULL)
    return 0;

    int altD = altura(raiz->dir);
    int altE = altura(raiz->esq);

    if(altE > altD)
    return(altE+1);

    return (altD+1);
}

int maior(int x, int y)
{
    if(x > y)
    return x;
    else
    return y;
}

no *criar_raiz(int elem)
{
    no *raiz = malloc(sizeof(no));

    raiz->info = elem;
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->altura = 1;

    return raiz;
}

no *rotacaoDireita(no *raiz)
{
    no *aux = raiz->esq;
    no *aux2= aux->dir;

    aux->dir = raiz;
    raiz->esq = aux2;

    raiz->altura = maior(altura(raiz->esq), altura(raiz->dir) + 1);
    aux->altura = maior(altura(aux->esq), altura(aux->dir) + 1);

    return aux;
}

no *rotacaoEsquerda(no *raiz)
{
    no *aux = raiz->dir;
    no *aux2= aux->esq;

    aux->esq = raiz;
    raiz->dir = aux2;

    raiz->altura = maior(altura(raiz->esq), altura(raiz->dir) + 1);
    aux->altura = maior(altura(aux->esq), altura(aux->dir) + 1);

    return aux;
}

int fator_balanceamento(no *raiz)
{
    if(raiz == NULL)
    return 0;

    return altura(raiz->dir) - altura(raiz->esq);
}

no *inserir(no *raiz, int elem)
{
    if(raiz == NULL)
    return(criar_raiz(elem));

    if(elem < raiz->info)
    raiz->esq = inserir(raiz->esq, elem);
    else if(elem > raiz->info)
    raiz->dir = inserir(raiz->dir, elem);
    else
    return raiz;

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    int FB = fator_balanceamento(raiz);

    if(FB < -1 && elem < raiz->esq->info)
    return rotacaoDireita(raiz);
    if(FB > 1 && elem > raiz->dir->info)
    return rotacaoEsquerda(raiz);
    if(FB < -1 && elem > raiz->esq->info)
    {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }
    if(FB > 1 && elem < raiz->dir->info)
    {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

no *menor(no *raiz)
{
    no *aux = raiz;

    while(aux->esq != NULL)
    aux = aux->esq;

    return aux;
}

no *remover(no *raiz, int elem)
{
    if(raiz == NULL)
    return raiz;

    if(elem < raiz->info)
    raiz->esq = remover(raiz->esq, elem);
    else if(elem > raiz->info)
    raiz->dir = remover(raiz->dir, elem);
    else
    {
        if((raiz->esq == NULL) || (raiz->dir == NULL))
        {
            no *aux = NULL;
            if(raiz->esq != NULL)
            aux = raiz->esq;
            else
            aux = raiz->dir;

            if(aux == NULL)
            {
                aux = raiz;
                raiz = NULL;
            }
            else
            *raiz = *aux;

            free(aux);
        }
        else
        {
            no *aux = menor(raiz->dir);

            raiz->info = aux->info;

            raiz->dir = remover(raiz->dir, aux->info);
        }
    }

    if(raiz == NULL)
    return raiz;

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    int FB = fator_balanceamento(raiz);

    if(FB < -1 && fator_balanceamento(raiz->esq) >= 0)
    return rotacaoDireita(raiz);
    
    if(FB < -1 && fator_balanceamento(raiz->esq) < 0)
    {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }
    
    if(FB > 1 && fator_balanceamento(raiz->esq) <= 0)
    return rotacaoEsquerda(raiz);
    
    if(FB > 1 && fator_balanceamento(raiz->esq) > 0)
    {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;

}

void inOrder(no *raiz)
{
    if(raiz != NULL)
    {
        inOrder(raiz->esq);
        printf("%d ", raiz->info);
        inOrder(raiz->dir);
    }
}