#include <stdio.h>

void exibirNumerosNaturais(int n, int maior) {
    if (n == maior) {
        printf("%d\n", n);
    } else {
        printf("%d ", n);
        exibirNumerosNaturais(++n, maior);
    }
}

int main() {
    int numero;

    scanf("%d", &numero);

    exibirNumerosNaturais(1, numero);

    return 0;
}
