#include <stdio.h>

int contarManeiras(int valor, int notas[]) {
    int dp[valor + 1], i, j;
    dp[0] = 1;

    for (i = 1; i <= valor; i++) {
        dp[i] = 0;
    }

    for (i = 0; i < 6; i++) {
        for (j = notas[i]; j <= valor; j++) {
            dp[j] += dp[j - notas[i]];
        }
    }

    return dp[valor];
}

int main() {
    int valor, notas[6], i, maneiras;

    scanf("%d", &valor);
    for (i = 0; i < 6; i++) {
        scanf("%d", &notas[i]);
    }

    maneiras = contarManeiras(valor, notas);

    if (maneiras > 0 && valor % notas[0] == 0) {
        printf("%d\n", maneiras);
    } else {
        printf("0\n");
    }

    return 0;
}
