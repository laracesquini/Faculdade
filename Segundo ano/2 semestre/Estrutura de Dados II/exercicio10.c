#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    FILE *fp, *write;
    int i = 0, j;
    typedef struct dados{
        char nome[40];
        float num_habitantes;
    }Tdados;

    Tdados cidades[MAX];
    Tdados maior;

    fp = fopen("arq.txt", "r");
    write = fopen("escrita.txt", "w");

    while(!feof(fp))
    {
        fscanf(fp, " %s", cidades[i].nome);
        fscanf(fp, " %f", &cidades[i].num_habitantes);

        i++;
    }
    
    maior = cidades[0];

    for(j = 0; j<i; j++)
    {
        if(cidades[j].num_habitantes > maior.num_habitantes)
        {
            maior = cidades[j];
        }
        
    }

    fprintf(write, "%s ", maior.nome);
    fprintf(write, "%.0f", maior.num_habitantes);

    fclose(fp);
    fclose(write);
}