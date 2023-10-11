#include <stdio.h>

int main() {

    int n;
    double soma;
    float i;
    scanf("%d", &n);
    if(n<=1) {
        printf("Numero invalido!\n");
    } else {
        for(i=1; i<=n; i++) {
            soma = soma + (1/i);
        }
        printf("%.6lf\n", soma);
    }

    return 0;
}