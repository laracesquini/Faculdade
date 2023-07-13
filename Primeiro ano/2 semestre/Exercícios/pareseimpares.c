#include <stdio.h>

int main()
{
  int N, X[1000], Y[1000], i; 

  scanf("%d", &N);

  for(i=0; i<N; i++)
    {
      scanf("%d %d", &X[i], &Y[i]);
    }
  for(i=0; i<N; i++)
    {
      if(X[i]%2 == 0 && Y[i]%2 == 0)
        printf("\nA");
      else if(X[i]%2 != 0 && Y[i]%2 != 0)
        printf("\nA");
      else if(X[i]%2 == 0 && Y[i]%2 != 0)
        printf("\nB");
      else
        printf("\nB");
    }

  return 0;
}