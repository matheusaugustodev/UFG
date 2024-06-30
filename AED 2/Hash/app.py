import time
import random

def funcaoHash(valor):
    return valor % 1000

class HashTable:
    def __init__(self, tamanho):
        self.tamanho = tamanho
        self.tabela = [[] for _ in range(tamanho)]

    def inserir(self, valor):
        hash_index = funcaoHash(valor)
        if valor not in self.tabela[hash_index]:
            self.tabela[hash_index].append(valor)

    def buscar(self, value):
        hash_index = funcaoHash(value)
        if value in self.tabela[hash_index]:
            return hash_index
        return -1

def main():
    
    tempoInicial = time.time()
    tabelaHash = HashTable(1000)

    with open('RandomNumbers.txt', 'r') as arquivo:
        for linha in arquivo:
            numeroDaLinha = int(linha.strip())
            tabelaHash.inserir(numeroDaLinha)

    numerosAleatorios = [random.randint(0, 10000000) for _ in range(100)]
    resultados = {}
    for numeroDaLinha in numerosAleatorios:
        posicao = tabelaHash.buscar(numeroDaLinha)
        resultados[numeroDaLinha] = posicao

    tempoFinal = time.time()

    # Exibindo os resultados
    for numeroDaLinha, posicao in resultados.items():
        if posicao != -1:
            print(f'O número {numeroDaLinha} está armazenado na posição {posicao}.')
        else:
            print(f'O número {numeroDaLinha} não está armazenado.')

    tempoExecucao = tempoFinal - tempoInicial
    print(f'Tempo de execução: {tempoExecucao:.6f} segundos')

if __name__ == "__main__":
    main()