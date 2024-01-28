#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int linha, coluna, valor;
    struct Node* prox;
} No;

typedef struct {
    No* linhas[100];
    No* colunas[100];
} MatrizEsparsa;

void inicializarMatriz(MatrizEsparsa* matriz) {
    for (int i = 0; i < 100; i++) {
        matriz->linhas[i] = NULL;
        matriz->colunas[i] = NULL;
    }
}

void inserirElemento(MatrizEsparsa* matriz, int linha, int coluna, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->valor = valor;
    novoNo->prox = NULL;

    novoNo->prox = matriz->linhas[linha];
    matriz->linhas[linha] = novoNo;

    novoNo->prox = matriz->colunas[coluna];
    matriz->colunas[coluna] = novoNo;
}

void imprimirMatriz(MatrizEsparsa* matriz, int numLinhas, int numColunas) {
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            No* noAtual = matriz->linhas[i];
            while (noAtual != NULL && noAtual->coluna < j) {
                noAtual = noAtual->prox;
            }
            if (noAtual != NULL && noAtual->coluna == j) {
                printf("%d\t", noAtual->valor);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void atribuirValor(MatrizEsparsa* matriz, int linha, int coluna, int valor) {
    No* noAtual = matriz->linhas[linha];
    while (noAtual != NULL && noAtual->coluna != coluna) {
        noAtual = noAtual->prox;
    }
    if (noAtual != NULL) {
        noAtual->valor = valor;
    } else {
        inserirElemento(matriz, linha, coluna, valor);
    }
}

int consultarValor(MatrizEsparsa* matriz, int linha, int coluna) {
    No* noAtual = matriz->linhas[linha];
    while (noAtual != NULL && noAtual->coluna != coluna) {
        noAtual = noAtual->prox;
    }
    if (noAtual != NULL) {
        return noAtual->valor;
    } else {
        return 0;
    }
}

int main() {
    MatrizEsparsa matriz;
    inicializarMatriz(&matriz);

    int numLinhas, numColunas;
    printf("Informe o número de linhas e colunas da matriz: ");
    scanf("%d %d", &numLinhas, &numColunas);

    int linha, coluna, valor;

    printf("Informe os elementos não nulos da matriz (linha coluna valor), encerre com -1 -1 -1:\n");
    while (1) {
        scanf("%d %d %d", &linha, &coluna, &valor);
        if (linha == -1 && coluna == -1 && valor == -1) {
            break;
        }
        inserirElemento(&matriz, linha, coluna, valor);
    }

    printf("\nMatriz:\n");
    imprimirMatriz(&matriz, numLinhas, numColunas);

    printf("\nInforme a posição (linha coluna) e o valor para atribuição: ");
    scanf("%d %d %d", &linha, &coluna, &valor);
    atribuirValor(&matriz, linha, coluna, valor);

    printf("\nValor na posição (%d, %d): %d\n", linha, coluna, consultarValor(&matriz, linha, coluna));

    return 0;
}