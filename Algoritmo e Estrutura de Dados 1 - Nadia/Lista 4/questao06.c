#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int nL = 0;

typedef struct {
    int vetor[MAX_SIZE];
} ListaLinear;

int criarLista(ListaLinear *lista) {
    nL = 0;
    return 0;
}

int inserirFinal(ListaLinear *lista, int x) {
    if (nL < MAX_SIZE) {
        lista->vetor[nL] = x;
        nL++;
        return 0;
    } else {
        return -1;
    }
}

int inserirInicio(ListaLinear *lista, int x) {
    int i;
    if (nL < MAX_SIZE) {
        for (i = nL; i > 0; i--) {
            lista->vetor[i] = lista->vetor[i - 1];
        }
        lista->vetor[0] = x;
        nL++;
        return 0;
    } else {
        return -1;
    }
}

int removerFinal(ListaLinear *lista) {
    if (nL > 0) {
        nL--;
        return 0;
    } else {
        return -1;
    }
}

int removerInicio(ListaLinear *lista) {
    int i;
    if (nL > 0) {
        for (i = 0; i < nL - 1; i++) {
            lista->vetor[i] = lista->vetor[i + 1];
        }
        nL--;
        return 0;
    } else {
        return -1;
    }
}

void mostrarLista(ListaLinear *lista) {
    int i;
    printf("Lista: ");
    for (i = 0; i < nL; i++) {
        printf("%d ", lista->vetor[i]);
    }
    printf("\n");
}

int quantidadeElementos() {
    return nL;
}

int primeiroElemento(ListaLinear *lista) {
    if (nL > 0) {
        return lista->vetor[0];
    } else {
        return -1;
    }
}

int ultimoElemento(ListaLinear *lista) {
    if (nL > 0) {
        return lista->vetor[nL - 1];
    } else {
        return -1;
    }
}

int main() {
    ListaLinear lista;
    criarLista(&lista);

    inserirFinal(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFinal(&lista, 20);

    mostrarLista(&lista);

    printf("Quantidade de números inteiros existentes na lista: %d\n", quantidadeElementos());
    printf("Primeiro elemento: %d\n", primeiroElemento(&lista));
    printf("Último elemento: %d\n", ultimoElemento(&lista));

    removerInicio(&lista);
    removerFinal(&lista);

    mostrarLista(&lista);

    return 0;
}