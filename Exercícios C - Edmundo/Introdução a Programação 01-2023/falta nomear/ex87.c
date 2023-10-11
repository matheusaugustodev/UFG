#include <stdio.h>

int main() {

    int a1, r, n, i, soma;
    scanf("%d %d %d", &a1, &r, &n);
    for (i = 0; i < n; i++) {
        soma = soma + a1 + r * i;
    }
    printf("%d\n", soma);

    return 0;
}