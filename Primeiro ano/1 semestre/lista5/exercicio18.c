#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int main() {

  int V[11], i, elem, ind, aux;

  srand(time(NULL));

  for(i=0; i<10; i++)
    {
      V[i]=1+rand()%100;
      
      printf(" %d", V[i]);
    }
  printf("\nDigite um valor: ");
  scanf("%d", &elem);
  do{
    printf("\nDigite um índice: ");
    scanf("%d", &ind);
    if(ind<0 || ind>9)
      printf("\nInválido");
    }while(ind<0 || ind>9);

  aux=V[ind];
  V[ind]= elem;

  for(i=10; i>ind; i--)
    {
      V[i]= V[i-1];
      if(i==ind+1)
        V[i]=aux;
    }
  
  for(i=0; i<11; i++)
    printf(" %d", V[i]);
    
    return 0;
}