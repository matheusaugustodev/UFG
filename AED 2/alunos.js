//Software de cadastro de alunos utilizando árvores binárias de busca

//Exemplo de árvore binária apenas para teste
const arvore = {
    aluno: {
        matricula: 1,
        nome: "João",
        curso: "Engenharia de Software",
        notas: [8, 9, 10]
    },
    esquerda: {
        aluno: {
            matricula: 2,
            nome: "Maria",
            curso: "Engenharia de Software",
            notas: [7, 8, 9]
        },
        esquerda: null,
        direita: null
    },
    direita: {
        aluno: {
            matricula: 3,
            nome: "José",
            curso: "Engenharia de Software",
            notas: [6, 7, 8]
        },
        esquerda: null,
        direita: null
    }
}
ImprimirAlunos("pre", arvore)


console.log(arvore)

function criarArvore(aluno) {
    if (aluno == null) {
        return null    
    } else {
        return {
            aluno: aluno,
            esquerda: null,
            direita: null
        }
    }
}

function preOrdem(no) {
    if (no != null) {
        preOrdem(no.esquerda)
        console.log(no.aluno)
        preOrdem(no.direita)
    }
}

function posOrdem(no) {
    if (no != null) {
        posOrdem(no.esquerda)
        posOrdem(no.direita)
        console.log(no.aluno)
    }
}

function emOrdem(no) {
    if (no != null) {
        console.log(no.aluno)
        emOrdem(no.esquerda)
        emOrdem(no.direita)
    }
}

function ImprimirAlunos(metodo, arvore) {
    if (metodo == "pre") {
        console.log("Impressão dos alunos em pré-ordem\n")
        preOrdem(arvore)
    } else if (metodo == "pos") {
        console.log("Impressão dos alunos em pós-ordem\n")
        posOrdem(arvore)
    } else if (metodo == "em") {
        console.log("Impressão dos alunos em ordem\n")
        emOrdem(arvore)
    } else if (metodo == "interativo") {
        console.log("Impressão dos alunos de forma iterativa\n")
        ImprimirAlunosFormaIterativa(arvore)
    } else if (metodo == "profundidade") {
        console.log("Impressão dos alunos em busca em profundidade\n")
        BuscaEmProfundidade(arvore)
    }
}

function ImprimirAlunosFormaIterativa(arvore) {
    const pilha = [] //pilha de nós
    let no = arvore //nó atual 

    //Enquanto o nó não for nulo ou a pilha não estiver vazia empilhe o nó e vá para a esquerda, se não desempilhe o nó e vá para a direita, imprimindo assim os nós
    while (no != null || pilha.length > 0) {
        while (no != null) {
            pilha.push(no)
            no = no.esquerda
        }
        no = pilha.pop()
        console.log(no.aluno)
        no = no.direita
    }
}

function BuscaEmProfundidade(no) {
    if (no == null) {
        return
    }
    console.log(no.aluno)
    BuscaEmProfundidade(no.esquerda)
    BuscaEmProfundidade(no.direita)
}

// 4. Deletar um registro da árvore binária de busca, mas mantendo-a como árvore binária de busca.
function DeletarAluno(matricula, arvore) {

    if (arvore == null) {
        return null
    }
    
    if (matricula < arvore.aluno.matricula) {
        arvore.esquerda = DeletarAluno(matricula, arvore.esquerda)
    } else if (matricula > arvore.aluno.matricula) {
        arvore.direita = DeletarAluno(matricula, arvore.direita)
    } else {
        // Caso 1 e 2: Nó a ser deletado é uma folha ou tem apenas um filho
        if (arvore.esquerda == null) {
            return arvore.direita
        } else if (arvore.direita == null) {
            return arvore.esquerda
        }
        // Caso 3: Nó a ser deletado tem dois filhos
        // Encontrar o nó sucessor na subárvore direita
        const sucessor = EncontrarMinimo(arvore.direita)
        // Atualizar os campos do nó a ser deletado com os valores do sucessor
        arvore.aluno = {...sucessor.aluno}
        // Remover o nó sucessor da subárvore direita
        arvore.direita = DeletarAluno(sucessor.matricula, arvore.direita)
    }
}

function EncontrarMinimo(no) {
    while (no.esquerda != null) {
        no = no.esquerda
    }
    return no.aluno
}

function InserirAluno(aluno, arvore) {
    if (arvore == null) {
        arvore = {
            aluno: aluno,
            esquerda: null,
            direita: null
        }
    } else {
        if (aluno.matricula < arvore.aluno.matricula) {
            arvore.esquerda = InserirAluno(aluno, arvore.esquerda)
        } else {
            arvore.direita = InserirAluno(aluno, arvore.direita)
        }
    }
    return arvore
}

function Merge(arvore1, arvore2) {
    if (arvore1 == null) {
        return arvore2
    }
    if (arvore2 == null) {
        return arvore1
    }
    arvore1.esquerda = Merge(arvore1.esquerda, arvore2)
    arvore1.direita = Merge(arvore1.direita, arvore2)
    return arvore1
}

function Copy(arvore) {
    if (arvore == null) {
        return null
    }
    let novoNo = {
        aluno: arvore.aluno,
        esquerda: Copy(arvore.esquerda),
        direita: Copy(arvore.direita)
    }
    return novoNo
}

function Mirror(arvore) {
    if (arvore == null) {
        return null
    }
    let novoNo = {
        aluno: arvore.aluno,
        esquerda: Mirror(arvore.direita),
        direita: Mirror(arvore.esquerda)
    }
    return novoNo
}

function Compare(arvore1, arvore2) {
    if (arvore1 == null && arvore2 == null) {
        return true
    }
    if (arvore1 == null || arvore2 == null) {
        return false
    }
    return arvore1.aluno.matricula == arvore2.aluno.matricula &&
        Compare(arvore1.esquerda, arvore2.esquerda) &&
        Compare(arvore1.direita, arvore2.direita)
}


// //Testes

// ImprimirAlunos("pre", arvore)
// ImprimirAlunos("pos", arvore)
// ImprimirAlunos("em", arvore)
// ImprimirAlunos("interativo", arvore)
// ImprimirAlunos("profundidade", arvore)

// DeletarAluno(2, arvore)
// ImprimirAlunos("pre", arvore)

// const alunoParaInserir = {
//     matricula: 4,
//     nome: "Ana",
//     curso: "Engenharia de Software",
//     notas: [5, 6, 7]
// }
// InserirAluno(alunoParaInserir, arvore)
// ImprimirAlunos("pre", arvore)

// console.log("\nMerge entre duas árvores\n")
// const arvore2 = {
//     aluno: {
//         matricula: 5,
//         nome: "Carlos",
//         curso: "Engenharia de Software",
//         notas: [4, 5, 6]
//     },
//     esquerda: null,
//     direita: null
// }
// const arvore3 = Merge(arvore, arvore2)
// ImprimirAlunos("pre", arvore3)

// console.log(arvore3)

// console.log("\nCópia de uma árvore\n")
// const arvore4 = Copy(arvore)
// ImprimirAlunos("pre", arvore4)

// console.log("\nMirror de uma árvore\n")
// const arvore5 = Mirror(arvore)
// ImprimirAlunos("pre", arvore5)

// console.log("\nComparação entre duas árvores\n")
// console.log(Compare(arvore, arvore4))
// console.log(Compare(arvore, arvore5))
// console.log(Compare(arvore, arvore3))