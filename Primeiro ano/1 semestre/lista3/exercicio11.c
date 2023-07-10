#include <stdio.h>

int main()
{
  float KWH, valor;

  printf("Adicione o valor consumido em KWH: ");
  scanf("%f", &KWH);
  if(KWH<=50)
    valor=KWH*1;
  else if(KWH>=51 && KWH<=100)
    valor=50+((KWH-50)*1.3);
  else if(KWH>=101 && KWH<=150)
    valor=115+((KWH-100)*1.6);
  else
    valor=195+((KWH-150)*2);

  printf("\n CONTA DE ENERGIA\n");
	printf("VALOR TOTAL A PAGAR: R$%.2f\n\n", valor);
 return 0;
}