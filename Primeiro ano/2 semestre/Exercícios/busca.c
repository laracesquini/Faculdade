#include <stdio.h>
#include <stdlib.h>

int busca(int*, int, int, int);

int main()
{
    int i, tam, num, *V, valor=0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    V = malloc(tam*sizeof(int));

    for(i=0; i<tam; i++)
    {
        printf("\nPreencha o vetor: ");
        scanf("%d", &V[i]);
    }

    printf("\nDigite o número procurado: ");
    scanf("%d", &num);

    i=0;
    valor = busca(V, i, tam, num);

    if(valor == -1)
    printf("\nNúmero não encontrado");
    else
    {
        printf("\nNúmero encontrado!!");
        printf("\nO valor do índice é: %d", valor);
    }
}

    int busca(int *vet, int i, int tam, int n)
    {        
        if(i>tam)
        return (-1);
        else if(*vet == n)
        return i;
        else
        busca((vet+1), i+1, tam-1, n);
    }
 