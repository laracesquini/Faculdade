#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char c;

    fp = fopen("arq.txt", "r");
    fseek(fp, 9, SEEK_SET);
    c = fgetc(fp);

    printf("O 10º caractere desse arquivo é %c", c);
    
    fclose(fp);
}