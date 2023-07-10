#include <stdio.h>
#include <stdlib.h>

typedef struct circ
{
    int I;
    int K;
    int O;
    struct circ *prox;
}Tcirc; //estrutura do tipo lista declarada 

int prox = 0, opc = 0, antI = 0, antK = 0, antO = 0; //variáveis que serão usadas no programa

//protótipos das funções usadas
Tcirc *insere(Tcirc *h, Tcirc *elem);
Tcirc *aloca(int i, int k, int o);
Tcirc *remover(Tcirc *h);
void inicializa(Tcirc *h);

int main()
{
    int N, i, k, o;
    Tcirc *head=NULL, *aux;

    scanf("%d", &N); //leio o número de elementos da lista 

    for(i=1; i<=N; i++) //laço que é percorrido até que o ultimo elemnto da lista seja preenchido
    {
        scanf("%d %d", &k, &o);//leio as informações 
        aux = aloca(i, k, o);//aloco memória criando um elemento do tipo lista, passando as informações necessárias
        head = insere(head, aux);//insiro o elemento na lista ordenadamente
    }

    prox = head->K; //variável que vai receber quantas casas tenho que andar para retirar o próximo número
    opc = head->O; //variável que vai receber a informação que diz se o elemento vai ser retirado ou retirado e o anterior reeinserido
    inicializa(head); //função que salva as informações do elemente a ser retirado, caso ele precise ser reeinserido
    head = remover(head); //passo a cabeça para a função de remover
    printf("%d", head->I); //printo o número do elemento restante
}

Tcirc *insere(Tcirc *h, Tcirc *elem) //função para inserção de elementos, retorna a nova cabeça
{
    Tcirc *aux, *antes;

    if(!h) //verifica se a cabeça é nula
    {
        h = elem;
        return elem;
    }
    aux = antes = h;
    if(h->prox == h) //verifica se tem um elemento só na lista
    {
        elem->prox = aux;
        aux->prox = elem;
        if(elem->I < aux->I) //verifica se preciso atualizar a cabeça
        h = elem;
        return h;
    }
    while(antes->prox != h && elem->I > aux->I) //laço percorrido ate chegar no final da lista ou achar o lugar em que o elemento deve ser inserido
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h && elem->I < aux->I) //elemento deve ser inserido como a nova cabeça da lista
    {
        antes = aux->prox;
        while(antes->prox != aux)
        antes = antes->prox;
        antes->prox = elem;
        elem->prox = h;
        h = elem;
    }
    elem->prox = aux; //elemento inserido no meio da lista
    antes->prox = elem;

    return h;
}

Tcirc *aloca(int i, int k, int o) //aloca memória para um elemento do tipo lista criado
{
    Tcirc *aux;
    aux = malloc(sizeof(Tcirc));
    aux->I = i;
    aux->K = k;
    aux->O = o;
    aux->prox = aux; //retorna o elemento apontando para ele mesto pelo fato de ser uma lista circular
    return aux;
}

Tcirc *remover(Tcirc *h) //função que remove os elementos até sobrar só um
{
    int i;
    Tcirc *aux, *antes, *aux2 = NULL, *aux3 = NULL;
    aux = antes = h;

    if(h->prox == h) //se sobrar só um elemento, retorna ele
    {
        return h;
    }
    else
    {
        for(i=1; i<prox; i++) //ando as posições que vão indicar o próximo elemento a ser retirado
        {
            antes = aux;
            aux = aux->prox;
        }
        antes->prox = aux->prox; //retiro o elemento 
        prox = aux->K; //atualizo as variáveis
        opc = aux->O;
        if(opc == 0) //se o elemento retirado tiver como opção 0, ja retirei ele, só salvo suas informações caso ele precise ser reeinserido
        inicializa(aux);
        else if(opc==1) //se o elemento retirado tiver como opção 1, já retirei ele mas preciso reeinserir o anterior, que tem suas informações salvas nas variáveis ant, ent aloco memoria passando essas informações e chamo a função de inserir novamente
        {
            aux2 = aloca(antI, antK, antO);
            aux3 = insere(h, aux2);
            inicializa(aux); //salvo as informações também caso ele precise ser reeinserido
        }
        free(aux);
        return remover(antes->prox); //chamo a função recursivamente 
    }

}
void inicializa(Tcirc *h) //função recebe um elemento do tipo lista e copia suas informações nas variáves
{
    antI = h->I;
    antK = h->K;
    antO = 0;
}


