#include <stdio.h>

int main()
{
  int N, i, fat;

  printf("Digite um número: ");
  scanf("%d", &N);

  i=1;
  fat=1;
  
  while(N>=i) 
  {
    fat=fat*i;
    i++;
  }

  printf("%d! é %d", N, fat);
  return 0;  
}