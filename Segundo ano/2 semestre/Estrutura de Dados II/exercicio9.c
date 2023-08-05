#include <stdio.h>
#include <stdlib.h>

void juntar(FILE *fp, FILE *arq);

int main()
{
    FILE *fp, *arq;
    char arquivo[20];

    do
    {
        //pedir para o usuário o nome dos arquivos
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);
        fp = fopen(arquivo, "r");
        printf("Digite o nome e extenção do outro arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);
        arq = fopen(arquivo, "r");
        
        //verificar se os arquivos existem
        if(fp == NULL || arq == NULL)
        printf("Erro ao abrir o arquivo, tente novamente!\n");
    } while (fp == NULL || arq == NULL);

    juntar(fp, arq);

    //fechar os arquivos
    fclose(fp);
    fclose(arq);
}

void juntar(FILE *fp, FILE *arq)
{
    FILE *write;
    char c;

    //abrir arquivo para escrita
    write = fopen("escrita.txt", "w");

    while(!feof(fp))
    {
        //ler o arquivo até o final e escrever no arquivo para escrita
        c = fgetc(fp);

        if(c != EOF)
        fprintf(write, "%c", c);
    }

    while(!feof(arq))
    {
        //ler o arquivo até o final e escrever no arquivo para escrita
        c = fgetc(arq);

        if(c != EOF)
        fprintf(write, "%c", c);
    }

    //fechar o arquivo para escrita
    fclose(write);
}