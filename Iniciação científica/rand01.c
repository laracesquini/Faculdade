#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que gera números aleatórios entre 0 e 1
double random_between_0_and_1() {
    return (double)rand() / RAND_MAX;
}

int main() {
    srand(time(NULL));

    // Gera e imprime alguns números aleatórios no intervalo [0, 1]
    for (int i = 0; i < 5; i++) {
        double random_number = random_between_0_and_1();
        printf("Random number between 0 and 1: %lf\n", random_number);
    }

    return 0;
}
