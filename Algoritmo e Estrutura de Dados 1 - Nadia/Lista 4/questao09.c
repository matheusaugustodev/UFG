#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    int prioridade;
    struct Node* proximo;
} Node;

typedef struct {
    Node* inicio;
} FilaPrioridade;

void criarFilaPrioridade(FilaPrioridade* fila) {
    fila->inicio = NULL;
}

void inserirNaFilaPrioridade(FilaPrioridade* fila, int valor, int prioridade) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->valor = valor;
    novoNode->prioridade = prioridade;
    novoNode->proximo = NULL;

    if (fila->inicio == NULL || prioridade < fila->inicio->prioridade) {
        novoNode->proximo = fila->inicio;
        fila->inicio = novoNode;
    } else {
        Node* atual = fila->inicio;
        while (atual->proximo != NULL && atual->proximo->prioridade <= prioridade) {
            atual = atual->proximo;
        }
        novoNode->proximo = atual->proximo;
        atual->proximo = novoNode;
    }
}

void imprimirFilaPrioridade(FilaPrioridade* fila) {
    Node* atual = fila->inicio;
    printf("Fila por prioridade: ");
    while (atual != NULL) {
        printf("(%d, %d) ", atual->valor, atual->prioridade);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite a quantidade de elementos (1 a 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    FilaPrioridade fila;
    criarFilaPrioridade(&fila);

    for (int i = 0; i < n; i++) {
        int valor, prioridade;
        printf("Digite o valor e a prioridade do elemento %d: ", i + 1);
        scanf("%d %d", &valor, &prioridade);

        if (prioridade < 0 || prioridade > 100) {
            printf("Prioridade inválida.\n");
            return 1;
        }

        inserirNaFilaPrioridade(&fila, valor, prioridade);
    }

    imprimirFilaPrioridade(&fila);

    return 0;
}