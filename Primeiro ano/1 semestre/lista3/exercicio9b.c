#include <stdio.h>
#include <math.h>

int main()
{ 
    int N;
    printf("Digite um número inteiro: ");
    scanf("%d", &N);
    if((N/4)*4==N)
        printf("\nEsse número é divisível por 4");
    else
        printf("\nNúmero inválido");
    
  return 0;
}