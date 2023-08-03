#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char c;

    //abrir o arquivo
    fp = fopen("arq.txt", "w");

    do{
        //ler um caractere do usuário
        printf("Digite um caractere: ");
        scanf(" %c", &c);
        //escrever ele no arquivo se ele for diferente de 0
        if(c != '0')
        fprintf(fp, "%c", c);
    }while(c != '0');

    fclose(fp);
}