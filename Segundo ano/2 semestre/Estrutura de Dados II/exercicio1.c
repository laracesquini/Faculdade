#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char c;

    fp = fopen("arq.txt", "w");

    do{
        printf("Digite um caractere: ");
        scanf(" %c", &c);
        if(c != '0')
        fprintf(fp, "%c", c);
    }while(c != '0');

    fclose(fp);
}