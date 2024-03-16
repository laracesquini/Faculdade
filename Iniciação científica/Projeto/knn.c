#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define num_caracteristicas 4
#define tam_conjunto 10

double distancia_euclidiana(double *v1, double *v2);
int KNN(double **matriz, int *binario, double *teste);
void validacao_cruzada(double **matriz);
int *converter_decimal_binario(long num);
int verifica_binario(int tam, int *binario);

int main()
{
    //primeiras 5 linhas é 0 (não patológica) e o resto é 1 (patológica)
    double dados[tam_conjunto][num_caracteristicas] = {
                    {142.71503,746.34085,4.40683,3.46999},
                    {168.56885,429.95539,1.84080,1.06057},
                    {171.65993,840.52738,3.98946,3.53424},
                    {169.54020,659.52995,3.15951,2.07910},
                    {124.23503,291.65270,1.51780,1.10508},
                    {378.68758,725.68889,1.29264,0.93640},
                    {247.92413,409.44490,1.01512,0.35161},
                    {293.23062,557.98766,1.29039,0.79120},
                    {241.25535,589.95850,1.69613,1.21203},
                    {245.47455,650.88646,1.73610,1.56406}
                    };

}

double distancia_euclidiana(double *v1, double *v2)
{
    double dist = 0.0;
    int i;

    for(i = 0; i < num_caracteristicas; i++)
    {
        dist = dist + pow((v1[i] - v2[i]), 2);
    }

    dist = sqrt(dist);

    return dist;
}

int KNN(double **matriz, int *binario, double *teste)
{
    double menor_dist = INFINITY, aux;
    int classe_menor_dist = -1, i;

    //1 - treino, 0 - teste
    for(i = 0; i < tam_conjunto; i++) 
    {
        if(binario[i] == 1)
        {
            aux = distancia_euclidiana(matriz[i], teste);

            if(aux < menor_dist)
            {
                menor_dist = aux;
                if(i < tam_conjunto/2)
                classe_menor_dist = 0;
                else
                classe_menor_dist = 1; 
            }
        }
    }

    return classe_menor_dist;
}

void validacao_cruzada(double **matriz)
{
    long i, j;
    int *binario, **combinacoes, num_combinacoes = 0;

    combinacoes = (int **)malloc(tam_conjunto * sizeof(int *));
    for(i = pow(2, (tam_conjunto/2)) - 1; i < pow(2, tam_conjunto); i++)
    {
        binario = converter_decimal_binario(i);
        if(verifica_binario(tam_conjunto, binario) == 1)
        {   
            combinacoes[num_combinacoes] = (int *)malloc(tam_conjunto * sizeof(int));
            for (j = 0; j < tam_conjunto; j++) 
            combinacoes[num_combinacoes][j] = binario[j];

            num_combinacoes++;
        }
    }

    for(j = 0; j < tam_conjunto; j++)
    {

    }
}

int *converter_decimal_binario(long num)
{
    int num;
    num = tam_conjunto;
    int *binario, i = 0;

    binario = (int *)malloc(num*sizeof(int));

    for(int j = 0; j < num; j++)
    {
        binario[j] = 0;
    }
    
    while(num > 0)
    {
        binario[i] = num%2;
        num = num/2;
        i++;
    }

    return binario;
}

int verifica_binario(int tam, int *binario)
{
    int count1 = 0, count0 = 0, i;

    for(i = 0; i < tam; i++)
    {
        if(binario[i] == 1)
        count1++;
        else
        count0++;
    }

    if(count0 == count1)
    return 1;
    else
    return 0;
}

