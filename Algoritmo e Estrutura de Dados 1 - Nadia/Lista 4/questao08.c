#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Pilha;

void criarPilha(Pilha* p) {
    p->top = NULL;
}

void empilhar(Pilha* p, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = x;
    newNode->next = p->top;
    p->top = newNode;
}

int desempilhar(Pilha* p) {
    if (p->top == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = p->top;
    int x = temp->data;
    p->top = temp->next;
    free(temp);
    return x;
}

int estaVazia(Pilha* p) {
    return p->top == NULL;
}

void removeChave(Pilha* p, int x) {
    Pilha tempPilha;
    criarPilha(&tempPilha);

    while (!estaVazia(p)) {
        int elemento = desempilhar(p);
        if (elemento != x) {
            empilhar(&tempPilha, elemento);
        }
    }

    while (!estaVazia(&tempPilha)) {
        int elemento = desempilhar(&tempPilha);
        empilhar(p, elemento);
    }
}

void imprimirPilha(Pilha* p) {
    Node* current = p->top;
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Pilha minhaPilha;
    criarPilha(&minhaPilha);

    empilhar(&minhaPilha, 10);
    empilhar(&minhaPilha, 20);
    empilhar(&minhaPilha, 30);
    empilhar(&minhaPilha, 40);

    imprimirPilha(&minhaPilha);

    int chaveRemover = 20;
    removeChave(&minhaPilha, chaveRemover);

    printf("Remover chave %d...\n", chaveRemover);
    imprimirPilha(&minhaPilha);

    return 0;
}