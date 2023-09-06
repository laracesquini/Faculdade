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

    while(fscanf(fp, "%[^#]s", aux) > 0)
    {
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

    while(fscanf(fs, "%[^#]s", aux) > 0)
    {
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

void cria_indices(FILE *fd, FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets, int flagp, int flags)
{
    char aux[193], *token;
    Iprimario *auxp;
    Isecundario *auxs;
    int count = 0;

    fd = fopen("movies.txt", "r");

    if(flagp == 0)
    {
        fp = fopen("iprimary.idx", "w");

    }

    if(flags == 0)
    {
        fs = fopen("ititle.idx", "w");
    }
    
    while(fread(aux, 192, 1, fd) == 1)
    {
        token = strtok(aux, "@");
        if(flagp == 0)
        {
            auxp = malloc(sizeof(Iprimario));
            strcpy(auxp->first_key, token);
            auxp->RNN = count;
            auxp->prox = NULL;
            count++;

            vetp = insereP(vetp, auxp);
        }
        if(flags == 0)
        {
            auxs = malloc(sizeof(Isecundario));
            strcpy(auxs->first_key, token);
            token = strtok(NULL, "@");
            strcpy(auxs->titulo, token);
            auxs->prox = NULL;

            vets = insereS(vets, auxs);
        }
    }
    
    if(flagp == 0)
    {
        fprintf(fp, "%d\n", 1);

        auxp = vetp;
        while(auxp != NULL)
        {
            fprintf(fp, "%s@%d@#", auxp->first_key, auxp->RNN);
            auxp = auxp->prox;
        }
    }
    
    if(flags == 0)
    {
        fprintf(fs, "%d\n", 1);
        
        auxs = vets;
        while(auxs != NULL)
        {
            fprintf(fs, "%s@%s@#", auxs->titulo, auxs->first_key);
            auxs = auxs->prox;
        }
    }
    
    
    fclose(fp);
    fclose(fs);
    fclose(fd);
}

char *cria_chave(Tdados aux)
{
    int i;
    char *aux1, *aux2;
    aux1 = malloc(4);
    aux2 = malloc(3);

    strncpy(aux1, aux.diretor + 0, 3);
    
    strncpy(aux2, aux.ano + 2, 2);
    aux1[3] = '\0';
    aux2[2] = '\0';

    strcat(aux1, aux2);
    
    return aux1;
}