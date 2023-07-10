#include <stdio.h>

int main ()
{
  int hora, min, minf;

  printf("Digite a hora atual(hora e minutos): ");
  scanf("%dh e %dmin", &hora, &min);

  minf=(hora*60)+min;

  printf("\nA hora em minutos é: %d", minf);
  
  return 0;
}