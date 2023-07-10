#include <stdio.h>

int main()
{ 
    int N1, N2, N3;
    printf("Digite 3 números inteiros e diferentes entre si: ");
    scanf("%d, %d, %d", &N1, &N2, &N3);
    if(N1<N2 && N1<N3)
        printf("%d é o menor número", N1);
    else if(N2<N1 && N2<N3)
        printf("%d é o menor número", N2);
    else
        printf("%d é o menor número", N3);
    return 0;
}