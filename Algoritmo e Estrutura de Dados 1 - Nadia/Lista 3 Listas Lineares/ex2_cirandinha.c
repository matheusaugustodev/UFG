#include <stdio.h>

int main() {
  int n, i, j, k, indice_ganhador, valores[100], total_valores=0;
  char nome_criancas[100][30];

  scanf("%d", &n);

  for (i=0; i<n; i++) {
    scanf("%s %d", nome_criancas[i], &valores[i]);
    total_valores += valores[i];
  }

    indice_ganhador = total_valores % 2 == 0 ? total_valores % n + 1 : n - 1 - (total_valores % n);
    printf("%s", nome_criancas[indice_ganhador]);

  return 0;
}
