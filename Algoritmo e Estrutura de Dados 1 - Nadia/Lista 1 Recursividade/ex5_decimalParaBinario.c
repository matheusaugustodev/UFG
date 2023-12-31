#include <stdio.h>

void decimalParaBinario(int decimal) {
    if (decimal > 0) {
        decimalParaBinario(decimal / 2);
        printf("%d", decimal % 2);
    }
}

void loop(int i, int numeroDeTestes) {
    int n;
    if (i < numeroDeTestes) {
        scanf("%d", &n);
        decimalParaBinario(n);
        printf("\n");
        i++;
        loop(i, numeroDeTestes);
    }
}

int main() {
    int k;

    scanf("%d", &k);
    loop(0, k);

    return 0;
}
