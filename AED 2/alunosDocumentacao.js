//Software de cadastro de alunos utilizando árvores binárias de busca
//Atividade Realizada por Marcello Ronald - 202302618, e Matheus Augusto

class Aluno {
    constructor(aluno) {
        this.aluno = aluno;
        this.esquerda = null;
        this.direita = null;
    }
}

function criarArvore(aluno) {
    if (aluno == null) {
        return null    
    } else {
        return new Aluno(aluno)
    }
}

function preOrdem(no) {
    if (no != null) {
        console.log(no.aluno)
        preOrdem(no.esquerda)
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
        emOrdem(no.esquerda)
        console.log(no.aluno)
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

    //Se a árvore tiver apenas a raiz, a raiz é deletada
    if (arvore.esquerda == null && arvore.direita == null) {
        return null
    }
    else if (matricula < arvore.aluno.matricula) {
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
// Descrição: a função DeletarAluno recebe a matrícula do aluno a ser removido e a árvore de onde vai ser removido 
/*
1. Se a árvore estiver vazia, retorne null
2. Se a árvore tiver apenas a raiz, retorne null
3. Se a matrícula do aluno for menor que a matrícula do nó atual, chame a função recursivamente para a subárvore esquerda
4. Se a matrícula do aluno for maior que a matrícula do nó atual, chame a função recursivamente para a subárvore direita
5. Se a matrícula do aluno for igual à matrícula do nó atual, verifique os casos:
    5.1. Se o nó a ser deletado não tiver filho à esquerda, retorne o filho à direita
    5.2. Se o nó a ser deletado não tiver filho à direita, retorne o filho à esquerda
    5.3. Se o nó a ser deletado tiver dois filhos, encontre o nó sucessor na subárvore direita, atualize os campos do nó a ser deletado com os valores do sucessor e remova o nó sucessor da subárvore direita
6. Retorne a árvore atualizada


*/

function EncontrarMinimo(no) {
    while (no.esquerda != null) {
        no = no.esquerda
    }
    return no.aluno
}

//Agora vamos implementar a função de inserção de um aluno na árvore apartir do nó pai analisado (caso não seja a raiz) e com base na matrícula do aluno ele
//Será inserido na esquerda ou direita do nó pai retornando recursivamente a árvore com o novo nó inserido
function InserirAluno(raiz, aluno) {
    if (raiz == null) {
        return criarArvore(aluno); // Se a raiz estiver vazia, crie um novo nó com o aluno
    }

    // Verifique se o aluno deve ser inserido à esquerda ou à direita da raiz atual
    if (aluno.matricula < raiz.aluno.matricula) {
        raiz.esquerda = InserirAluno(raiz.esquerda, aluno); // Insira à esquerda
    } else if (aluno.matricula > raiz.aluno.matricula) {
        raiz.direita = InserirAluno(raiz.direita, aluno); // Insira à direita
    }

    // Retorne a raiz atual (não modificada, a menos que a inserção tenha ocorrido)
    return raiz;
}
// Descrição: a função InserirAluno recebe a raiz da árvore e o aluno a ser inserido
/*
1. Se a raiz estiver vazia, crie um novo nó com o aluno e retorne
2. Verifique se o aluno deve ser inserido à esquerda ou à direita da raiz atual
3. Se a matrícula do aluno for menor que a matrícula do nó atual, chame a função recursivamente para a subárvore esquerda
4. Se a matrícula do aluno for maior que a matrícula do nó atual, chame a função recursivamente para a subárvore direita
5. Retorne a raiz atual (não modificada, a menos que a inserção tenha ocorrido)
*/


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
// Descrição: a função Merge recebe duas árvores binárias de busca e as mescla em uma única árvore
/*
1. Se a primeira árvore estiver vazia, retorne a segunda árvore
2. Se a segunda árvore estiver vazia, retorne a primeira árvore
3. Mesclar as subárvores esquerda e direita da primeira árvore com a segunda árvore
4. Retorne a primeira árvore atualizada
*/

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
// Descrição: a função Copy recebe uma árvore binária de busca e retorna uma cópia da árvore
/*
1. Se a árvore estiver vazia, retorne null
2. Crie um novo nó com o mesmo aluno da árvore atual
3. Faça uma cópia das subárvores esquerda e direita da árvore atual
4. Retorne o novo nó com as subárvores copiadas
*/


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
// Descrição: a função Mirror recebe uma árvore binária de busca e retorna a árvore espelhada
/*
1. Se a árvore estiver vazia, retorne null
2. Crie um novo nó com o mesmo aluno da árvore atual
3. Faça uma cópia das subárvores esquerda e direita da árvore atual, trocando-as de posição
4. Retorne o novo nó com as subárvores espelhadas
*/

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
// Descrição: a função Compare recebe duas árvores binárias de busca e verifica se são iguais
/*
1. Se ambas as árvores estiverem vazias, retorne true
2. Se apenas uma das árvores estiver vazia, retorne false
3. Verifique se os alunos dos nós atuais são iguais e se as subárvores esquerda e direita também são iguais
4. Retorne true se as árvores forem iguais, caso contrário, retorne false
*/


//Testes
const aluno1 = {
    nome: "Mateus",
    idade: 19,
    matricula: 1,
    curso: "Engenharia de software"
}

const alunos = criarArvore(aluno1);
// console.log(alunos);
const aluno2 = {
    nome: "Marcello",
    idade: 19,
    matricula: 2,
    curso: "Engenharia de software"
}
const aluno3 = {
    nome: "Karla",
    idade: 18,
    matricula: 3,
    curso: "Engenharia de software"
}
const aluno6 = {
    nome: "Junior",
    idade: 18,
    matricula: -1,
    curso: "Engenharia de pesca"
}

//Árvore 2
const aluno4 = {
    nome: "Pedro",
    idade: 15,
    matricula: 21,
    curso: "Engenharia de software"
}
const aluno5 = {
    nome: "Jose",
    idade: 18,
    matricula: 30,
    curso: "Engenharia de software"
}

const alunos2 = criarArvore(aluno4);


InserirAluno(alunos, aluno2)
InserirAluno(alunos, aluno3)
InserirAluno(alunos, aluno6)
DeletarAluno(-1, alunos)

// ImprimirAlunos("pos", alunos);
// ImprimirAlunos("em", alunos);

InserirAluno(alunos2, aluno1)
InserirAluno(alunos2, aluno2)
InserirAluno(alunos2, aluno3)
DeletarAluno(30, alunos2)
DeletarAluno(21, alunos2)
// ImprimirAlunos("interativo", alunos2)
// console.log(alunos);
// ImprimirAlunos("pre", alunos);
// ImprimirAlunos("interativo", alunos);
// ImprimirAlunos("profundidade", alunos);
// ImprimirAlunos("pre", alunos);
// DeletarAluno(3, alunos)
// ImprimirAlunos("pre", alunos2);
// Merge(alunos, alunos2)
ImprimirAlunos("pre", alunos2);
// Compare(alunos, alunos2) ? console.log("iguais") : console.log("diferentes");