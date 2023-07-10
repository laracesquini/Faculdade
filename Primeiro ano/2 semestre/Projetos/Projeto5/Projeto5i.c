#include <stdio.h>
#include <time.h>

typedef struct biggo //declaração da estrutura do tipo BigInt
{
    int high;
    int low;
}BigInt;

void insertion(BigInt *vet, int n);

int main()
{
    BigInt vet[200000], aux;
    FILE *fp, *fq;
    clock_t tempo; //usado para a contagem do tempo
    int i;

    fp = fopen("bigint.dat", "r"); //abrindo os arquivos utilizados
    fq = fopen("quick.dat", "w");

    for(i=0; i<200000; i++) //lendo os números do arquivo e salvando em um vetor
    {
        fscanf(fp, "%d %d", &vet[i].high, &vet[i].low);
    }

    tempo = clock(); //iniciando a contagem do tempo
    insertion(vet, 200000); 
    tempo = clock() - tempo;
    double time = ((double)tempo)/CLOCKS_PER_SEC;
    printf("%f", time); //printa o tempo que demorou para realizar a ordenação
    
    for(i=0; i<200000; i++) //printa o vetor ordenado no novo arquivo
    {
        fprintf(fq, "%d %d\n", vet[i].high, vet[i].low);
    }
}

void insertion(BigInt *vet, int n) //função de ordenação do tipo inserção
{
    int i, j, k;
    BigInt aux;

    for(i=1; i<n; i++) //laço que percorre o vetor 
    {
        aux = vet[i]; //variavel auxiliar recebe o valor da posição i
        j = i; 
        while(j>0 && vet[j-1].high > aux.high) //enquanto j for maior que zero e o elemento da posição j-1 for maior que o elemento da posição i(aux), troca o elemento da posição j com o elemento da posição j-1 e decrementa j
        {
            vet[j] = vet[j-1];
            j--;
        }
        if(vet[j-1].high == aux.high) //se a primeira parte do número for igual, ordenar levando em consideração a segunda parte
        {
            k = j;
            if(vet[j-1].high >= 0) //se a primeria parte for positiva, ordena crescentemente
            {
                while(k>0 && vet[k-1].high == aux.high && vet[k-1].low > aux.low)
                {
                    vet[k] = vet[k-1];
                    k--;
                }
                vet[k] = aux;
            }
            else //se for negativa, ordena a segunda parte de forma decrescente
            {
                while(k>0 && vet[k-1].high == aux.high && vet[k-1].low < aux.low)
                {
                    vet[k] = vet[k-1];
                    k--;
                }
                vet[k] = aux;
            }

        }
        else
        vet[j] = aux;
    }
}