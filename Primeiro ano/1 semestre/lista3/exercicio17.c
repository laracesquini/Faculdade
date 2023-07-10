#include <stdio.h>

int main()
{
  float altura, peso, IMC;

  printf("Digite seu peso: ");
  scanf("%f", &peso);
  printf("\nDigite sua altura: ");
  scanf("%f", &altura);

  IMC=peso/(altura*altura);

  if(IMC<18.5)
    printf("\nDesnutrição.");
  else if(IMC>=18.5 && IMC<=24.5)
    printf("\nPeso normal.");
  else if(IMC>=25 && IMC<=29.9)
    printf("\nSobrepeso.");
  else if(IMC>=30 && IMC<=39.9)
    printf("\nObesidade.");
  else
    printf("\nObesidade mórbida");

  return 0;
}