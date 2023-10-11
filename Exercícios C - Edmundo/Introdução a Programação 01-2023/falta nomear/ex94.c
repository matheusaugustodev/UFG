#include <stdio.h>

int main() {

  int n, x1, x;
  int contador = 1, maior = 1, i = 1;
  
  scanf("%d", &n);
  scanf("%d", &x1);
  while(i<n) {
    scanf("%d", &x);
    if(x1<x) {
      contador++;
    } else {
      contador = 1;
    }
    x = x1;
    if(contador>maior) {
      maior = contador;
    }
    i++;
  }
  printf("O comprimento do segmento crescente maximo e: %i\n", maior);

   return 0;
 }
