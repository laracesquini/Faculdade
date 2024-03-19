#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define num_caracteristicas 4
#define tam_conjunto 60

double distancia_euclidiana(double *v1, double *v2);
int KNN(double matriz[tam_conjunto][num_caracteristicas], int *binario, double *teste);
void validacao_cruzada(double matriz[tam_conjunto][num_caracteristicas]);
int *converter_decimal_binario(long long num);
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
                    {171.33008,815.56154,3.92454,3.13362},
                    {110.90256,315.93507,2.02403,1.51135},
                    {133.37908,541.76577,3.65429,1.08032},
                    {184.33605,636.51466,2.93082,1.17133},
                    {134.39626,358.28155,2.10304,0.84505},
                    {171.70140,393.89843,1.53741,0.95114},
                    {141.27826,641.61110,3.67246,3.07293},
                    {127.98303,408.02293,2.49224,1.47932},
                    {148.92739,918.02730,5.22315,4.86443},
                    {209.58041,718.72435,2.61698,1.95871},
                    {115.01182,273.07344,1.63068,0.99078},
                    {179.13689,600.32370,2.58322,1.78181},
                    {115.73403,320.54798,2.03237,1.27263},
                    {120.42392,425.67607,2.81103,1.80030},
                    {287.24801,660.34028,1.39902,1.18972},
                    {176.86336,645.04661,2.73889,2.40729},
                    {220.37557,512.97043,1.47157,1.27067},
                    {271.18826,569.28225,1.30070,1.12167},
                    {191.42454,703.97592,2.90817,2.13202},
                    {138.23118,675.49742,3.92784,3.73011},
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
                    {294.45437,426.42676,1.04861,0.82561},
                    {216.79522,216.92955,0.03525,0.02234},
                    {353.16543,469.98044,0.87844,0.53759},
                    {458.05234,571.63271,0.74780,0.69877},
                    {279.18081,357.83796,0.80245,0.30326},
                    {662.87179,769.70168,0.59041,0.53199},
                    {662.47510,764.79206,0.57709,0.51293},
                    {288.99161,484.34353,1.34633,0.65884},
                    {517.82695,598.81025,0.58099,0.52905},
                    {650.70413,669.98845,0.24541,0.15790},
                    {314.85828,385.67280,0.70883,0.61106},
                    {469.39250,578.83780,0.72216,0.65155},
                    {597.07000,729.85847,0.70329,0.65025},
                    {240.15025,247.86818,0.25574,0.02814},
                    {384.60070,735.40891,1.15780,1.04881},
                    {501.17660,561.84447,0.50698,0.46811},
                    {519.01218,544.44153,0.31705,0.21504},
                    {591.40714,688.87308,0.59750,0.54760},
                    {776.06221,867.27611,0.49915,0.42748},
                    {496.75483,607.55883,0.70456,0.65054},                  
                    };
    
    validacao_cruzada(dados);
    //int *aux = converter_decimal_binario(1);
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

    printf("Combinação: ");
    for(int k = 0; k < tam_conjunto; k++)
    {
        printf("%d ", binario[k]);
    }

    printf("Linha da matriz: ");
    for(int k = 0; k < num_caracteristicas; k++)
    {
        printf("%lf ", teste[k]);
    }

    printf("\n");
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
    long long i, j;
    double VP, VN, FP, FN;
    int *binario, **combinacoes, num_combinacoes = 0, resultado;
    
    VP = VN = FP = FN = 0.0;

    combinacoes = (int **)malloc(tam_conjunto * sizeof(int *));
    for(i = pow(2, (tam_conjunto/2)) - 1; i < pow(2, tam_conjunto); i++)
    {
        printf("percent: %f\n", (i*100)/pow(2, tam_conjunto));
        printf("%ld\n", i);
        binario = converter_decimal_binario(i);
        //for(int k = 0; k < tam_conjunto; k++)
        //printf("%d ", binario[k]);
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

int *converter_decimal_binario(long long num)
{
    int *binario, i, n = 0, j, m;

    binario = (int *)malloc(tam_conjunto*sizeof(int));

    while(num >= pow(2, n))
    {
        n++;
    }
    //printf("N: %d\n", n);
    m = tam_conjunto - n;

    for(i = 0; i < tam_conjunto; i++)
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
