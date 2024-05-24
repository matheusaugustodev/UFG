// Estrutura do nó da árvore
class No {
    constructor(chave) {
        this.chave = chave;
        this.esquerda = null;
        this.direita = null;
    }
}

// Implementação da árvore binária de busca Splay
class ArvoreSplay {
    constructor() {
        this.raiz = null;
    }

    // Função para realizar rotações Splay
    splay(chave, no) {
        if (no === null || no.chave === chave) {
            return no;
        }

        if (chave < no.chave) {
            // Caso 1: a chave está à esquerda
            if (no.esquerda === null) {
                return no;
            }
            
            if (chave < no.esquerda.chave) {
                // Zig-Zig (rotacionar à direita duas vezes)
                no.esquerda.esquerda = this.splay(chave, no.esquerda.esquerda);
                no = this.rotacionarDireita(no);
            } else if (chave > no.esquerda.chave) {
                // Zig-Zag (rotacionar à esquerda e depois à direita)
                no.esquerda.direita = this.splay(chave, no.esquerda.direita);
                if (no.esquerda.direita !== null) {
                    no.esquerda = this.rotacionarEsquerda(no.esquerda);
                }
            }

            return (no.esquerda === null) ? no : this.rotacionarDireita(no);
        } else {
            // Caso 2: a chave está à direita
            if (no.direita === null) {
                return no;
            }

            if (chave > no.direita.chave) {
                // Zag-Zag (rotacionar à esquerda duas vezes)
                no.direita.direita = this.splay(chave, no.direita.direita);
                no = this.rotacionarEsquerda(no);
            } else if (chave < no.direita.chave) {
                // Zag-Zig (rotacionar à direita e depois à esquerda)
                no.direita.esquerda = this.splay(chave, no.direita.esquerda);
                if (no.direita.esquerda !== null) {
                    no.direita = this.rotacionarDireita(no.direita);
                }
            }

            return (no.direita === null) ? no : this.rotacionarEsquerda(no);
        }
    }

    // Rotação à esquerda
    rotacionarEsquerda(no) {
        const temp = no.direita;
        no.direita = temp.esquerda;
        temp.esquerda = no;
        return temp;
    }

    // Rotação à direita
    rotacionarDireita(no) {
        const temp = no.esquerda;
        no.esquerda = temp.direita;
        temp.direita = no;
        return temp;
    }

    // Inserção na árvore
    inserir(chave) {
        if (this.raiz === null) {
            this.raiz = new No(chave);
            return;
        }

        this.raiz = this.splay(chave, this.raiz);

        if (chave < this.raiz.chave) {
            const novoNo = new No(chave);
            novoNo.esquerda = this.raiz.esquerda;
            novoNo.direita = this.raiz;
            this.raiz.esquerda = null;
            this.raiz = novoNo;
        } else if (chave > this.raiz.chave) {
            const novoNo = new No(chave);
            novoNo.direita = this.raiz.direita;
            novoNo.esquerda = this.raiz;
            this.raiz.direita = null;
            this.raiz = novoNo;
        }
    }

    // Busca na árvore
    buscar(chave) {
        this.raiz = this.splay(chave, this.raiz);
        return (this.raiz !== null && this.raiz.chave === chave);
    }

    // Deleção na árvore
    remover(chave) {
        if (this.raiz === null) {
            return;
        }

        this.raiz = this.splay(chave, this.raiz);

        if (chave === this.raiz.chave) {
            if (this.raiz.esquerda === null) {
                this.raiz = this.raiz.direita;
            } else {
                const novaRaiz = this.splay(chave, this.raiz.esquerda);
                novaRaiz.direita = this.raiz.direita;
                this.raiz = novaRaiz;
            }
        }
    }
}


// Exemplo de uso da árvore Splay
const arvoreSplay = new ArvoreSplay();
arvoreSplay.inserir(10);
arvoreSplay.inserir(5);
arvoreSplay.inserir(15);
arvoreSplay.inserir(3);

console.log(arvoreSplay.buscar(5)); // Saída: true
console.log(arvoreSplay.buscar(7)); // Saída: false

arvoreSplay.remover(5);
console.log(arvoreSplay.buscar(5)); // Saída: false

console.log(arvoreSplay) // Saída: ArvoreSplay { raiz: No { chave: 10, esquerda: No { chave: 3, esquerda: null, direita: null }, direita: No { chave: 15, esquerda: null, direita: null } } }