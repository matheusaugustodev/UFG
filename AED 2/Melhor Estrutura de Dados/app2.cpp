#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

/*

    -Descrição breve:
    Código por: Marcello Ronald e Matheus Augusto
    Foi utilizada uma árvore binária de busca (BST) como ED.
    Os números são lidos do arquivo e inseridos na BST.
    A função inOrderTraversal é usada para percorrer a BST em ordem, garantindo que os números sejam escritos em ordem no arquivo de saída.

    -Complexidade do tempo:

    O(log n) para inserir um nó na árvore binária de busca.
    O(n) para percorrer a árvore em ordem.

    -Requisitos propostos:
    1. Produzir um programa que leia o arquivo "RandomNumbers.txt" (Feito)
    2. Ordenar os números lidos (Feito)
    3. Gravar em outro arquivo, chamamos de "SortedNumbers.txt", ou seja, números ordenados (Feito)
    4. Medir o tempo de execução do programa (Feito)
    5. Usar apenas estruturas de dados vistas em aula (Feito), nesse caso, a árvore binária de busca.

*/

// Definição do nó da árvore binária de busca
struct No {
    int dado;
    No* esquerda;
    No* direita;
    No(int valor) : dado(valor), esquerda(nullptr), direita(nullptr) {}
};

// Função para inserir um novo nó na árvore
No* inserir(No* raiz, int dado) {
    if (raiz == nullptr) {
        return new No(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

// Função para percorrer a árvore em ordem e escrever os dados em um arquivo
void percorrerEmOrdem(No* raiz, ofstream& arquivoSaida) {
    if (raiz != nullptr) {
        percorrerEmOrdem(raiz->esquerda, arquivoSaida);
        arquivoSaida << raiz->dado << endl;
        percorrerEmOrdem(raiz->direita, arquivoSaida);
    }
}

// Função principal
int main() {
    // Medir o tempo
    clock_t inicio, fim;
    inicio = clock();

    // Ler o arquivo
    ifstream arquivoNumerosAleatorios("RandomNumbers.txt");

    // Checagem
    if (!arquivoNumerosAleatorios.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    No* raiz = nullptr;
    int num;

    while (arquivoNumerosAleatorios >> num) {
        raiz = inserir(raiz, num);
    }

    arquivoNumerosAleatorios.close();

    // Criar o arquivo para escrita
    ofstream arquivoNumerosOrdenados("SortedNumbers.txt");

    if (!arquivoNumerosOrdenados.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita" << endl;
        return 1;
    }

    // Percorrer a árvore em ordem e escrever os números ordenados
    percorrerEmOrdem(raiz, arquivoNumerosOrdenados);

    arquivoNumerosOrdenados.close();

    // Medir o tempo
    fim = clock();
    double tempo_execucao = double(fim - inicio) / double(CLOCKS_PER_SEC);

    cout << "Tempo de execucao: " << tempo_execucao << "s" << endl;

    return 0;
}