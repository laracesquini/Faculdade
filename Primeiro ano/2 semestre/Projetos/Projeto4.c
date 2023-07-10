#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int I;
    int O; 
    int C;
    struct fila *prox;
}Fila;

//declaração das variáveis globais utilizadas
int *stt, *cargas;
int tempo = 0, tam = 0;

//declaração das funções utilizadas
Fila *inserir(Fila *h, Fila *elem);
Fila *remover(Fila *h);
Fila *alocar(int identificacao, int instante, int atendimento);
int adiantar();
int disponivel();
void att();
void atendimento(Fila *h);

int main()
{
    int i, j, M, N, ident, inst, atend;
    Fila *aux, *head = NULL;

    scanf("%d %d", &N, &M);

    //declaração dos vetores de tamanho M que serão utilizados
    stt = malloc(M*sizeof(int)); //vetor que vai armazenar os status dos centro de atendimento. 0 - disponível 1 - ocupado. 
    cargas = malloc(M*sizeof(int)); //vetor que vai armazenar o tempo do atendimento de cada centro
    tam = M; 

    for(i=0; i<M; i++) //zerando os vetores
    {
        cargas[i] = 0;
        stt[i] = 0;
    }

    for(i=0; i<N; i++)
    {
        scanf("%d %d %d", &ident, &inst, &atend); //lendo as informações, alocando memória e inserindo na fila
        aux = alocar(ident, inst, atend);
        head = inserir(head, aux);
    }

    atendimento(head); // função que realizará os atendimentos
    
}

Fila *inserir(Fila *h, Fila *elem) //função para inserir os elementos na fila de forma ordenada de acordo com o instante de chegada ou identificador, se o instante for o mesmo
{
    Fila *aux, *antes;

    aux = antes = h;
    if(h == NULL) //se a cabeça for nula, retorna o próprio elemento
    return elem;
    while(aux != NULL && elem->O > aux->O) //laço que é percorrido até chegar no final da fila ou até que o elemento comparado seja maior que o atual
    {
        antes = aux;
        aux = aux->prox;
    }
    while(aux != NULL && aux->O == elem->O && elem->I > aux->I) //laço percorrido caso o instante de chegado seja o mesmo
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h) //caso precise atualizar a cabeça
    {
        elem->prox = h;
        return elem;
    }
    //se não entrar em nenhum if, insere no meio da fila normalmente
    antes->prox = elem;
    elem->prox = aux;
    return h;
}

Fila *remover(Fila *h) //função para remover o elemento da fila
{
    Fila *aux;
    aux = h;

    if(h == NULL) //se a cabeça for nula retorna NULL
    return h;
    else //atualiza a cabeça e retira o primeiro elemento
    {
        h = aux->prox;
        free(aux);
        return h;
    }
}

Fila *alocar(int identificacao, int instante, int atendimento) //função que aloca memória
{
    Fila *aux;

    aux = malloc(sizeof(Fila));
    aux->I = identificacao;
    aux->O = instante;
    aux->C = atendimento;
    aux->prox = NULL;

    return aux;
}

int adiantar() //função que adianta o tempo caso todos os centros de atendimento estiverem ocupados, verifica qual será desocupado primeiro
{
    int i, menor = cargas[0], disp;

    for(i=0; i<tam; i++)
    {
        if(cargas[i] < menor)
        {
            menor = cargas[i];
            disp = i;
        }
    }
    return disp; //retorna o índice da posição que ficará disponível primeiro
}

int disponivel() //função que verifica se tem algum centro disponível
{
    int i, menor = cargas[0], ind = 0, count = 0;

    for(i=0; i<tam; i++)
    {
        if(stt[i]==0)
        count++;
    }

    if(count == 0) //não tem nenhum centro disponível
    return -1;
    else if(count == 1) //tem somente um centro disponível, retorna o índice dele
    {
        for(i=0; i<tam;i++)
        {
            if(stt[i] == 0)
            ind = i;
        }
        return ind;
    }
    else //tem mais de um centro disponível, verifica quem está disponível a mais tempo
    {
        for(i=0; i<tam; i++)
        {
            if(stt[i] == 0)
            {
                if(cargas[i] < menor)
                {
                    menor = cargas[i];
                    ind = i;
                }
            }
        }
        return ind;
    }
}


void att() //função que atualiza os status dos centros de atendimento, verifica se o atendimento já foi finalizado
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(tempo > cargas[i])
        {
          stt[i] = 0;
        }
    }
    return;
}

void atendimento(Fila *h) //função que realiza o atendimento
{
    Fila *head;
    int i = 0, j;

    head = h;
    while(head != NULL) //laço que vai ser percorrido até que não sobre nenhum elemento
    {
        tempo = head->O; //atualizo a variável tempo, com o instante de chegada na fila de cada elemento
        att(); //atualizo os status dos centros de atendimento
        
        i = disponivel(); //verifico se tem algum disponível
        if(i == -1) //nenhum centro disponível
        {
            j = adiantar(); //adianto o tempo 
            if(head->O > cargas[j]) //incrementa o vetor de cargas
            cargas[j] = head->O + head->C;
            else
            cargas[j] = cargas[j] + head->C;
        
            head = remover(head); //remove o elemento que já foi atendido

        }
        else //tem algum centro disponível
        {
            stt[i] = 1; //muda o estado dele para ocupado
            if(head->O > cargas[i]) //incrementa o vetor de cargas
            cargas[i] = head->O + head->C;
            else
            cargas[i] = cargas[i] + head->C;
         
            head = remover(head); //remove o elemento que já foi atendido
        }
    }

    for(i=0; i<tam; i++) //printa o vetor de cargas
    {
        printf("%d ", cargas[i]);
    }
}


