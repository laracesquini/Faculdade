#include <stdio.h>

int main()
{
  float KW, VT;

  printf("Digite o valor de energia consumido em quilowatts: ");
  scanf("%f", &KW);

  VT=(KW*0.12)*1.18;

  printf("\nO valor a ser pago é: %.2f", VT);

  return 0;
}