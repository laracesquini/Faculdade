#include <stdio.h>

int espiral(int n);

int main()
{
   int N, resp;
   scanf("%d", &N);

   resp = espiral(N);

   printf("\nA resposta: %d", resp);

}

int espiral(int n)
{
    int i, j, m[n][n], resp[n];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(m[i][j]==(m[i+1][j]+1))
            {
            resp[j] = 1;
            }
        }
    }
}