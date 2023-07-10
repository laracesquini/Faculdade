#include <stdio.h>

int main ()
{
  float b, a, area, perimetro;

  printf("Digite dois valores para ser a base e a altura de um retângulo: ");
  scanf("%f, %f", &b, &a);

  area=b*a;
  perimetro=b+b+a+a;

  printf("\nA area do retângulo é %.2f e o perimetro do retângulo é %.2f", area, perimetro);

  return 0;

}