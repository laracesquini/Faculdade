#include <stdio.h>
#include <stdlib.h>

int *maior_comb; //declaração do vetor que vai armazenar a maior combinação e de variáveis que serão utilizadas
int tam_vet=0;
int maior_elem = 0, count = 0;

void juntar(int *v, int num) //função que vai adicionar um elemento à combinação
{
    int i=0;
    while(v[i]!=0)
    i++;
    v[i] = num;
}

void remover(int *v) //função que remove o último elemento para não se repetir
{
    int i=0;
    while(v[i]!=0)
    i++;
    v[i-1] = 0;
}

void att(int *v) //função que atualiza o vetor de maior combinação
{
    int i=0;

    while(v[i]!=0)
    {
        maior_comb[i] = v[i];
        i++;
    }
}

void inicializar(int *v, int tam) //função que iniciliza os vetores
{
    int i = 0;

    for(i=0; i<tam; i++)
    v[i] = 0;
}

void backtrack(int *v, int *comb_atual, int i, int n, int quant, int tam, int maior_num)
{
    int j = i, prev; 

    if(n==0) //se o número deu 0, encontrei uma combinação desejada
    {
        if(tam > tam_vet || (tam == tam_vet && maior_num > maior_elem)) //verifica se a combinação encontrada é maior que a maior combinação
        {
            att(comb_atual); //atualizo o vetor de maior combinações
            tam_vet = tam; //atualizo o tamanho do vetor de maior combinação
            maior_elem = maior_num; //atualizo o maior elemento
        }
        count++; //conta a quantidade de combinações
        tam = 0;
        maior_num = 0;
    }
    else if(n<=0) //se o valor for menor do que 0, a decomposição feita não é a desejada.
    {
        return;
    }
    //se o número for maior do que 0, é chamada a recursão até que a soma encontrada dê 0 ou menos

    prev = -1; //inicializar essa variável como um número negativo, que não estará presente nos números utilizados para a decomposição. Para garantir que o primeiro teste dê falso, uma vez que o primeiro elemento não é repitido.
    while(j!=quant) //laço que percorre o vetor de números utilizados na combinação
    {
        if(v[j]==prev) //se o elemento anterior for igual ao atual, pular ele, ir para o próximo elemento. Garante que não se repita combinações
        continue;

        if(v[j]>maior_num) //se o elemento atual for maior que o maior número, atualiza a posição de maior número
        maior_num = v[j];

        juntar(comb_atual, v[j]); //juntar o novo elemento na combinação atual
        backtrack(v, comb_atual, j+1, n-v[j], quant, tam+1, maior_num); //chamar a função novamente, mas agora para o elemento do índice seguinte(j+1), o número que será decomposto menos o elemento atual(n-v[j]) e atualiza o tamanho do vetor de combinação atual (tam+1) 
        remover(comb_atual); //remove o último elemento para não repetir
        prev = v[j];
        j++;
    }
}


int main()
{
    int i, j, aux, m, N, *v, *comb_atual, *num;

    scanf("%d", &N);
    scanf("%d", &m);

    v = malloc(m*sizeof(int)); //vetor de números que serão usados na decomposição
    comb_atual = malloc(m*sizeof(int)); //vetor auxiliar que vai guardar a combinação atual
    num = malloc(N*sizeof(int)); //vetor dos números que serão decompostos
    maior_comb = malloc(m*sizeof(int)); //vetor que armazena a maior combinação

    for(i=0; i<m; i++) //preenchendo o vetor de números usados na decomposição
    {
        scanf("%d", &v[i]);
    }

    for(i=0; i<N; i++) //preenchendo o vetor de números que serão decompostos
    {
        scanf("%d", &num[i]);
    }

    for(i=0; i<m; i++) //ordenando o vetor de números que serão decompostos, caso ainda não esteja ordenado
    {
        for(j=i+1; j<m; j++)
        {
            if(v[i]>v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    j=0; //inicializar a variável, pois ela será usada no for seguinte novamente

    for(i=0; i<N; i++) //esse for vai percorrer o vetor de números que serão decompostos e realizar a decomposição de cada um
    {
        inicializar(maior_comb, m); //inicializar o vetor auxiliar e o vetor de maior combinação, todas as posições recebem 0.
        inicializar(comb_atual, m);
        backtrack(v, comb_atual, 0, num[i], m, 0, 0); //função que decompõe o vetor e conta o número de combinações
        printf("%d ", count);//imprime o número de combinações
        while(maior_comb[j]!=0) //while que percorre o vetor da maior combinação e imprime ela
        {
            printf("%d ", maior_comb[j]);
            j++;
        }
        printf("\n"); //pular para a linha seguinte
        j=0; //inicializar as variáveis que serão utilizadas como 0 para o cálculo da decomposição do próximo número
        count = 0;
        tam_vet = 0;
        maior_elem = 0;
    }
}

