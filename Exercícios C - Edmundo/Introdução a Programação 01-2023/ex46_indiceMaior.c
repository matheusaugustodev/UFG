#include <stdio.h>

int main() {
    int N=-1;
    while (N != 0) {
        scanf("%d", &N);

    	if (N<=10000 && N>=1) {
            int vetor[N], i, maior, indice;
    
            for (i = 0; i < N; i++) {
                scanf("%d", &vetor[i]);
            }
    
            maior = vetor[0];
            indice = 0;
    
            for (i = 1; i < N; i++) {
                if (vetor[i] > maior) {
                    maior = vetor[i];
                    indice = i;
                }
            }
    
            printf("%d %d\n", indice, maior);
        }
    }

    return 0;
}