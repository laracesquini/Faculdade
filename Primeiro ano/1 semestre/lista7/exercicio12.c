#include <stdio.h>
#include <math.h>

int main()
{
  typedef struct ponto{
    int x;
    int y;
  }Tponto;

  Tponto P[4];
  int i; 
  float dist1, dist2, dist3, dist4;

  for(i=0; i<4; i++)
    {
      printf("\nDigite a coordenada de um ponto: ");
      printf("\nx: ");
      scanf("%d", &P[i].x);
      printf("\ny: ");
      scanf("%d", &P[i].y);
    }

  dist1 = sqrt(pow(P[1].x-P[0].x, 2) + pow(P[1].y-P[0].y, 2));
  dist2 = sqrt(pow(P[2].x-P[1].x, 2) + pow(P[2].y-P[1].y, 2));
  dist3 = sqrt(pow(P[3].x-P[2].x, 2) + pow(P[3].y-P[2].y, 2));
  dist4 = sqrt(pow(P[3].x-P[0].x, 2) + pow(P[3].y-P[0].y, 2));

  if(dist1 == dist3 && dist2 == dist4)
  {
    printf("\nÉ um retângulo");
    printf("\nO comprimento de cada aresta é: ");
    printf("\nAresta 1: %.2f", dist1);
    printf("\nAresta 2: %.2f", dist2);
    printf("\nAresta 3: %.2f", dist3);
    printf("\nAresta 4: %.2f", dist4);
    printf("\nA área do retângulo é: %.2f", dist1*dist2);
  }
  else
    printf("\nNão é um retângulo");
}
