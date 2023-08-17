#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("arq.txt", "r+");
    fseek(fp, 14, SEEK_SET);
    fputc('X', fp);
    fclose(fp);
}