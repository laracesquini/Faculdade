#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double modulo(double num)
{
        if(num > 0)
        return num;
        else
        return (-num);
}

double media(double *F0i, int tam)
{
        int i;
        double media, soma = 0.0;

        for(i = 0; i < 400; i++)
        soma = soma + F0i[i];
        
        media = soma/(double)tam;

        return media;
}

//obtenção da média geométrica do sinal, considerando o F0i
double media_geometrica(double *F0i, int tam)
{
        int i;
        double soma = 0.0, media_g;

        for(i = 0; i < tam; i++)
        soma = soma + log(F0i[i]);
        
        soma = soma/tam;
        media_g = exp(soma);

        return media_g;
}

//obtenção do RMS(Root Mean Squared) do sinal, considerando o F0i
double RMS(double *F0i, int tam)
{
        int i;
        double soma = 0, media, rms;

        for(i = 0; i < tam; i++)
        soma = soma + pow(F0i[i], 2);

        media = soma/tam;
        rms = sqrt(media);

        return rms;     
}

//obtenção da dispersão do sinal, considerando o F0i
double dispersao(double *F0i, int tam, double media)
{
        int i;
        double dispersao, soma = 0;

        for(i = 0; i < tam; i++)
        soma = soma + pow((F0i[i] - media), 2);
        
        dispersao = soma/(tam-1);
        dispersao = sqrt(dispersao);

        return dispersao;
}

//obtenção do percentual de variabilidade do sinal, considerando o F0i
double percentual_variabilidade(double *F0i, int tam, double media)
{
        int i;
        double soma = 0, pv;

        for(i = 0; i < tam; i++)
        soma = soma + modulo((F0i[i] - media));
        
        pv = soma/tam;
        pv = pv/media;

        return pv;
}

//obtenção do coeficiente de consitência do sinal, considerando o F0i
double coeficiente_consistencia(double *F0i, int tam, double media)
{
        int i;
        double soma = 0, cc;

        for(i = 0; i < tam; i++)
        soma = soma + modulo((F0i[i] - media));
        
        cc = soma/tam;
        cc = media/cc;

        return cc;
}

int main()
{
    FILE *fp;
    char aux[100000], *token, aux2[10];
    int tam_F0i;
    

    fp = fopen("F0i.txt", "r");

    fscanf(fp, "%s", aux2);
    tam_F0i = atoi(aux2);
    printf("aux: %s", aux2);
    double F0i[tam_F0i];
    fscanf(fp, "%s", aux);
    token = strtok(aux, ",");
    for(int j = 0; j < tam_F0i; j++)
    {
        F0i[j] = strtod(token, NULL);
        token = strtok(NULL, ",");
    }

    fclose(fp);
    
    double c[7];

    c[0] = media(F0i, tam_F0i);
    c[1] = media_geometrica(F0i, tam_F0i);
    c[2] = RMS(F0i, tam_F0i);
    c[3] = dispersao(F0i, tam_F0i, c[0]);
    c[4] = c[3]/c[0]; //obtenção do coeficiente de variação
    c[5] = percentual_variabilidade(F0i, tam_F0i, c[0]);
    c[6] = coeficiente_consistencia(F0i, tam_F0i, c[0]);
    
    fp = fopen("patologicas.txt", "a+");
    for(int i = 0; i< 7; i++)
    {
        fprintf(fp, "%.5f,", c[i]);
    }
    fputs("\n", fp);
    fclose(fp);
    
    return 0;
}