#include <stdio.h>

int main() {
    
    int vetor[1000], n, k, i, valorTeste, achei, contador;
    contador = 0;

    scanf("%d", &n);
    while(n<1 || n>1000) {
        scanf("%d", &n);
    }
    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d", &k);
    for(i = 0; i < n; i++) {
        achei = 0;
        if(vetor[i] >= k) {
            achei = 1;
        }
        if(achei == 1) {
            contador++;
        }
    }
    printf("%d\n", contador);

    return 0;
}
