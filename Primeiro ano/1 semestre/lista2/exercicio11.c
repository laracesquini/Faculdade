#include <stdio.h>

int main()
{
  float realD, dolar, aux1, realE, euro, aux2;

  printf("\nDigite o valor a ser convertido de dólar para real e a cotação do dia: ");
  scanf("%f e %f", &dolar, &aux1);
  printf("\nDigite o valor a ser convertido de Euro para real e a cotação do dia: ");
  scanf("%f e %f", &euro, &aux2);

  realD=dolar*aux1;
  realE=euro*aux2;

  printf("\n%.2f dólares são %.2f reais", dolar, realD);
  printf("\n%.2f euros são %.2f reais", euro, realE);

  return 0;
}
