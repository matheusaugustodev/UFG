#include <stdio.h>

void moverDisco(int n, char origem, char destino) {
    printf("(%c,%c)\n", origem, destino);
}

void torreHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        moverDisco(1, origem, destino);
        return;
    }

    torreHanoi(n - 1, origem, auxiliar, destino);
    moverDisco(n, origem, destino);
    torreHanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;
    scanf("%d", &n);

    char origem = 'O';
    char destino = 'D';
    char auxiliar = 'A';

    torreHanoi(n, origem, destino, auxiliar);

    return 0;
}
