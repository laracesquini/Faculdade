#include <stdio.h>
#include <stdlib.h>

void vogais(FILE *fp);

int main()
{
    FILE *fp;
    char arquivos[20];

    do
    {
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivos);
        fp = fopen(arquivos, "r");
        if(fp == NULL)
        printf("Erro ao abrir o arquivo, tente novamente!\n");
    } while (fp == NULL);

    vogais(fp);

    fclose(fp);
}

void vogais(FILE *fp)
{
    FILE *arq;
    char c;

    arq = fopen("escrita.txt", "w");

    while(!feof(fp))
    {
        c = fgetc(fp);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        fprintf(arq, "%c", '*');
        else if(c != EOF)
        fprintf(arq, "%c", c);
    }

    fclose(arq);
}