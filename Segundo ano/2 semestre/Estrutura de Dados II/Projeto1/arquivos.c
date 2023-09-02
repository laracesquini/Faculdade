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

Iprimario *carrega_indicesP(FILE *fp, Iprimario *vetp)
{
    char *token, aux[20];
    Iprimario *auxp;

    while(!feof(fp))
    {
        fscanf(fp, "%[^#]s", aux);
        fgetc(fp);
        token = strtok(aux, "@");
        auxp = malloc(sizeof(Iprimario));
        strcpy(auxp->first_key, token);
        token = strtok(NULL, "@");
        auxp->RNN = atoi(token);
        auxp->prox = NULL;
        vetp = insereP(vetp, auxp);
    }

    return vetp;
}

Isecundario *carrega_indicesS(FILE *fs, Isecundario *vets)
{
    char *token, aux[100];
    Isecundario *auxs;

    while(!feof(fs))
    {
        fscanf(fs, "%[^#]s", aux);
        fgetc(fs);
        token = strtok(aux, "@");
        auxs = malloc(sizeof(Isecundario));
        strcpy(auxs->titulo, token);
        token = strtok(NULL, "@");
        strcpy(auxs->first_key, token);
        auxs->prox = NULL;
        vets = insereS(vets, auxs);
    }

    return vets;
}

void cria_indices(FILE *fd, Iprimario **vetp, Isecundario **vets)
{
    char aux[193];
    Iprimario *auxp;
    Isecundario *auxs;
    int count = 0;

    while(!feof(fd))
    {
        fread(aux, 192, 1, fd);
        char *token = strtok(aux, "@");
        auxp = malloc(sizeof(Iprimario));
        auxs = malloc(sizeof(Isecundario));
        strcpy(auxp->first_key, token);
        strcpy(auxs->first_key, token);
        token = strtok(NULL, "@");
        strcpy(auxs->titulo, token);
        auxp->RNN = count;
        count++;

        *vetp = insereP((*vetp), auxp);
        *vets = insereS((*vets), auxs);

        vetp = &(*vetp);
        vets = &(*vets);
        
        printf("Vetp: %s, %d\n", (*vetp)->first_key, (*vetp)->RNN);
        printf("Vets: %s, %s\n", (*vets)->titulo, (*vets)->first_key);
    }

    fclose(fd);
}
