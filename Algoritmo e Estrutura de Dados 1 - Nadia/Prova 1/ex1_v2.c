#include <stdio.h>

void vertical(int linha, int coluna, int n, int x, int y) {

    if (linha == 0 || linha == n-1 || coluna == 0 || coluna == n-1 || (coluna%2 == 0 && linha<n - 1 - coluna/2 && linha > coluna/2) || (linha%2 == 0 && coluna<n - 1 - linha/2 && coluna > linha/2))
        printf("%d", x);
    else
        printf("%d", y);

    // organiza espaços
    if (coluna != n-1) printf(" ");
}

void horizontal(int linha, int coluna, int n, int x, int y) {

    if (linha < n) {
        vertical(linha, coluna, n, x, y);

        if (coluna != n-1) {
            horizontal(linha, coluna + 1, n, x, y);
        } else {
            printf("\n");
            horizontal(linha + 1, 0, n, x, y);
        }
    }
}

int main() {
    int n, x, y, i, j, matriz[10][10];
    scanf("%d %d %d", &n, &x, &y);

    horizontal(0, 0, n, x, y);

    return 0;
}
