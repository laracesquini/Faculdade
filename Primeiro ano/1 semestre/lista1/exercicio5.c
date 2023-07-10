#include <stdio.h>

int main() {
  float n1, n2;
  printf("Adicione um número: ");
  scanf("%f", &n1);
  printf("\nAdicione outro número: ");
  scanf("%f", &n2);
  printf("\nA soma de %.3f e %.3f é %.5f", n1, n2, n1+n2);

  return 0;
}