#include <stdio.h>
#include <math.h>
#define n 5

int main()
{
  typedef struct ponto {
    int x;
    int y;
  }Tponto;

  Tponto P[n];
  int i, xmenor = 0, ymenor=0;
  float distancia = 0, menordist;

  for(i=0; i<n; i++)
    {
      printf("\nPonto %d", i+1);
      printf("\nDigite um valor para a coordenada x do ponto: ");
      scanf("%d", &P[i].x);
      printf("\nDigite um valor para a coordenada y do ponto: ");
      scanf("%d", &P[i].y);
    }

  for(i=1; i<n; i++)
    {
      distancia = sqrt(pow(P[i].x- P[0].x, 2) + pow(P[i].y - P[0].y, 2));

      if(i==1)
      {
        menordist = distancia;
        xmenor = P[i].x;
        ymenor = P[i].y;
        }
      
      else if(distancia<menordist)
      {
        menordist = distancia;
        xmenor = P[i].x;
        ymenor = P[i].y;
      }
    }

  printf("\nO ponto (%d,%d) é o que tem menor distância em relação ao ponto (%d,%d)", xmenor, ymenor, P[0].x, P[0].y);
  printf("\nA distância é: %.2f", menordist);

  return 0;
}