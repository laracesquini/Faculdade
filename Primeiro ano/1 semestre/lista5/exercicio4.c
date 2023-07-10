#include <stdio.h>

int main()
{
  int VA[5], VB[5], VC[5], i, j, k;

  
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
  k=4;
  for(i=0; i<5; i++)
    {
      VC[k]=VA[i]*VB[j];
  
      j--;
      k--;
    }

  for(k=0; k<5; k++)
    printf("\n%d", VC[k]);
    
    return 0;
}
