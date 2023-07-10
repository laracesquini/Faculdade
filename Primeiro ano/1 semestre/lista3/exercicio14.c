#include <stdio.h>

int main()
{
  int a, b, c;

  printf("Digite 3 números diferentes entre si: ");
  scanf("%d, %d, %d", &a, &b, &c);
  if(a>b && a>c)
    printf("%d é o maior número", a);
  else if(b>a && b>c)
    printf("%d é o maior número", b);
  else
    printf("%d é o maior número", c);

  return 0;
}