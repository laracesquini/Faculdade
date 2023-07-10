#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

int main() {

  //Variáveis
  int v[10], i, j=0, k=0, soma=0, pares[10], soma_pares=0, impares[10], soma_impares=0;
  float media;

  srand(time(NULL));
  
  for(i=0; i<10; i++) 
  {
    v[i]=1+rand()%10;
    printf("\n v[%d]: %d", i+1, v[i]);
    soma=soma+v[i];
    }

  //item a
  media=(float)soma/10;
  printf("\nA média dos números é %.2f", media);
  
  //item b
  for(i=0; i<10; i++) {
   if((v[i]%2)==0)
   {
        pares[j]=v[i];
        j=j+1;
        soma_pares=soma_pares+v[i];
    }
    else
   {
        impares[k]=v[i];
        k=k+1;
        soma_impares=soma_impares+v[i];
   }
  }

  printf("\nA média dos números pares é: %.2f", (float)soma_pares/j);
  printf("\nA média dos números ímpares é: %.2f", (float)soma_impares/k);
  printf("\nA quantidade de números pares é: %d", j);
  printf("\nA quantidade de números ímpares é %d", k);
 
  return 0;
}