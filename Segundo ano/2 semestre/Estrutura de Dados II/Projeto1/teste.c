#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

int main()
{
    Iprimario *vetp = NULL, *auxp;
    FILE *fd;
    char aux[20];
    int i = 0, a;
    fd = fopen("teste.txt", "r");

    fseek(fd, 0, SEEK_END);

    a = ftell(fd);
    printf("Tamanho: %d", a);

}