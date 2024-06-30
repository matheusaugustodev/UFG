//Código Feito por Marcello Ronald e Matheus Augusto
//Tempo médio esperado 0,7 segundos

const fs = require('fs')
const readline = require('readline')

function funcaoHash(valor) {
    return valor % 1000
}

class TabelaHash {
    constructor(tamanho) {
        this.tamanho = tamanho
        this.tabela = Array.from({ length: tamanho }, () => [])
    }

    inserir(valor) {
        const indiceHash = funcaoHash(valor)
        if (!this.tabela[indiceHash].includes(valor)) {
            this.tabela[indiceHash].push(valor)
        }
    }

    buscar(valor) {
        const hashIndex = funcaoHash(valor)
        if (this.tabela[hashIndex].includes(valor)) {
            return hashIndex
        }
        return -1
    }
}

async function main() {
    
    const tempoInicial = Date.now()

    const tabelaHash = new TabelaHash(1000)

    const fileStream = fs.createReadStream('RandomNumbers.txt')
    const rl = readline.createInterface({
        input: fileStream,
        crlfDelay: Infinity
    })

    for await (const linha of rl) {
        const numeroDaLinha = parseInt(linha.trim(), 10)
        tabelaHash.inserir(numeroDaLinha)
    }

    const numerosAleatorios = Array.from({ length: 100 }, () => Math.floor(Math.random() * 10000000))
    const resultados = {}
    numerosAleatorios.forEach(numero => {
        const posicao = tabelaHash.buscar(numero)
        resultados[numero] = posicao
    })

    const tempoFinal = Date.now()

    for (const [numeroDaLinha, posicao] of Object.entries(resultados)) {
        if (posicao !== -1) {
            console.log(`${numeroDaLinha} está armazenado na posição ${posicao}`)
        } else {
            console.log(`${numeroDaLinha} não está armazenado`)
        }
    }

    const tempoExecucao = ((tempoFinal - tempoInicial) / 1000).toFixed(6)
    console.log(`Tempo de execução: ${tempoExecucao} segundos`)
}

main()