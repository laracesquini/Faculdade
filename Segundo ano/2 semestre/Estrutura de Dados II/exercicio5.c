#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int contar(FILE *fp, char c);

int main()
{
    FILE *fp;
    char arquivo[20];
    char c;
    int count;

    do
    {
        //pedir para o usuário o nome do arquivo e um caractere
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);
        printf("Digite um caracter: ");
        scanf(" %c", &c);

        fp = fopen(arquivo, "r");
        //verificar se o arquivo existe
        if(fp == NULL)
        {
            printf("Erro ao abrir o arquivo, tente novamente!\n");
        }
    } while (fp == NULL);

    //chamar a função que conta quantas vezes aparece determinado caracter
    count = contar(fp, c);
    
    //printar o resultado
    printf("Nesse arquivo o caractere '%c' aparece %d vezes.", c, count);

    //fechar o arquivo
    fclose(fp);
}

int contar(FILE *fp, char c)
{
    int count = 0;

    //percorrer o rquivo até o final
    while(!feof(fp))
    {
        //transformar todos em caracteres lidos em minúsculo e comparar com o passado para a função
        if(tolower(fgetc(fp)) == c)
        count++;
    }
    return count;
}