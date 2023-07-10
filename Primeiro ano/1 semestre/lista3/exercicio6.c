#include <stdio.h>

int main()
{
  float N;

  printf("Digite um número: ");
  scanf("%f", &N);
  if(N>0)
    printf("\nÉ um número positivo");
  else if(N==0)
    printf("\nÉ um número nulo");
  else
    printf("\nÉ um número negativo");

  return 0;
}