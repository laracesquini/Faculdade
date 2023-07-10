#include <stdio.h>
#define x 2
#define y 4
#define max 10

int main()
{
  //Declaração de variáveis
  int str[max]={2, 6, 8, 3, 10, 9, 1, 21, 33, 14};
  int i;

  i=x+y;

  if(i<10)
    printf("%d", str[str[i]]);
  
  else
    printf("ERRO!");

  return 0;
}