#include <stdio.h>
#include <time.h>

typedef struct biggo //declaração da estrutura do tipo BigInt
{
    int high;
    int low;
}BigInt;

int mediana(BigInt *vet, int lo, int mid, int hi); //função que calcula a mediana de 3
void quicksort(BigInt *vet, int low, int hi);

int main()
{
    BigInt vet[200000], aux;
    FILE *fp, *fq;
    clock_t tempo;
    int i;

    fp = fopen("bigint.dat", "r"); //abrindo os arquivos
    fq = fopen("quick.dat", "w");

    for(i=0; i<200000; i++) //lendo o arquivo e salvando os números em um vetor
    {
        fscanf(fp, "%d %d", &vet[i].high, &vet[i].low);
    }

    tempo = clock();
    quicksort(vet, 0, 199999);
    tempo = clock() - tempo;
    double time = ((double)tempo)/CLOCKS_PER_SEC;
    printf("%f", time); //printa o tempo que demorou para realizar a ordenação
    
    for(i=0; i<200000; i++) //printa o vetor ordenado no novo arquivo
    {
        fprintf(fq, "%d %d\n", vet[i].high, vet[i].low);
    }
}

int mediana(BigInt *vet, int lo, int mid, int hi) //função que vê qual é a mediana entre 3 números
{
    if((vet[lo].high > vet[hi].high && vet[lo].high < vet[mid].high) || (vet[lo].high < vet[hi].high && vet[lo].high > vet[mid].high))
    return lo;
    if((vet[hi].high > vet[lo].high && vet[hi].high < vet[mid].high) || (vet[hi].high < vet[lo].high && vet[hi].high > vet[mid].high))
    return hi;
    else
    return mid;
}

void quicksort(BigInt *vet, int lo, int hi)
{
    int i, pivo, bigger;
    BigInt aux;

    if(lo < hi)
    {
        pivo = mediana(vet, lo, (lo+hi)/2, hi); //pivo a mediana de 3
        aux = vet[pivo]; //coloca o pivo na última posição
        vet[pivo] = vet[hi];
        vet[hi] = aux;
        bigger = lo; //bigger começa na primeira posição
        for(i = bigger; i<hi; i++)
        {
            if(vet[i].high < vet[hi].high) //se o elemento da posição i for menor que o pivo, troca ele com o elemento da posição bigger
            {
                aux = vet[i];
                vet[i] = vet[bigger];
                vet[bigger] = aux;
                bigger++; //incrementa bigger
            }
            else if(vet[i].high == vet[hi].high) //se a primeira parte do número for igual, ordena usando a segunda parte
            {
                if(vet[i].high < 0) //se a primeira parte do número for negativa, ordena de forma decrescente
                {
                    if(vet[i].low > vet[hi].low)
                    {
                        aux = vet[i];
                        vet[i] = vet[bigger];
                        vet[bigger] = aux;
                        bigger++;
                    }
                }
                else //se for positiva, ordena crescentemente
                {
                    if(vet[i].low < vet[hi].low)
                    {
                        aux = vet[i];
                        vet[i] = vet[bigger];
                        vet[bigger] = aux;
                        bigger++;
                    }
                }
            }
        }
        aux = vet[bigger]; //coloca o pivo no lugar certo(vai ser onde bigger está)
        vet[bigger] = vet[hi];
        vet[hi]= aux;
        quicksort(vet, lo, bigger-1); //chama a função recursivamente para a primeira parte do vetor
        quicksort(vet, bigger+1, hi); //chama a função recursivamente para a segunda parte do vetor
    }
}