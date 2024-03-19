#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define num_caracteristicas 4
#define tam_conjunto 20

double distancia_euclidiana(double *v1, double *v2);
int KNN(double matriz[tam_conjunto][num_caracteristicas], int *binario, double *teste);
void validacao_cruzada(double matriz[tam_conjunto][num_caracteristicas]);
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
                    {108.72435,285.29126,1.79429,1.33462},
                    {202.80963,851.54210,3.30822,2.84617},
                    {175.90667,686.14636,3.03292,2.51132},
                    {157.22425,971.25849,5.18112,5.16438},
                    {148.67413,487.66803,2.43836,1.90917},
                    {378.68758,725.68889,1.29264,0.93640},
                    {247.92413,409.44490,1.01512,0.35161},
                    {293.23062,557.98766,1.29039,0.79120},
                    {241.25535,589.95850,1.69613,1.21203},
                    {245.47455,650.88646,1.73610,1.56406},
                    {349.69553,495.25630,1.00427,0.83565},
                    {670.80700,818.62224,0.70081,0.60866},
                    {207.77998,305.68711,1.08099,0.66202},
                    {420.96427,562.11057,0.88626,0.82876},
                    {724.52946,861.88543,0.64463,0.61750},
                    };
    
    validacao_cruzada(dados);
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

int KNN(double matriz[tam_conjunto][num_caracteristicas], int *binario, double *teste)
{
    double menor_dist = INFINITY, aux;
    int classe_menor_dist = -1, i;

    /*printf("Combinação: ");
    for(int k = 0; k < tam_conjunto; k++)
    {
        printf("%d ", binario[k]);
    }

    printf("Linha da matriz: ");
    for(int k = 0; k < num_caracteristicas; k++)
    {
        printf("%lf ", teste[k]);
    }

    printf("\n");*/
    //1 - treino, 0 - teste
    for(i = 0; i < tam_conjunto; i++) 
    {
        if(binario[i] == 1)
        {
            aux = distancia_euclidiana(matriz[i], teste);
            //printf("dist: %fl\n", aux);

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

void validacao_cruzada(double matriz[tam_conjunto][num_caracteristicas])
{
    long i, j;
    double VP, VN, FP, FN;
    int *binario, **combinacoes, num_combinacoes = 0, resultado;
    
    VP = VN = FP = FN = 0.0;

    combinacoes = (int **)malloc(tam_conjunto * sizeof(int *));
    for(i = pow(2, (tam_conjunto/2)) - 1; i < pow(2, tam_conjunto); i++)
    {
        printf("percent: %f\n", (i*100)/pow(2, tam_conjunto));
        binario = converter_decimal_binario(i);
        if(verifica_binario(tam_conjunto, binario) == 1)
        {   
            for(j = 0; j < tam_conjunto; j++)
            {
                if(binario[j] == 0)
                {
                    resultado = KNN(matriz, binario, matriz[j]);
                    if(resultado == 0)
                    {
                        if(j < tam_conjunto/2)
                        VN++;
                        else
                        FN++;
                    }
                    else
                    {
                        if(j > tam_conjunto/2)
                        VP++;
                        else
                        FP++;
                    }
                }
            }
        }  
    }

    printf("Resultados: ");
    printf("Acurácia: %lf\nPrecisão: %lf\nSensibilidade: %lf\nEspecificidade: %lf\n", (double)((VP+VN)/(VP+VN+FP+FN)), (double)(VP/(VP+FP)), (double)(VP/(VP+FN)), (double)(VN/(VN+FP)));
    printf("VP: %lf\nVN: %lf\nFP: %lf\nFN: %lf\n", VP, VN, FP, FN);
}

int *converter_decimal_binario(long num)
{
    int *binario, i, n = 0, j, m;

    binario = (int *)malloc(tam_conjunto*sizeof(int));

    while(num >= pow(2, n))
    {
        n++;
    }

    m = tam_conjunto - n;

    for(i = 0; i < m; i++)
    {
        binario[i] = 0;
    }
    
    for(j = (tam_conjunto - 1); j >= m; j--)
    {
        binario[j] = num%2;
        num = num/2;
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

