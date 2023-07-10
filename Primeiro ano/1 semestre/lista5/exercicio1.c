#include <stdio.h>
#define x 2
#define y 4
#define max 10

int main()
{
  //Declaração de variáveis
  int str[max]={2, 6, 8, 3, 10, 9, 1, 21, 33, 14};
  int i;

  i=x*5;
  // i=x+1, i=x+2, i=x+3, i=y*1, i=x*3, i=x*2, i=x*5

  if(i<10)
    printf("%d", str[i]);
  
  else
    printf("ERRO!");

  return 0;
}