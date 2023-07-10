#include <stdio.h>

int main()
{
  int soma, i;

  i=0;
  soma=0;

  while(i>=0 && i<=500) {
    soma=soma+i;
    i+=2;
    }

  printf("%d", soma);
  
  return 0;
}