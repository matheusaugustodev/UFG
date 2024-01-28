#include <stdio.h>

int contar_ocorrencias(int array[], int tamanho, int elemento) {
    int contagem = 0, i;
    for (i = 0; i < tamanho; i++) {
        if (array[i] == elemento) {
            contagem++;
        }
    }
    return contagem;
}

int cor_predominante(int toucas[], int a, int b) {
    int contagens[b - a + 1], i;

    for (i = 0; i < b - a + 1; i++) {
        contagens[i] = contar_ocorrencias(toucas, b, toucas[i + a - 1]);
    }

    int max_ocorrencias = 0;
    int cor_max_ocorrencias = toucas[a - 1];

    for (i = 0; i < b - a + 1; i++) {
        if (contagens[i] > max_ocorrencias) {
            max_ocorrencias = contagens[i];
            cor_max_ocorrencias = toucas[i + a - 1];
        }
    }

    return cor_max_ocorrencias;
}

int main() {
    int t, caso, i;
    scanf("%d", &t);

    for (caso = 0; caso < t; caso++) {
        int n, c;
        scanf("%d %d", &n, &c);

        int toucas[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &toucas[i]);
        }

        int m;
        scanf("%d", &m);

        for (i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            int cor = cor_predominante(toucas, a, b);

            if (contar_ocorrencias(toucas, b, cor) > (b - a + 1) / 2) {
                printf("bonita %d\n", cor);
            } else {
                printf("feia\n");
            }
        }
    }

    return 0;
}
