#include <stdio.h>

int main() {
    int n, i, j, lista[10001], errado;
    scanf("%d", &n);

    for (i=0; i<n; i++) scanf("%d", &lista[i]);

    errado = 0;
    j = 1;
    if (lista[0] == 1) {
        for (i=0; i<n; i++) {
            if (lista[i] != j) errado++;
            j++;
        }
    } else {
        for (i=n-1; i>=0; i--) {
            if (lista[i] != j) errado++;
            j++;
        }
    }

    if (errado > 0) printf("nao\n");
    else printf("sim\n");

    return 0;
}