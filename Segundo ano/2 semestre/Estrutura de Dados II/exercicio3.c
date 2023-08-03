#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int verifica(FILE *fp);

int main()
{
    FILE *fp;
    char arquivo[20];
    int vogais;

    do
    {
        //pedir para o usuário o nome do arquivo
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);

        fp = fopen(arquivo, "r");
        //verificar se o arquivo existe 
        if(fp == NULL)
        printf("Erro ao abrir o arquivo, tente novamente!");
    } while (fp == NULL);
    
    //chamar a função que vai contar as vogais
    vogais = verifica(fp);

    printf("Esse arquivo tem %d vogais", vogais);

    fclose(fp);

}

int verifica(FILE *fp)
{
    char c;
    int count = 0;

    //percorrer o arquivo até o final
    while(!feof(fp))
    {
        //ler os caracteres e transformar todos em minúsculos
        c = fgetc(fp);
        c = tolower(c);

        //verifica se é uma vogal
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        count++;
    }

    //retorna a quantidade de vogais
    return count;
}