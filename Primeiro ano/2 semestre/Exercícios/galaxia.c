#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  int N, M, op, i, j;
  typedef struct planeta {
  char nome[21];
  double peso;
  double x;
  double y;
  double z;
  }TP;

  char nomeaux[21], nomeaux2[21];
  double x_aux, y_aux, z_aux, x2_aux, y2_aux, z2_aux, dist;

  scanf("%d %d", &N, &M);

  TP plan[N];

  for(i=0; i<N; i++)
    {
      scanf(" %s %lf %lf %lf %lf", plan[i].nome, &plan[i].peso, &plan[i].x, &plan[i].y, &plan[i].z);
    }

  for(j=0; j<M; j++)
    {
      scanf("%d", &op);

      if(op==1)
      {
        scanf(" %s %s", nomeaux, nomeaux2);
        for(i=0; i<N; i++)
          {
            if(strcmp(nomeaux, plan[i].nome)==0)
            {
              x_aux = plan[i].x;
              y_aux = plan[i].y;
              z_aux = plan[i].z;
            }
            if(strcmp(nomeaux2, plan[i].nome)==0)
            {
              x2_aux = plan[i].x;
              y2_aux = plan[i].y;
              z2_aux = plan[i].z;
            }
          }
        
        dist = sqrt(pow((x2_aux - x_aux), 2) + pow((y2_aux - y_aux), 2) + pow((z2_aux - z_aux), 2));
        printf("\n%.2lf", dist);
      }

      if(op==2)
      {
        scanf(" %s", nomeaux);
        for(i=0; i<N; i++)
          {
            if(strcmp(nomeaux, plan[i].nome)==0)
            {
              printf("\n%.0lf %.0lf %.0lf", plan[i].x, plan[i].y, plan[i].z);
            }
          }
      }

      if(op==3)
      {
        scanf(" %s", nomeaux);
        for(i=0; i<N; i++)
          {
            if(strcmp(nomeaux, plan[i].nome)==0)
            {
              printf("\n%.2lf", plan[i].peso);
            }
          }
      }
    }

  return 0;
}