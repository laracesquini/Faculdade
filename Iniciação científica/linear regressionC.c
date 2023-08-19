#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct results{
    double price_per_room;
    double base_price;
}Results;

double random();
Results square_tric(Results result, int num_rooms, double price, double learning_rate);
Results linear_regression(int *features, int *labels, double learning_rate, double epochs);

int main()
{
    int features[6] = {1, 2, 3, 5, 6, 7};
    int labels[6] = {155, 187, 244, 356, 407, 448};

    Results resultado;

    resultado = linear_regression(features, labels, 0.01, 1000);

    printf("Preço por quarto: %.2lf\nPreço base: %.2lf", resultado.price_per_room, resultado.base_price);
}

double random() {
    return (double)rand() / RAND_MAX;
}

Results square_tric(Results result, int num_rooms, double price, double learning_rate)
{
    double predicted_price = result.base_price + (result.price_per_room*num_rooms);
    result.base_price += learning_rate*(price - predicted_price);
    result.price_per_room += learning_rate*num_rooms*(price - predicted_price);

    return result;
}

Results linear_regression(int *features, int *labels, double learning_rate, double epochs)
{
    Results result;
    int i, epoch, num_rooms;
    double price;

    srand(time(NULL));
    result.price_per_room = random();
    result.base_price = random();
   
    for(epoch = 0; epoch < epochs; epoch++)
    {
        i = rand()%(sizeof(features)-1);
        num_rooms = features[i];
        price = labels[i];
        result = square_tric(result, num_rooms, price, learning_rate);
    }

    return result;
}