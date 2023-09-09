//implementação de funções
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    int sla;
    Iprimario *auxp;

    fp = fopen("iprimary.idx", "r");
    fscanf(fp, "%d", &sla);

    while(fscanf(fp, "%[^#]s", aux) > 0)
    {
        fgetc(fp);
        token = strtok(aux, "@");
        auxp = malloc(sizeof(Iprimario));
        strcpy(auxp->first_key, token);
        token = strtok(NULL, "@");
        auxp->RRN = atoi(token);
        auxp->prox = NULL;
        vetp = insereP(vetp, auxp);
    }

    fclose(fp);

    return vetp;
}

Isecundario *carrega_indicesS(FILE *fs, Isecundario *vets)
{
    char *token, aux[100];
    int sla;
    Isecundario *auxs;

    fs = fopen("ititle.idx", "r");
    fscanf(fs, "%d", &sla);

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

    fclose(fs);

    return vets;
}

void cria_indices(FILE *fd, FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets, int flagp, int flags)
{
    char aux[193], *token;
    Iprimario *auxp;
    Isecundario *auxs;
    int count = 0;


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
        if(aux[0] == '*') //testar se isso funciona depois
        continue;

        token = strtok(aux, "@");
        if(flagp == 0)
        {
            auxp = malloc(sizeof(Iprimario));
            strcpy(auxp->first_key, token);
            auxp->RRN = count;
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
        fprintf(fp, "%d", 1);

        auxp = vetp;
        while(auxp != NULL)
        {
            fprintf(fp, "%s@%d@#", auxp->first_key, auxp->RRN);
            auxp = auxp->prox;
        }
    }
    
    if(flags == 0)
    {
        fprintf(fs, "%d", 1);
        
        auxs = vets;
        while(auxs != NULL)
        {
            fprintf(fs, "%s@%s@#", auxs->titulo, auxs->first_key);
            auxs = auxs->prox;
        }
    }
    
    
    fclose(fp);
    fclose(fs);

    return;
}

char *cria_chave(Tdados aux)
{
    int i;
    char *aux1 = (char *)malloc(4);
    char *aux2 = (char *)malloc(3);
    char upper[30];
    
    strncpy(aux1, aux.diretor + 0, 3);
    
    strncpy(aux2, aux.ano + 2, 2);
    
    strcat(aux1, aux2);
    aux1[5] = '\0';

    for (int i = 0; i < strlen(aux1); i++) 
    {
        aux1[i] = toupper(aux1[i]); 
    }
    
    return aux1;
}

char *formata_dados(Tdados aux)
{
    char *dados = (char *)malloc(193);
    int i;
    
    strcpy(dados, aux.first_key);
    strcat(dados, "@");
    strcat(dados, aux.titulo_portugues);
    strcat(dados, "@");
    strcat(dados, aux.titulo_original);
    strcat(dados, "@");
    strcat(dados, aux.diretor);
    strcat(dados, "@");
    strcat(dados, aux.ano);
    strcat(dados, "@");
    strcat(dados, aux.pais);
    strcat(dados, "@");
    strcat(dados, aux.nota);
    strcat(dados, "@");

    int len = strlen(dados);

    for(i = len; i < 192; i++)
    {
        dados[i] = '#';
    }

    dados[192] = '\0';

    return dados;
}

Iprimario *alocarP(char *chave, int RRN)
{
    Iprimario *aux;

    aux = malloc(sizeof(Iprimario));
    strcpy(aux->first_key, chave);
    aux->RRN = RRN;
    aux->prox = NULL;

    return aux;
}

Isecundario *alocarS(char *chave, char *titulo)
{
    Isecundario *aux;

    aux = malloc(sizeof(Isecundario));
    strcpy(aux->first_key, chave);
    strcpy(aux->titulo, titulo);

    return aux;
}

int novo_RRN(Iprimario *vetp)
{
    Iprimario *aux;
    int maior;

    aux = vetp;
    maior = aux->RRN;

    while(aux != NULL)
    {
        if(aux->RRN > maior)
        maior = aux->RRN;

        aux = aux->prox;
    }

    return maior;
}

void salvar(FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets)
{
    Iprimario *auxp;
    Isecundario *auxs;

    fp = fopen("iprimary.idx", "w");
    fs = fopen("ititle.idx", "w");

    fprintf(fp, "%d", 1);
    auxp = vetp;
    while(auxp != NULL)
    {
        fprintf(fp, "%s@%d@#", auxp->first_key, auxp->RRN);
        auxp = auxp->prox;
    }

    fprintf(fs, "%d", 1);
    auxs = vets;
    while(auxs != NULL)
    {
        fprintf(fs, "%s@%s@#", auxs->titulo, auxs->first_key);
        auxs = auxs->prox;
    }

    fclose(fp);
    fclose(fs);

    return;
}

void atualiza_flag(FILE *file, char *nome)
{
    char c;

    file = fopen(nome, "r+");
    c = fgetc(file);
    fseek(file, 0, SEEK_SET);
    fputc('0', file);

    fclose(file);

    return;
}