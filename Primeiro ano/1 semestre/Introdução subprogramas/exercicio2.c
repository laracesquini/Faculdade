#include <stdio.h>

int fat(int n)
{
  int fatorial = 1;
  for(int i=1; i<=n; i++)
    fatorial = fatorial*i;
  return fatorial;
}

int main()
{
  int n1;

  printf("\nDigite um número: ");
  scanf("%d", &n1);
  printf("\nO fatorial desse número é %d", fat(n1));

  return 0;
}