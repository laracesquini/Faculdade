#include <stdio.h>

int main ()
{
  float a, b, c;
  float media;

  printf("Digite três números: ");
  scanf("%f, %f, %f", &a, &b, &c);
  
   media=(a+b+c)/3;

  if(media>a || media>b || media>c)
    printf("A média é maior que um dos números");
  else
    printf("A média é %.2f", media);

  return 0;
}