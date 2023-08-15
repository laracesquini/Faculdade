#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int stt = 0;
    char nome[50], nome_buscado[50];

    fp = fopen("arq.txt", "r");

    printf("Qual o nome buscado? ");
    scanf(" %[^\n]s", nome_buscado);

    while(!feof(fp))
    {
        fgets(nome, 50, fp);
        nome[strcspn(nome, "\n")] = 0;
        if(strcmp(nome, nome_buscado) == 0)
        stt = 1;
    }

    fclose(fp);

    if(stt == 1)
    printf("Encontrado");
    else
    printf("Não encontrado");
}