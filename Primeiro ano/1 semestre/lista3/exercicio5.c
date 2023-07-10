#include <stdio.h>

int main ()
{
  float KW, total, total2;
  char aposentado;

  printf("Quantos KW foram consumidos por hora? ");
  scanf("%f", &KW);
  printf("Você é aposentado(a)? ");
  scanf("%s", &aposentado);
  
     total=KW*0.10;

  if(aposentado=='s' || aposentado=='S')
  {
    total2=total*0.85;
    printf("\nO total a ser pago é %.2f", total2);
  }
  else
  {
    printf("\nO valor a ser pago é %.2f", total);
  }

  return 0;
}
