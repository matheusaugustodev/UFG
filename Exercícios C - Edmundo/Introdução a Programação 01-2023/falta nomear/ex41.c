#include <stdio.h>

int main() {
    int vetor[100000], n, m, i, j, valorTeste, achei;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &valorTeste);
        achei = 0;
        for(j = 0; j < n; j++) { 
            if(vetor[j] == valorTeste) {
                achei = 1;
            }
        }
        if(achei == 1) {
            printf("ACHEI\n");
        } else {
            printf("NAO ACHEI\n");
        }
    }

    return 0;
}
