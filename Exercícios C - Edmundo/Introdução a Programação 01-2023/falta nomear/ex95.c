#include <stdio.h>

int main() {

    int n, x, x1, i, contador, maior, temp;
    scanf("%d", &n);

    i=1;
    contador = 1;
    maior = 1;
    scanf("%d", &x1);
    while(i<n) {
        scanf("%d", &x);
        if(x1==x) {
            contador++;
        } 
        
        else {
            contador = 1;
        }
        if(contador>maior) {
            maior = contador;
        }
        x1 = x;
        i++;
    }
    printf("O comprimento do segmento de numeros iguais e: %d\n", maior);

    return 0;
}
