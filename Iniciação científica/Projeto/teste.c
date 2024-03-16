#include <stdio.h>
#include <math.h>

int main()
{
    long n = pow(2, 20);
    int t[n];

    

    for(int i = 0; i < n; i++)
    {
        printf("a");
        t[i] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d", t[i]);
    }
}