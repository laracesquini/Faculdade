#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define linhas 30
#define colunas 7

void imprimir_matriz(double **matriz)
{
    int i, j;

    for(i =0 ; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%.5f ", matriz[i][j]);
        }
        printf("\n");
    }

    return;
}

double modulo(double num)
{
        if(num > 0)
        return num;
        else
        return (-num);
}

double **ler_dados(char *nome)
{
    FILE *fp;
    int i, j;
    char aux[100], *token;
    double **matriz;

    matriz = (double**)malloc(linhas * sizeof(double*));

    for(i = 0; i < linhas; i++)
    {
        matriz[i] = (double*)malloc(colunas * sizeof(double));
    }

    fp = fopen(nome, "r");
    for(i = 0; i < linhas; i++)
    {
        fscanf(fp, "%s", aux);
        token = strtok(aux, ",");
        for(j = 0; j < colunas; j++)
        {
            matriz[i][j] = strtod(token, NULL);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return matriz;
}

void normaliza_matriz(double **matriz)
{
    int i, j;
    double maior;

    for(i = 0; i < linhas; i++)
    {
        maior = modulo(matriz[i][0]);
        for(j = 0; j < colunas; j++)
        {
            if(modulo(matriz[i][j]) > maior)
            maior = modulo(matriz[i][j]);
        }

        for(j = 0; j < colunas; j++)
        {
            matriz[i][j] = matriz[i][j]/maior;
        }
    }

    return;
}

int main()
{
    double **classe_patologicas, **classe_nao_patologicas;
    classe_patologicas = ler_dados("caracteristicas_patologicas.txt");
    classe_nao_patologicas = ler_dados("caracteristicas_nao_patologicas.txt");

    normaliza_matriz(classe_nao_patologicas);
    imprimir_matriz(classe_nao_patologicas);
}