#include <stdio.h>

int main()
{
    int numDeTestes, i, posicaoVetor, numeroAtual, quantidadeDivisores, posicaoSolicitada, j, primosSolicitados[10000], primos[10000], somaTotal=0, posicaoPrimo=0, temp;

    scanf("%d", &numDeTestes);

    for (i=0; i<numDeTestes; i++) {
        posicaoVetor=0;
        numeroAtual=2;
        scanf("%d", &posicaoSolicitada);
        
        while (posicaoVetor < posicaoSolicitada) {
            
            quantidadeDivisores=0;

            for (j=1; j<=numeroAtual; j++) {
                if (numeroAtual % j == 0) quantidadeDivisores++;
            }

            if (quantidadeDivisores == 2) primos[posicaoVetor++] = numeroAtual;
            
            numeroAtual++;
        }
        
        primosSolicitados[posicaoPrimo++] = primos[posicaoVetor-1];
    }

    for (i=0; i<posicaoPrimo; i++) {
        for (j= i+1; j<posicaoPrimo; j++) {
            if (primosSolicitados[i] > primosSolicitados[j]) {
                temp = primosSolicitados[i];
                primosSolicitados[i] = primosSolicitados[j];
                primosSolicitados[j] = temp;
            }
        }
    }

    for (i=0; i<posicaoPrimo; i++) {
        printf("%d", primosSolicitados[i]);
        if (i != posicaoPrimo-1) printf(" ");
        else printf("\n");
        somaTotal += primosSolicitados[i];
    }
    printf("%d\n", somaTotal);

    return 0;
}
