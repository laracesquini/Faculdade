#include <stdio.h>
#include <math.h>

int main ()
{
  float a, b, c, d, e, f, x;

  printf("Digite 6 números: ");
  scanf("%f, %f, %f, %f, %f, %f", &a, &b, &c, &d, &e, &f);

  x=((a+(b/c))/(d-(2*(e/f))))+4;

  printf("O valor de x é %f", x);

  return 0;
    
}