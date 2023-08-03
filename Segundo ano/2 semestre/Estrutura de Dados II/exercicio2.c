#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char arquivo[20];
    int linhas = 0;

    do{
        //pedir para o usuário o nome do arquivo
        printf("Digite o nome e extenção do seu arquivo (Ex: file.txt): ");
        scanf(" %s", arquivo);
        fp = fopen(arquivo, "r");
        
        //verificar se o arquivo existe 
        if(fp == NULL)
        {
            printf("Erro ao abrir o arquivo, tente novamente!\n");
        }
    }while(fp == NULL);

    //ler todas as linhas, até o final do arquivo
    while(!feof(fp))
    {
        //ler caractere por caractere e verificar se corresponde ao caractere de quebra de linha ou tem uma única linha 
        char c = fgetc(fp);
    
        if((c == '\n') || (linhas == 0 && c != EOF))
        {
            linhas++;
        }
    }
    
    //printar o número de linhas
    printf("Esse arquivo tem %d linhas", linhas);
    
    //fechar o arquivo
    fclose(fp);
}