#include <stdio.h>

int main()
{
  int a, b, c, d, e;

  printf("Digite 5 números inteiros: ");
  scanf("%d, %d, %d, %d, %d", &a, &b, &c, &d, &e);
  if(a>b && a>c && a>d && a>e) 
    printf("\n%d é o maior número", a);
  else if(b>c && b>d && b>e)
    printf("\n%d é o maior número", b);
  else if(c>d && c>e)
   printf("\n%d é o maior número", c);
  else if(d>e) 
     printf("\n%d é o maior número", d);
  else
     printf("\n%d é o maior número", e);

  if(a<b && a<c && a<d && a<e)
     printf("\n%d é o menor número", a);
  else if(b<c && b<d && b<e)
    printf("\n%d é o menor número", b);
  else if(c<d && c<e)
     printf("\n%d é o menor número", c);
  else if(d<e)
     printf("\n%d é o menor número", d);
  else
     printf("\n%d é o menor número", e);

  return 0;
}