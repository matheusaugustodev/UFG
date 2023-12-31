#include <stdio.h>

int mostrarNumero(unsigned long int n, unsigned long int i){
    if (i>n) return (1);
    else {
        if (i==n) printf("%ld\n", i);
        else printf("%ld ", i);
        return mostrarNumero(n, ++i);
    }
}

int main() {
    unsigned long int n;
    scanf("%ld", &n);

    mostrarNumero(n, 0);

    return 0;
}