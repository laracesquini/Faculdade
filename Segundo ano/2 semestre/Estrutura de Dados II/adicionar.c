#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char nome[50];

    fp = fopen("arq.txt", "a");

    printf("Digite o nome que será adicionado: ");
    scanf(" %[^\n]s", nome);

    fprintf(fp, "\n%s", nome);

    fclose(fp);
}