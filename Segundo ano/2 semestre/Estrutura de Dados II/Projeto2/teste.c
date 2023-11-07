#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ordem 6

int main()
{
    int chaves[ordem];
    int temp1[ordem];
    int chave = 32;

    int tam = sizeof(temp1)/4;

    printf("Antes:");
    for(int i = 0; i<ordem; i++)
    {
        chaves[i] = ordem*i;
        printf("%d ", chaves[i]);
    }
    printf("\n");

    for(int i = 0; i<ordem; i++)
    {
        temp1[i] = chaves[i];
    }
    //printf("Temp: %d\n", sizeof(temp1));

    for(int i = 0; i <= (tam-1); i++)
        {
            if(chave == temp1[i])
            {
                printf("Essa chave já existe, nãi é possível realizar a inserção\n");
                break;
            }
            else if(chave < temp1[i]) 
            {
                printf("Chega aqui: %d\nChave: %d, Temp: %d", i, chave, temp1[i]);
                chaves[i] = chave;
                for(int j = i+1; j < tam; j++)
                {
                    //printf("Chega aqui2\n");
                    chaves[j] = temp1[j-1];
                }
                break;
            }
            else if(i + 1 == tam)
            {
                chaves[i] = chave;
                break;
            }
        }

    printf("Depois:");
    for(int i = 0; i<ordem; i++)
    {
        printf("%d ", chaves[i]);
    }
    printf("\n");
}
