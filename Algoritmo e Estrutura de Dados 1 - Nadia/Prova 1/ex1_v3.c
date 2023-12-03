#include <stdio.h>

int main() {

    int n, x, y, a, b, i, j;
    scanf("%d %d %d", &n, &x, &y);

    int matriz[n][n], linha, coluna;

    for (a=0; a<n; a++) {
        for (b=0; b<n; b++) matriz[a][b] = y;
    }

    for (i=0; i<n; i++) {

        for (j=0; j<n; j++) {

            for (a=0; a<n; a++) {

                for (b=0; b<n; b++) {

                }

            }

        }

    }

    linha=0;
    while (linha != -1) {
        coluna=0;

        while (coluna != -1) {
            if (linha%2 == 0) {
                matriz[linha][coluna] = x;
            }
            coluna++;
        }
    }

    return 0;
}
