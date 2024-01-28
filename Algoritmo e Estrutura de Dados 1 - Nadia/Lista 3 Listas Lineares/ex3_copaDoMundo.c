#include <stdio.h>

void removerDaFila(int fila[], int *tamFila, int pessoa) {
    int i, j;

    for (i = 0; i < *tamFila; i++) {
        if (fila[i] == pessoa) {
            for (j = i; j < *tamFila - 1; j++) {
                fila[j] = fila[j + 1];
            }
            (*tamFila)--;
            break;
        }
    }
}

int main() {
    int n, s, i;
    scanf("%d", &n);

    int fila[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &s);
    for (i = 0; i < s; i++) {
        int pessoa;
        scanf("%d", &pessoa);

        removerDaFila(fila, &n, pessoa);
    }

    for (i = 0; i < n; i++) {
        if (i<n-1) printf("%d ", fila[i]);
        else printf("%d\n", fila[i]);
    }

    return 0;
}
