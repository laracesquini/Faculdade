#include <stdio.h>
#include <math.h>

int main()
{
  double x, *y, **z;
  x = 2.3;
  y = &x; 
  z = &y;

  printf("O valor de x: %.2f \n", x);
  printf("O endereço de x: %p \n", &x);
  printf("O valor de y: %p \n", y);
  printf("O endereço de y: %p \n", &y);
  printf("O valor apontado por y: %.2f \n", *y);
  printf("O valor de z: %p \n", z);
  printf("O endereço de z: %p \n", &z);
  printf("O valor apontado por z: %p \n", *z);
  printf("O valor apontado pela variável que está apontada por z: %.2f \n", **z);

  return 0;
}

/*Resposta:  
O valor de x: 2.30 
O endereço de x: 0x7ffc979ad600 
O valor de y: 0x7ffc979ad600 
O endereço de y: 0x7ffc979ad5f8 
O valor apontado por y: 2.30 
O valor de z: 0x7ffc979ad5f8 
O endereço de z: 0x7ffc979ad5f0 
O valor apontado por z: 0x7ffc979ad600 
O valor apontado pela variável que está apontada por z: 2.30 */