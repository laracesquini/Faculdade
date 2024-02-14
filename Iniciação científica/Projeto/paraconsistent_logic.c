#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define linhas 30
#define colunas 7

void imprimir_matriz(double **matriz);
double modulo(double num);
double **ler_dados(char *nome);
void normaliza_matriz(double **matriz);
double *calculo_vetor_similaridade(double **matriz);
void calculo_vetor_alcance(double **matriz, double *maior, double *menor);
double media(double *vet);
double overlap(double **classe1, double **classe2, double *maiores_valores_1, double *menores_valores_1, double *maiores_valores_2, double *menores_valores_2);

int main()
{   
    double **classe_patologicas, **classe_nao_patologicas; //declaração de matrizes
    double *vetor_similaridade_1, *vetor_similaridade_2, *menores_valores_1, *maiores_valores_1, *menores_valores_2, *maiores_valores_2; //declaração de vetores
    double alpha, aux, R; //declaração de variáveis

    //leitura dos dados
    classe_patologicas = ler_dados("caracteristicas_patologicas.txt");
    classe_nao_patologicas = ler_dados("caracteristicas_nao_patologicas.txt");

    //normalização dos vetores de características
    normaliza_matriz(classe_patologicas);
    normaliza_matriz(classe_nao_patologicas);

    //intraclass analysis
    //cálculo do vetor de similaridade para cada classe
    vetor_similaridade_1 = calculo_vetor_similaridade(classe_patologicas);
    vetor_similaridade_2 = calculo_vetor_similaridade(classe_nao_patologicas);

    //cálculo do alpha
    alpha = media(vetor_similaridade_1);
    aux = media(vetor_similaridade_2);

    if(alpha > aux)
    alpha = aux;
    
    //interclass analysis
    //cálculo dos vetores de alcance
    menores_valores_1 = (double*)malloc(colunas * sizeof(double));
    menores_valores_2 = (double*)malloc(colunas * sizeof(double));
    maiores_valores_1 = (double*)malloc(colunas * sizeof(double));
    maiores_valores_2 = (double*)malloc(colunas * sizeof(double));

    calculo_vetor_alcance(classe_patologicas, &maiores_valores_1[0], &menores_valores_1[0]);
    calculo_vetor_alcance(classe_nao_patologicas, &maiores_valores_2[0], &menores_valores_2[0]);
    printf("\nClasse 1\nSimilaridade: ");
    for(int i = 0; i < colunas; i++)
    printf("%.5f, ", vetor_similaridade_1[i]);

    printf("\nMaiores");
    for(int i = 0; i < colunas; i++)
    printf("%.5f, ", maiores_valores_1[i]);

    printf("\nMenores: ");
    for(int i = 0; i < colunas; i++)
    printf("%.5f, ", menores_valores_1[i]);

    //cálculo do R
    R = overlap(classe_patologicas, classe_nao_patologicas, maiores_valores_1, menores_valores_1, maiores_valores_2, menores_valores_2);

    printf("R: %f", R);
}

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
    int i, j;
    double maior_valor, menor_valor;

    for(j = 0; j < colunas; j++)
    {
        maior_valor = 0;
        menor_valor = 1;
        for(i = 0; i < linhas; i++)
        {
            if(matriz[i][j] > maior_valor)
            maior_valor = matriz[i][j];

            if(matriz[i][j] < menor_valor)
            menor_valor = matriz[i][j];
        }
        maior[j] = maior_valor;
        menor[j] = menor_valor;
    }

    return;  
}

double media(double *vet)
{
    int i;
    double media = 0;

    for(i = 0; i < colunas; i++)
    {
        media = media + vet[i];
    }

    media = media/colunas;

    return media;
}

double overlap(double **classe1, double **classe2, double *maiores_valores_1, double *menores_valores_1, double *maiores_valores_2, double *menores_valores_2)
{
    double R = 0;
    int i, j;

    for(j = 0; j < colunas; j++)
    {
        for(i = 0; i < linhas; i++)
        {
            if(((classe1[i][j] <= maiores_valores_2[j]) && (classe1[i][j] >= menores_valores_2[j])))
            R++;
        }
    }

    for(j = 0; j < colunas; j++)
    {
        for(i = 0; i < linhas; i++)
        {
            if(((classe2[i][j] <= maiores_valores_1[j]) && (classe2[i][j] >= menores_valores_1[j])))
            R++;
        }
    }

    return R;
}