#include <stdio.h>
#include <stdlib.h>

void juntar(FILE *fp, FILE *arq);

int main()
{
    FILE *fp, *arq;
    char arquivo[20];

    do
    {
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);
        fp = fopen(arquivo, "r");
        printf("Digite o nome e extenção do outro arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);
        arq = fopen(arquivo, "r");
        if(fp == NULL || arq == NULL)
        printf("Erro ao abrir o arquivo, tente novamente!\n");
    } while (fp == NULL || arq == NULL);

    juntar(fp, arq);

    fclose(fp);
    fclose(arq);
}

void juntar(FILE *fp, FILE *arq)
{
    FILE *write;
    char c;

    write = fopen("escrita.txt", "w");

    while(!feof(fp))
    {
        c = fgetc(fp);

        if(c != EOF)
        fprintf(write, "%c", c);
    }

    while(!feof(arq))
    {
        c = fgetc(arq);

        if(c != EOF)
        fprintf(write, "%c", c);
    }

    fclose(write);
}