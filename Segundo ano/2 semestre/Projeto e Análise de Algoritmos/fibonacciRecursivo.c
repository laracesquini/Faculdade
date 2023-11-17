#include <stdio.h>
#include <sys/time.h>
#include <time.h>

unsigned long long int fibonacciRecursivo(int N) {
    if (N <= 1)
        return N;
    else
        return fibonacciRecursivo(N - 1) + fibonacciRecursivo(N - 2);
}

int main() {
    int N;
    unsigned long long int resultado;
    N = 10;
    //struct timeval inicio, fim;
    //double tempo;
    clock_t inicio, fim;
    long double tempo;

    inicio = clock();
    resultado = fibonacciRecursivo(N);
    fim = clock();

    tempo = ((long double)(fim - inicio))/CLOCKS_PER_SEC;
    printf("N: %d\nResultado: %llu\nTempo: %Lf segundos", N, resultado, tempo);
    
    return 0;
}