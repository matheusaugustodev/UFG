#include <stdio.h>

int main() {

    int numCasosTeste, i, posicaoArrayPrimos, numeroAtual, contDivisores, posicaoSolicitada, j, primosSolicitados[10000], primos[10000], somaTotal = 0, posicaoPrimo = 0, temp;

    scanf("%d", &numCasosTeste);

    for (i = 0; i < numCasosTeste; i++) {
        posicaoArrayPrimos = 0;
        numeroAtual = 2;
        scanf("%d", &posicaoSolicitada);

        while (posicaoArrayPrimos < posicaoSolicitada) {
            contDivisores = 0;

            for (j = 1; j <= numeroAtual; j++) {
                if (numeroAtual % j == 0) {
                    contDivisores++;
                }
            }

            if (contDivisores == 2) {
                primos[posicaoArrayPrimos++] = numeroAtual;
            }

            numeroAtual++;
        }

        primosSolicitados[posicaoPrimo++] = primos[posicaoArrayPrimos - 1];
    }

    for (i = 0; i < posicaoPrimo; i++) {
        for (j = i + 1; j < posicaoPrimo; j++) {
            if (primosSolicitados[i] > primosSolicitados[j]) {
                temp = primosSolicitados[i];
                primosSolicitados[i] = primosSolicitados[j];
                primosSolicitados[j] = temp;
            }
        }
    }
    
    for (i = 0; i < posicaoPrimo; i++) {
        printf("%d", primosSolicitados[i]);

        if (i != posicaoPrimo - 1) {
            printf(" ");
        } else {
            printf("\n");
        }

        somaTotal += primosSolicitados[i];
    }

    printf("%d\n", somaTotal);

    return 0;
}
