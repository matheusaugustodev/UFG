#include <stdio.h>

int main() {

    int n, quadrado;
    int i = 1, valor = 2;
    scanf("%d", &n);
    while (i<=n) {
        printf("%d^2 = %d\n", valor, valor*valor);
        if(valor+2<=n) {
            valor = valor + 2;
        }
            i=i+2;
    }
    return 0;
}
