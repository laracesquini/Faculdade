#include <stdio.h>
#include <math.h>
#define num_caracteristicas 4

typedef struct vetor_caracteristicas
{
    double caracteristicas[num_caracteristicas];
    int classe;
}VCs;

double distancia_euclidiana(VCs *v1, VCs *v2);

int main()
{
    //0 é não patológica e 1 é patológica
    VCs dados[10] = {
                    {{142.71503,746.34085,4.40683,3.46999}, 0},
                    {{168.56885,429.95539,1.84080,1.06057}, 0},
                    {{171.65993,840.52738,3.98946,3.53424}, 0},
                    {{169.54020,659.52995,3.15951,2.07910}, 0},
                    {{124.23503,291.65270,1.51780,1.10508}, 0},
                    {{378.68758,725.68889,1.29264,0.93640}, 1},
                    {{247.92413,409.44490,1.01512,0.35161}, 1},
                    {{293.23062,557.98766,1.29039,0.79120}, 1},
                    {{241.25535,589.95850,1.69613,1.21203}, 1},
                    {{245.47455,650.88646,1.73610,1.56406}, 1}
                    };

}

double distancia_euclidiana(VCs *v1, VCs *v2)
{
    double dist = 0.0;
    int i;

    for(i = 0; i < num_caracteristicas; i++)
    {
        dist = dist + pow((v1->caracteristicas[i] - v2->caracteristicas[i]), 2);
    }

    dist = sqrt(dist);

    return dist;
}