#include <stdio.h>

int main()
{
    float vet[4] = {100330, 10560000, 5780000, 21247};
    float maior;

    maior = vet[0];

    for(int i = 0; i<4; i++)
    {
        if(vet[i] > maior)
        maior = vet[i];
    }

    printf("%.2f", maior);

}