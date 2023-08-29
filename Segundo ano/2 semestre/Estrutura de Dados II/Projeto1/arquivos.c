//implementação de funções
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

int file_exists(char *nome)
{
    FILE *fp;

    if(fp = fopen(nome, "r"))
    {
        fclose(fp);
        return 1;
    }

    return 0;
}