#include <stdio.h>
#include <math.h>
#define n 2

int main()
{
  //Declaração de variáveis
  typedef struct vetor {
  float x;
  float y;
  float z;
  }Tvetor;
  Tvetor V[n];

  int i;
  float eixo_x, eixo_y, eixo_z, soma;

  //Programa principal
  for(i=0; i<n; i++)
    {
      printf("\nDigite um valor para preencher o vetor %d: ", i+1);
      printf("\nEixo x: ");
      scanf("%f", &V[i].x);
      printf("\nEixo y: ");
      scanf("%f", &V[i].y);
      printf("\nEixo z: ");
      scanf("%f", &V[i].z);
  
      eixo_x = V[0].x + V[1].x;
      eixo_y = V[0].y + V[1].y;
      eixo_z = V[0].z + V[1].z;
    }

  soma = sqrt(pow(eixo_x,2)+pow(eixo_y,2)+pow(eixo_z,2));

  printf("\nA soma dos vetores em relação aos seus eixos é: %.0f em x, %.0f em y e %.0f em z", eixo_x, eixo_y, eixo_z);
  printf("\nA soma dos vetores em módulo é: ");
  printf("\nV = %.2f", soma);

  return 0;
}
