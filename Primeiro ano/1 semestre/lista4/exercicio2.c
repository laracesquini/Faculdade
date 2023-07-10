#include <stdio.h>

int main ()
{
  float KW, total, total2;
  char aposentado;
  int i;

  printf("Digite o número de residências: ");
  scanf("%d", &i);
  
  while(i>0) 
  {
    printf("\nResidência %d", i);
    printf("\nQuantos KW foram consumidos por hora? ");
    scanf("%f", &KW);
    printf("\nVocê é aposentado(a)? ");
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
    i--;
  }
  
  return 0;
}