#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>

#define n 10
#define tam_conjunto 20

void shuffle(int* v, int t)
{
    srand(time(0));
    long r1;
    long r2;
    int a;
    for(int i=0;i<(int)(t/2.0);i++)
    {
        
    do
    {
        r1=((long)(rand()/100.0))%t;
        r2=((long)(rand()/100.0))%t;
    }while(v[r1]==v[r2]);
    a=v[r1];
    v[r1]=v[r2];
    v[r2]=a;
    }
}

int main()
{
    int *m, k, it = 0;

    m = (int *)malloc(tam_conjunto*sizeof(int));


    for(k = 0; k < tam_conjunto/2; k++)
    m[k] = 1;

    for(k = tam_conjunto/2; k < tam_conjunto; k++)
    m[k] = 0;

    

    do
    {
        for(int k = 0; k < tam_conjunto; k++)
        {
            printf("%d ", m[k]);
        }
        printf("\n");

        shuffle(&m[0], tam_conjunto);
        it++;
    }while(it <= n);
}
