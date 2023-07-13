#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int I;
    int T;
    struct fila *prox;
}Fila;

int maior = 0, caixa = 0;

void insere(Fila **h, Fila **t, Fila *elem);
Fila *aloca(int i, int t);
void remover(Fila **h, Fila **t);
void imprime(Fila *h);


int main()
{
    int N, i, j, idade, temp, *Vi, *Vt, *tempo, aux1;
    Fila *aux, *head = NULL, *tail = NULL;

    scanf("%d", &N);

    Vi = malloc(N*sizeof(int));
    Vt = malloc(N*sizeof(int));
    tempo = malloc(N*sizeof(int));

    for(i=0; i<N; i++)
    {
        scanf("%d", &idade);
        scanf("%d", &temp);
        Vi[i] = idade;
        Vt[i] = temp;
        tempo[i] = 0;
    }

    for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(Vt[i] > Vt[j])
            {
                aux1 = Vt[j];
                Vt[j] = Vt[i];
                Vt[i] = aux1;

                aux1 = Vi[j];
                Vi[j] = Vi[i];
                Vi[i] = aux1;
            }
        }
    }

    caixa = Vt[0] + 3;
    j = 0;

    for(i=0; i<N; i++)
    {
        aux = aloca(Vi[i], Vt[i]);
        insere(&head, &tail, aux);
        if(Vt[j] >= caixa)
        {
            remover(&head, &tail);
            caixa = caixa + 3;
            j = 0;
            
        }
        if(Vt[i]!=Vt[i+1])
        imprime(head);
        j++;
    }
    
    return 0;
}

Fila *aloca(int i, int t)
{
    Fila *aux;
    aux = malloc(sizeof(Fila));
    aux->I = i;
    aux->T = t;
    aux->prox = NULL;
    return aux;
}

void imprime(Fila *h)
{
    Fila *aux;
    aux = h;
    while(aux!= NULL)
    {
        printf("%d ", aux->I);
        aux = aux->prox;
    }
    printf("\n");
    return;
}
void insere(Fila **h, Fila **t, Fila *elem)
{
    Fila *aux, *antes;
    aux = *h;
    
    if(*h == NULL)
    {
        *h = *t = elem;
        return;
    }
    else
    {
        if(elem->I > 59)
        {
            while(aux!=NULL)
            {
                if(aux->I > maior && elem->I > maior)
                {
                    maior = aux->I;
                }
                aux = aux->prox;
            }
            aux = antes = *h;
            while(aux->I != maior)
            {
                antes = aux;
                aux = aux->prox;
            }
            if(elem->I < maior && elem->I > (aux->prox)->I)
            {
                elem->prox = aux->prox;
                aux->prox = elem;
            }
            else
            {
                antes->prox = elem;
                elem->prox = aux;
            }
        }
        else
        {
            (*t)->prox = elem;
            *t = elem;
            return;
        }
    }

}

void remover(Fila **h, Fila **t)
{
    Fila *aux;
    aux = *h;

    if(*h != *t)
    {
        *h = (*h)->prox;
        return;
    }
    else
    {
        *h = *t = NULL;
        return;
    }

}