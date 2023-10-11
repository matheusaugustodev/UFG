#include <stdio.h>

int main() {

    int valores, n, i=1, contador = 0;
    scanf("%d", &n);
    while(i<=n) {
        scanf("%d", &valores);
        if(valores%2==0) {
            contador++;
            printf("%d ", valores);
        }
        i++;
    }
    printf("%d\n", contador);

    return 0;
}
