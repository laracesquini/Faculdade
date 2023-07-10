#include <stdio.h>

int main() {
 float N1, N2, media;
  printf("Digite as notas: ");
  scanf("%f e %f", &N1, &N2);
  media=(N1+N2)/2;
  printf("Sua média é: %.1f", media);
  if(media>=5)
    printf("\nAprovado!");
  else
    printf("\nReprovado.");
    
    return 0;
}