#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *pai;
} ConjuntoDisjunto;

void inicializarConjunto(ConjuntoDisjunto *conjunto, int tamanho) {
    int i;
    conjunto->pai = (int *)malloc((tamanho + 1) * sizeof(int));
    for (i = 1; i <= tamanho; i++) {
        conjunto->pai[i] = i;
    }
}

int encontrarRepresentante(ConjuntoDisjunto *conjunto, int pessoa) {
    int pai = conjunto->pai[pessoa];
    if (pai != pessoa) {
        conjunto->pai[pessoa] = pai = encontrarRepresentante(conjunto, pai);
    }
    return pai;
}

void unirConjuntos(ConjuntoDisjunto *conjunto, int pessoa1, int pessoa2) {
    int representante1 = encontrarRepresentante(conjunto, pessoa1);
    int representante2 = encontrarRepresentante(conjunto, pessoa2);

    if (representante1 != representante2) {
        conjunto->pai[representante1] = representante2;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ConjuntoDisjunto conjunto;
    inicializarConjunto(&conjunto, n);

    int i;
    for (i = 0; i < m; i++) {
        int pessoa1, pessoa2;
        scanf("%d %d", &pessoa1, &pessoa2);
        unirConjuntos(&conjunto, pessoa1, pessoa2);
    }

    int familias = 0;
    for (i = 1; i <= n; i++) {
        if (conjunto.pai[i] == i) {
            familias++;
        }
    }

    printf("%d\n", familias);

    free(conjunto.pai);

    return 0;
}
