#include <stdio.h>
int main() {
    int numerador, denominador;
    double n, temp=0;

    scanf("%lf", &n);
    temp = n;

    for (denominador = 2; denominador < 1000; denominador++) {
        n *= denominador;
        numerador = n;
        if (numerador == n) {
            printf("%d/%d\n", numerador, denominador);
            denominador = 1001;
        }
        else n = temp;
    }
    return 0;
}