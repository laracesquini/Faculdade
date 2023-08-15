#include <stdio.h>
#include <stdlib.h>
#define n 10

int busca_binaria(int *indice, int num)
{
    int min = 0, max = (n-1), mid;

    while(min <= max)
    {
        mid = (min + max)/2;

        if(num == indice[mid])
        return mid;
        else if(num > indice[mid])
        min = mid + 1;
        else
        max = mid - 1;
    }

    return -1;
}

int main()
{
    int vet[n] = {10, 25, 32, 45, 70, 100, 120, 135, 150, 200};
    int num, i;

    scanf("%d", &num);
    i = busca_binaria(vet, num);

    if(i != -1)
    printf("Encontrado!");
    else
    printf("Não encontrado");
}