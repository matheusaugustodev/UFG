#include <stdio.h>

int main()
{
    int vetor[1000000], n, i, j, frequencia[1000000], menorNumero, maiorFrequencia;
    
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
    }
    for(i=0; i<n; i++) {
        frequencia[i] = 0;
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(vetor[i]==vetor[j]) {
                frequencia[i]++;
            }
        }
    }
    maiorFrequencia = -999999;
    for(i=0; i<n; i++) {
        if(frequencia[i]>maiorFrequencia) {
            maiorFrequencia = frequencia[i];
        }
    }
    menorNumero = 999999;
    for(i=0; i<n; i++) {
        if(frequencia[i]==maiorFrequencia) {
            if(vetor[i]<menorNumero) {
                menorNumero=vetor[i];
            }            
        }

    }
    printf("%d\n%d\n", menorNumero, maiorFrequencia);



    return 0;
}