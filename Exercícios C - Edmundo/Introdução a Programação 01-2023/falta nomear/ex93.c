#include <stdio.h>

int main() {

    double valorInicial, taxaJuros, renda, valor;
    int numMes, i;
    scanf("%lf %lf %d", &valorInicial, &taxaJuros, &numMes);
    valor = valorInicial;
    for(i=1; i<=numMes; i++) {
        valor = valor*(1+taxaJuros);
        renda = valor - valorInicial;
        printf("a*(1+r)^%d = %.2lf, renda: %.2lf\n", i, valor, renda);
    }

    return 0;
}
