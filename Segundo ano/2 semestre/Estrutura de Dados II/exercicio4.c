#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int contar(FILE *fp, int *count_letras);

//Considerando que seja um arquivo só de letras(para facilitar)
int main()
{
    FILE *fp;
    char arquivo[20];
    int vogais, *count_letras;

    //vai contar quantas letras tem, o que não for vogal, é consoante. Começa com -1 para desconsiderar o final do arquivo
    *count_letras = -1;

    do
    {
        //pedir para o usuário o nome do arquivo
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);

        fp = fopen(arquivo, "r");
        //verificar se o arquivo existe 
        if(fp == NULL)
        printf("Erro ao abrir o arquivo, tente novamente!\n");
    } while (fp == NULL);
    
    //chamar a função que vai contar as vogais e as consoantes
    vogais = contar(fp, count_letras);
    
    //printar o resultado
    printf("Esse arquivo tem %d vogais e %d consoantes.", vogais, *count_letras - vogais);

    //fechar o arquivo
    fclose(fp);
}

int contar(FILE *fp, int *count_letras)
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
        
        //conta quantas letras tem, mudando a variável por referência
        (*count_letras)++;
    }

    //retorna a quantidade de vogais
    return count;
}