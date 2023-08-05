#include <stdio.h>
#include <stdlib.h>

void vogais(FILE *fp);

int main()
{
    FILE *fp;
    char arquivos[20];

    do
    {
        //pedir para o usuário o nome do arquivo
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivos);

        //abrir o arquivo
        fp = fopen(arquivos, "r");

        //verificar se o arquivo existe
        if(fp == NULL)
        printf("Erro ao abrir o arquivo, tente novamente!\n");
    } while (fp == NULL);

    vogais(fp);

    //fechar o arquivo
    fclose(fp);
}

void vogais(FILE *fp)
{
    FILE *arq;
    char c;

    //criar arquivo para escrita
    arq = fopen("escrita.txt", "w");

    while(!feof(fp))
    {
        //ler cada caractere 
        c = fgetc(fp);

        //verificar se é vogal e, se for, escrever no arquivo substituindo por '*', senão, só escrever a vogal normalmente
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        fprintf(arq, "%c", '*');
        else if(c != EOF)
        fprintf(arq, "%c", c);
    }

    //fechar o arquivo de escrita
    fclose(arq);
}