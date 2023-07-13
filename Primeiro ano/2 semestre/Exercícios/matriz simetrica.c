#include <stdio.h>
#define n 5

int main()
{
    int m[n][n], i, j, stt=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\nPreencha a matriz: ");
            scanf("%d", &m[i][j]);
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(m[i][j]!=m[j][i])
            stt = 1;
        }
    }

    if(stt==0)
    printf("\nA matriz é simétrica");
    else
    printf("\nA matriz não é simétrica");


}