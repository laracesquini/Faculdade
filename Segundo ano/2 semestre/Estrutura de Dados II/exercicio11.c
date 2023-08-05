#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char c;
    int palavras = 0, caracteres = 0, linhas = 0;

    //abrir o arquivo
    fp = fopen("arq.txt", "r");

    while(!feof(fp))
    {
        //ler cada caractere e verifica-lo
        c = fgetc(fp);

        //se for diferente do final do arquivo, incrementa a quantidade de caracteres
        if(c != EOF)
        {
            caracteres++;
        }

        //se for espaço, quebra de linha ou no caso de ser a última palavra ou ter uma palavra só
        if(c == ' ' || c == '\n' ||(caracteres != 0 && c == EOF))
        {
            palavras++;
        }
        
        //se for quebra de linha ou tiver uma única linha
        if((c == '\n') || (linhas == 0 && c != EOF))
        {
            linhas++;
        }
    }

    //fechar o arquivo
    fclose(fp);
    //printar os resultados
    printf("Linhas: %d\nPalavras: %d\nCaracteres: %d\n", linhas, palavras, caracteres);
}