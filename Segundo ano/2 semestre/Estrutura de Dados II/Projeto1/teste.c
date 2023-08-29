#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct iprimary{
    char first_key[5];
    int RNN;
}Iprimario;

int main()
{
    Iprimario vetp[30];
    FILE *fp;
    char aux[20];
    int i = 0, a;

    fp = fopen("teste.txt", "r");
    char *token;

    while(!feof(fp))
    {
        fscanf(fp, "%[^#]s", aux);
        fgetc(fp);
        
        token = strtok(aux, "@");
        printf("Tokwn string: %s\n", token);
        strcpy(vetp[i].first_key, token);
        token = strtok(NULL, "@");
        printf("%s\n", token);
        vetp[i].RNN = atoi(token);
        i++;
    }

    printf("0: %s, %d\n", vetp[0].first_key, vetp[0].RNN);
    printf("1: %s, %d", vetp[1].first_key, vetp[1].RNN);
}