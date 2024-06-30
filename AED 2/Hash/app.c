#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABELA 1000

typedef struct Node {
    int dado;
    struct Node* proximo;
} Node;

typedef struct TabelaHash {
    Node* tabela[TAMANHO_TABELA];
} TabelaHash;

int funcaoHash(int valor) {
    return valor % TAMANHO_TABELA;
}

TabelaHash* criarTabela() {
    TabelaHash* tabelaHash = (TabelaHash*)malloc(sizeof(TabelaHash));
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash->tabela[i] = NULL;
    }
    return tabelaHash;
}

void inserir(TabelaHash* tabelaHash, int valor) {
    int indiceHash = funcaoHash(valor);
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->dado = valor;
    novoNode->proximo = tabelaHash->tabela[indiceHash];
    tabelaHash->tabela[indiceHash] = novoNode;
}

int buscar(TabelaHash* tabelaHash, int valor) {
    int indiceHash = funcaoHash(valor);
    Node* atual = tabelaHash->tabela[indiceHash];
    while (atual != NULL) {
        if (atual->dado == valor) {
            return indiceHash;
        }
        atual = atual->proximo;
    }
    return -1;
}

void liberarTabela(TabelaHash* tabelaHash) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Node* atual = tabelaHash->tabela[i];
        while (atual != NULL) {
            Node* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(tabelaHash);
}

int main() {

    clock_t tempoInicio = clock();

    TabelaHash* tabelaHash = criarTabela();

    FILE* arquivo = fopen("RandomNumbers.txt", "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numero;
    while (fscanf(arquivo, "%d", &numero) != EOF) {
        inserir(tabelaHash, numero);
    }
    fclose(arquivo);

    // Gerando 100 numeros aleatórios e buscando na tabela hash
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int numeroAleatorio = rand() % 10000000;
        int posicao = buscar(tabelaHash, numeroAleatorio);
        if (posicao != -1) {
            printf("O numero %d esta armazenado na posicao %d.\n", numeroAleatorio, posicao);
        } else {
            printf("O numero %d nao esta armazenado.\n", numeroAleatorio);
        }
    }

    clock_t tempoFim = clock();

    double tempoExecucao = ((double)(tempoFim - tempoInicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.6f segundos\n", tempoExecucao);

    return 0;
}
