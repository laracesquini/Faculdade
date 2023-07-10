#include <stdio.h>
#include <math.h>

int main()
{
  typedef struct ponto{
  int x;
  int y;
  }Tponto;

  Tponto P[6];
  int i; 
  float dist1, dist2, dist3;

  for(i=0; i<6; i++)
    {
      printf("\nDigite a coordenada de um ponto: ");
      printf("\nx: ");
      scanf("%d", &P[i].x);
      printf("\ny: ");
      scanf("%d", &P[i].y);
    }

  dist1 = sqrt(pow(P[1].x-P[0].x, 2) + pow(P[1].y-P[0].y, 2));
  dist2 = sqrt(pow(P[3].x-P[2].x, 2) + pow(P[3].y-P[2].y, 2));
  dist3 = sqrt(pow(P[5].x-P[4].x, 2) + pow(P[5].y-P[4].y, 2));
  

  if(dist1<(dist2+dist3) && dist2<(dist1+dist3) && dist3<(dist1+dist2))
  {
    printf("\nEssa medidas podem formar um triângulo");
    printf("\nO comprimento de cada aresta é: ");
    printf("\nAresta 1: %.2f", dist1);
    printf("\nAresta 2: %.2f", dist2);
    printf("\nAresta 3: %.2f", dist3);
  }
  else
    printf("\nNão é um triângulo");

  return 0;
}