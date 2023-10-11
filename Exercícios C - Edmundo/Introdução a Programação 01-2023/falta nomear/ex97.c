#include <stdio.h>

int main() {

    int n, i, j, k;
    scanf("%d", &n);
    if(n<2) {
        printf("Campeonato invalido!\n");
    } else {
        k=1;
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(i!=j && j>i) {
                    printf("Final %d: Time%d X Time%d\n", k++, i, j);
                }
            }
        }
    }

    return 0;
}
