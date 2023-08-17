#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char linha[100];
    int count = 0;
    
    fp = fopen("arq.txt", "r");

    while(count < 4 && fgets(linha, sizeof(linha), fp))
    {
        count++;
    }
    if(count == 4)
    {
        fgets(linha, sizeof(linha), fp);
        printf("5º linha: %s", linha);
    }

    fclose(fp);
}