#include <stdio.h>

int main()
{
  float SB, SL, HE, VHE;

  printf("Digite o salário bruto do funcionário: ");
  scanf("%f", &SB);
  printf("Digite o número de horas extras prestadas pelo funcionário e o valor de cada hora: ");
  scanf("%f e %f", &HE, &VHE);

  SL=(SB+(HE*VHE))*0.92;

  printf("O salário líquido é: %.2f", SL);

  return 0;
}