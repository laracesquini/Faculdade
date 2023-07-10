#include <stdio.h>

int main()
{
  //Declaração de variávies
  int VIN[10], VAI[30], i;

  //Programa principal
  for(i=0; i<10; i++)
    {
      printf("\nDigite um valor para VIN[%d]: ", i);
      scanf("%d", &VIN[i]);
      VAI[3*i]=VIN[i];
      VAI[3*i+1]=VIN[i];
      VAI[3*i+2]=VIN[i];
    }

  for(i=0; i<30; i++)
    {
      printf(" %d", VAI[i]);
    }
  
  return 0;
}