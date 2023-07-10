#include <stdio.h>

int main()
{
  float a, b, c, d, e;
  int mesa;
  float refrigerante, cerveja, pizza, almoço, porçao, conta;

printf("Digite o número da mesa: ");
scanf("%d", &mesa);
printf("\nDigite o que foi consumido: ");
printf("\nRefrigerante: ");
scanf("%f", &a);
printf("\nCerveja: ");
scanf("%f", &b);
printf("\nPizza: ");
scanf("%f", &c);
printf("\nAlmoço: ");
scanf("%f", &d);
printf("\nPorção: ");
scanf("%f", &e);

refrigerante=a*2.50;
cerveja=b*4;
pizza=c*47.30;
almoço=d*15;
porçao=e*10.50;
conta=(refrigerante+cerveja+pizza+almoço+porçao)*1.10;

printf("\nA conta da mesa %d deu %.2f reais.", mesa, conta);

  
return 0;
}
