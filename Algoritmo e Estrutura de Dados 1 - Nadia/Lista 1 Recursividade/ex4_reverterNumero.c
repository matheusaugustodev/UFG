#include <stdio.h>
#include <math.h>

int numeroReverso(int n) {
    if (n < 10) {
        return n;
    }

    int digito = n % 10;

    int reversoRestante = numeroReverso(n / 10);

    return digito * pow(10, (int)log10(reversoRestante) + 1) + reversoRestante;
}

int main() {
    int n;
    scanf("%d", &n);

    int resultado = numeroReverso(n);

    printf("%d\n", resultado);

    return 0;
}
