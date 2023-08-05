#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char c;
    int palavras = 0, caracteres = 0, linhas = 0;

    fp = fopen("arq.txt", "r");

    while(!feof(fp))
    {
        c = fgetc(fp);

        if(c != EOF)
        {
            caracteres++;
        }
        if(c == ' ' || c == '\n' ||(palavras != 0 && c == EOF))
        {
            palavras++;
        }
        if((c == '\n') || (linhas == 0 && c != EOF))
        {
            linhas++;
        }
    }

    fclose(fp);

    printf("Linhas: %d\nPalavras: %d\nCaracteres: %d\n", linhas, palavras, caracteres);
}