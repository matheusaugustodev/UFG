//Código Feito por Marcello Ronald e Matheus Augusto

const fs = require('fs')
const readline = require('readline')

function lerMatriz(nomeArquivo) {
    const data = fs.readFileSync(nomeArquivo, 'utf8')
    const linhas = data.split('\n')
    const matriz = linhas.map(linha => linha.trim().split(' ').map(Number))
    return matriz
}

function dijkstra(grafo, inicio, fim) {
    
    const tamanhoGrafo = grafo.length

    const distancias = new Array(tamanhoGrafo).fill(Infinity)
    const visitou = new Array(tamanhoGrafo).fill(false)
    const anterior = new Array(tamanhoGrafo).fill(null)

    distancias[inicio] = 0

    for (let i = 0; i < tamanhoGrafo - 1; i++) {

        let distanciaMinima = Infinity
        let u = -1

        for (let v = 0; v < tamanhoGrafo; v++) {
            if (!visitou[v] && distancias[v] < distanciaMinima) {
                distanciaMinima = distancias[v]
                u = v
            }
        }

        if (u === -1) break
        visitou[u] = true

        for (let v = 0; v < tamanhoGrafo; v++) {
            if (!visitou[v] && grafo[u][v] !== 0 && distancias[u] + grafo[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + grafo[u][v]
                anterior[v] = u
            }
        }
    }

    const caminho = []
    for (let at = fim; at !== null; at = anterior[at]) {
        caminho.push(at)
    }
    caminho.reverse()

    return { distance: distancias[fim], caminho: caminho.length > 1 ? caminho : null }
}

async function montarPrompt(texto) {
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })

    return new Promise(resolve => rl.question(texto, resposta => {
        rl.close()
        resolve(resposta)
    }))
}

async function main() {

    const matriz = lerMatriz('AdjacencyMatrix.txt')

    const origem = parseInt(await montarPrompt('Informe o nó de origem (inteiro): '), 10)
    const destino = parseInt(await montarPrompt('Informe o nó de destino (inteiro): '), 10)

    const resultado = dijkstra(matriz, origem, destino)
    
    if (resultado.caminho) {
        console.log(`Caminho de menor custo do nó ${origem} para o nó ${destino}:`)
        console.log(resultado.caminho.join(' -> '))
        console.log(`Custo total: ${resultado.distance}`)
    } else {
        console.log(`Não há caminho disponível do nó ${origem} para o nó ${destino}`)
    }
}

main()