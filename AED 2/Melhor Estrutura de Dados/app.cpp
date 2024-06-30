//Código Feito por Marcello Ronald e Matheus Augusto
//Tempo médio esperado 11s - 13s

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// heapify
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Inicia largest como raiz
    int l = 2 * i + 1; // Esquerda = 2 * i + 1
    int r = 2 * i + 2; // Direita = 2 * i + 2
    
    // Se o filho da esquerda for maior que a raiz
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    
    // Se o filho da direita for maior que a raiz
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    
    // Se largest não é raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, largest);
    }
}

// heapSort
void heapSort(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {

    // Medir o tempo
    clock_t start, end;
    start = clock();

    //Lê o arquivo
    ifstream randomNumbersFile("RandomNumbers.txt");

    //Checagem
    if (!randomNumbersFile.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    vector<int> numbers;
    int num;

    while (randomNumbersFile >> num) {
        numbers.push_back(num);
    }

    randomNumbersFile.close();

    int n = numbers.size();
    heapSort(numbers, n);

    //Cria o arquivo para escrita
    ofstream sortedNumbersFile("SortedNumbers.txt");

    if (!sortedNumbersFile.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita" << endl;
        return 1;
    }

    // Escreve em outro arquivo os números ordenados
    for (int i = 0; i < n; i++) {
        sortedNumbersFile << numbers[i] << endl;
    }

    sortedNumbersFile.close();
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Tempo de execucao: " << time_taken << "s" << endl;

    return 0;
}