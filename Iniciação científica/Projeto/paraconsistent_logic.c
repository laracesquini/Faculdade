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

double *calculo_vetor_similaridade(double **matriz)
{
    double *vetor, maior, menor;
    int i, j;

    vetor = (double*)malloc(colunas * sizeof(double)); 

    for(j = 0; j < colunas; j++)
    {
        maior = 0;
        menor = 1;
        for(i = 0; i < linhas; i++)
        {
            if(matriz[i][j] > maior)
            maior = matriz[i][j];

            if(matriz[i][j] < menor)
            menor = matriz[i][j];
        }
        vetor[j] = maior - menor;
    }

    for(j = 0; j < colunas; j++)
    {
        vetor[j] = 1 - vetor[j];
    }

    return vetor;
}

void calculo_vetor_alcance(double **matriz, double *maior, double *menor)
{

}
int main()
{
    double **classe_patologicas, **classe_nao_patologicas, *vetor_similaridade_1, *vetor_similaridade_2, *menores_valores_1, *maiores_valores_1, *menores_valores_2, *maiores_valores_2;

    classe_patologicas = ler_dados("caracteristicas_patologicas.txt");
    classe_nao_patologicas = ler_dados("caracteristicas_nao_patologicas.txt");

    normaliza_matriz(classe_patologicas);
    normaliza_matriz(classe_nao_patologicas);

    vetor_similaridade_1 = calculo_vetor_similaridade(classe_patologicas);
    vetor_similaridade_2 = calculo_vetor_similaridade(classe_nao_patologicas);

    //menores_valores_1 = menores_valores_2 = maiores_valores_1 = maiores_valores_2 = (double*)malloc(colunas * sizeof(double));

    
    
}