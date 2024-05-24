class No {
    constructor(valor) {
        this.valor = valor;
        this.esquerda = null;
        this.direita = null;
    }
}

class ArvoreBinaria {
    constructor() {
        this.raiz = null;
    }

    inserir(valor) {
        const novoNo = new No(valor);
        if (this.raiz === null) {
            this.raiz = novoNo;
        } else {
            this.inserirNo(this.raiz, novoNo);
        }
    }

    inserirNo(no, novoNo) {
        if (novoNo.valor < no.valor) {
            if (no.esquerda === null) {
                no.esquerda = novoNo;
            } else {
                this.inserirNo(no.esquerda, novoNo);
            }
        } else {
            if (no.direita === null) {
                no.direita = novoNo;
            } else {
                this.inserirNo(no.direita, novoNo);
            }
        }
    }

}


const arvore = new ArvoreBinaria();
arvore.inserir(10);
arvore.inserir(5);
arvore.inserir(15);
arvore.inserir(3);
arvore.inserir(7);
arvore.inserir(12);
arvore.inserir(20);