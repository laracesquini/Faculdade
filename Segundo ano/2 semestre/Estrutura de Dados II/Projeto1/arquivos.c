//implementação de funções
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

int file_exists(char *nome)
{
    FILE *fp;

    if(fp = fopen(nome, "r"))
    {
        fclose(fp);
        return 1;
    }

    return 0;
}

Iprimario *insereP(Iprimario *h, Iprimario *p)
{
    Iprimario *aux, *antes;

    if(!h)
    {
    return p;
    }
    aux = antes = h; //todo mundo aponta p onde a cabeça tá apontando
    while(aux->prox && strcmp(p->first_key, aux->first_key)>0) //se não cheguei no final da lista e a palavra que será inserida é maior que a atual, continua
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h) //insere como primeiro elemento
    {
        if(strcmp(p->first_key, h->first_key)<0)
        {
            p->prox = h;
            return p;
        }
        else if(strcmp(p->first_key, h->first_key)>0)
        {
            p->prox = h->prox;
            h->prox = p;
            return h;
        }
        else
        return h;
    }
    if(strcmp(p->first_key, aux->first_key)<0) //insere antes do último elemento
    {
        antes->prox = p;
        p->prox = aux;
        return h;
    }
    else if(strcmp(p->first_key, aux->first_key)>0) //insere como ultimo elemento
    {
        p->prox = aux->prox;
        aux->prox = p;
        return h;
    }
    else
    return h;
}

Isecundario *insereS(Isecundario *h, Isecundario *p)
{
    Isecundario *aux, *antes;

    if(!h)
    {
    return p;
    }
    aux = antes = h; //todo mundo aponta p onde a cabeça tá apontando
    while(aux->prox && strcmp(p->titulo, aux->titulo)>0) //se não cheguei no final da lista e a palavra que será inserida é maior que a atual, continua
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h) //insere como primeiro elemento
    {
        if(strcmp(p->titulo, h->titulo)<0)
        {
            p->prox = h;
            return p;
        }
        else if(strcmp(p->titulo, h->titulo)>0)
        {
            p->prox = h->prox;
            h->prox = p;
            return h;
        }
        else
        return h;
    }
    if(strcmp(p->titulo, aux->titulo)<0) //insere antes do último elemento
    {
        antes->prox = p;
        p->prox = aux;
        return h;
    }
    else if(strcmp(p->titulo, aux->titulo)>0) //insere como ultimo elemento
    {
        p->prox = aux->prox;
        aux->prox = p;
        return h;
    }
    else
    return h;
}
