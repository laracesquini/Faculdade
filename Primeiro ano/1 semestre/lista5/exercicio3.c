#include <stdio.h>

int main()
{
  int VA[5], VB[5], i, j, aux;

  
  for(i=0; i<5; i++)
    {
      do{
     printf("\nDigite o %dº valor: ", i+1);
      scanf("%d", &VA[i]);
      if(VA[i]<0)
        printf("\nValor inválido");
    
    }while (VA[i]<0);
      }
  
  for(j=0; j<5; j++)
    {
      do{
      printf("\nDigite o %dº valor: ", j+6);
      scanf("%d", &VB[j]);
        if(VB[j]<0)
          printf("\nValor inválido");
        } while(VB[j]<0);
    }

  j=4;
  for(i=0; i<5; i++)
    {
      aux=VA[i];
      VA[i]=VB[j];
      VB[j]=aux;
      j--;
    }

  for(i=0; i<5; i++)
    printf("\n%d", VA[i]);
  for(j=0; j<5; j++)
    printf("\n%d", VB[j]);
    
    return 0;
}