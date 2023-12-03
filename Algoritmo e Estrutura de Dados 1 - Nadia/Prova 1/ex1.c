#include <stdio.h>

void espiral(int n, int x, int y) {

  // Inicializa a matriz
  int matriz[n][n], i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matriz[i][j] = x;
    }
  }



  // Começa na posição central da matriz
  i = n / 2;
  j = n / 2;

  // Define a direção atual
  int direcao = 1, valor;

  // Preenche a matriz
  for (valor = x; valor <= y; valor++) {
    matriz[i][j] = valor;

    // Atualiza a posição atual
    switch (direcao) {
      case 1:
        i--;
        break;
      case 2:
        j++;
        break;
      case 3:
        i++;
        break;
      case 4:
        j--;
        break;
    }

    // Verifica se precisa mudar a direção
    if (i < 0 || i >= n || j < 0 || j >= n || matriz[i][j] != 0) {
      // Se atingir os limites da matriz ou encontrar uma célula já preenchida, muda a direção
      switch (direcao) {
        case 1:
          i++;
          break;
        case 2:
          j--;
          break;
        case 3:
          i--;
          break;
        case 4:
          j++;
          break;
      }
      direcao = (direcao % 4) + 1;
    }
  }

  // Imprime a matriz
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main() {

  int n, x, y;

  // Lê os dados do usuário
  scanf("%d %d %d", &n, &x, &y);

  // Cria a matriz listrada
  espiral(n, x, y);

  return 0;
}
