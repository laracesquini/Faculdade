#include <stdio.h>
int main() {
  
  float sal_orig, sal_novo;
  
  printf("Adicione o salário do funcionário: ");
  scanf("%f", &sal_orig);
  if(sal_orig<500)
   sal_novo=sal_orig*1.15;
    else if(sal_orig>=500 && sal_orig<=1000)
      sal_novo=sal_orig*1.10;
      else
        sal_novo=sal_orig*1.05;

  printf("\nO salário do funcionário é: %.2f", sal_orig);
  printf("\nO salário reajustado é: %.2f", sal_novo);
  return 0;
  
}