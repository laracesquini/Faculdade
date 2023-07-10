#include <stdio.h>

int main ()
{
  int N1, N2, soma, subt, mult;
  float div;

  printf("Digite dois números inteiros: ");
  scanf("%d, %d", &N1, &N2);

  soma=N1+N2;
  subt=N1-N2;
  div=N1/N2;
  mult=N1*N2;

  printf("\nA soma dos números é: %d, a subtração dos números é %d, a divisão dos números é %.2f e a multiplicação dos números é %d", soma, subt, div, mult);

  return 0;

}