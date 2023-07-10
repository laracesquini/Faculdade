#include <stdio.h>

int main() {
  int n1, n2;
  printf("Adicione um número: ");
  scanf("%d", &n1);
  printf("\nAdicione outro número: ");
  scanf("%d", &n2);
  printf("\nA soma de %d e %d é %d", n1, n2, n1+n2);
  return 0;
}
