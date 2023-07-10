#include <stdio.h>

int main()
{
    int i=0;
    FILE *fp;

    fp = fopen("dados.dat", "w");

    while(i<15)
    {
        fprintf(fp, "LALA");
        i++;
    }

    fclose(fp);
}