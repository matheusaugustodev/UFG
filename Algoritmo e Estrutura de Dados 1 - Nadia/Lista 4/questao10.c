#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digito;
    struct Node* proximo;
} Node;

typedef struct {
    Node* inicio;
} NumeroInteiro;

void inicializarNumero(NumeroInteiro* numero) {
    numero->inicio = NULL;
}

void inserirDigito(NumeroInteiro* numero, int digito) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNode->digito = digito;
    novoNode->proximo = numero->inicio;
    numero->inicio = novoNode;
}

void imprimirNumero(NumeroInteiro* numero) {
    Node* atual = numero->inicio;
    while (atual != NULL) {
        printf("%d", atual->digito);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberarMemoria(NumeroInteiro* numero) {
    Node* atual = numero->inicio;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    numero->inicio = NULL;
}

NumeroInteiro soma(NumeroInteiro* num1, NumeroInteiro* num2) {
    NumeroInteiro resultado;
    inicializarNumero(&resultado);

    int carry = 0;
    Node* atual1 = num1->inicio;
    Node* atual2 = num2->inicio;

    while (atual1 != NULL || atual2 != NULL) {
        int digito1 = (atual1 != NULL) ? atual1->digito : 0;
        int digito2 = (atual2 != NULL) ? atual2->digito : 0;

        int somaDigitos = digito1 + digito2 + carry;
        carry = somaDigitos / 10;
        inserirDigito(&resultado, somaDigitos % 10);

        if (atual1 != NULL) atual1 = atual1->proximo;
        if (atual2 != NULL) atual2 = atual2->proximo;
    }

    if (carry > 0) {
        inserirDigito(&resultado, carry);
    }

    return resultado;
}

NumeroInteiro subtracao(NumeroInteiro* num1, NumeroInteiro* num2) {
    NumeroInteiro resultado;
    inicializarNumero(&resultado);

    int borrow = 0;
    Node* atual1 = num1->inicio;
    Node* atual2 = num2->inicio;

    while (atual1 != NULL || atual2 != NULL) {
        int digito1 = (atual1 != NULL) ? atual1->digito : 0;
        int digito2 = (atual2 != NULL) ? atual2->digito : 0;

        int subtracaoDigitos = digito1 - digito2 - borrow;
        if (subtracaoDigitos < 0) {
            subtracaoDigitos += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        inserirDigito(&resultado, subtracaoDigitos);

        if (atual1 != NULL) atual1 = atual1->proximo;
        if (atual2 != NULL) atual2 = atual2->proximo;
    }

    while (resultado.inicio != NULL && resultado.inicio->digito == 0) {
        Node* temp = resultado.inicio;
        resultado.inicio = resultado.inicio->proximo;
        free(temp);
    }

    return resultado;
}

NumeroInteiro multiplicacaoPorDigito(NumeroInteiro* num, int digito) {
    NumeroInteiro resultado;
    inicializarNumero(&resultado);

    int carry = 0;
    Node* atual = num->inicio;

    while (atual != NULL) {
        int produto = (atual->digito * digito) + carry;
        carry = produto / 10;
        inserirDigito(&resultado, produto % 10);
        atual = atual->proximo;
    }

    while (carry > 0) {
        inserirDigito(&resultado, carry % 10);
        carry /= 10;
    }

    return resultado;
}

NumeroInteiro multiplicacao(NumeroInteiro* num1, NumeroInteiro* num2) {
    NumeroInteiro resultado;
    inicializarNumero(&resultado);

    int posicao = 0;
    Node* atual = num2->inicio;

    while (atual != NULL) {
        NumeroInteiro parcial = multiplicacaoPorDigito(num1, atual->digito);

        // Adicionar zeros à direita de acordo com a posição
        for (int i = 0; i < posicao; i++) {
            inserirDigito(&parcial, 0);
        }

        resultado = soma(&resultado, &parcial);

        liberarMemoria(&parcial);
        atual = atual->proximo;
        posicao++;
    }

    return resultado;
}

NumeroInteiro divisaoPorDigito(NumeroInteiro* num, int divisor, int* resto) {
    NumeroInteiro resultado;
    inicializarNumero(&resultado);

    int quociente = 0;
    int tempResto = 0;
    Node* atual = num->inicio;

    while (atual != NULL) {
        int dividendo = tempResto * 10 + atual->digito;
        quociente = dividendo / divisor;
        tempResto = dividendo % divisor;

        inserirDigito(&resultado, quociente);
        atual = atual->proximo;
    }

    if (resto != NULL) {
        *resto = tempResto;
    }

    // Remover zeros à esquerda
    while (resultado.inicio != NULL && resultado.inicio->digito == 0) {
        Node* temp = resultado.inicio;
        resultado.inicio = resultado.inicio->proximo;
        free(temp);
    }

    return resultado;
}

NumeroInteiro divisao(NumeroInteiro* num1, NumeroInteiro* num2, int* resto) {
    if (num2->inicio == NULL) {
        printf("Erro: divisão por zero.\n");
        exit(EXIT_FAILURE);
    }

    NumeroInteiro resultado;
    inicializarNumero(&resultado);

    NumeroInteiro tempNum1;
    inicializarNumero(&tempNum1);
    Node* atual = num1->inicio;

    while (atual != NULL) {
        inserirDigito(&tempNum1, atual->digito);
        resultado.inicio->digito = 0;

        while (ehMaiorOuIgual(&tempNum1, num2)) {
            tempNum1 = subtracao(&tempNum1, num2);
            resultado.inicio->digito++;
        }

        if (resultado.inicio->digito > 0 || resultado.inicio->proximo != NULL || atual->proximo != NULL) {
            inserirDigito(&resultado, 0);
        }

        atual = atual->proximo;
    }

    if (resto != NULL) {
        *resto = 0;

        if (tempNum1.inicio != NULL) {
            Node* tempAtual = tempNum1.inicio;
            while (tempAtual != NULL) {
                *resto = *resto * 10 + tempAtual->digito;
                tempAtual = tempAtual->proximo;
            }
        }
    }

    liberarMemoria(&tempNum1);

    // Remover zeros à esquerda
    while (resultado.inicio != NULL && resultado.inicio->digito == 0) {
        Node* temp = resultado.inicio;
        resultado.inicio = resultado.inicio->proximo;
        free(temp);
    }

    return resultado;
}

int ehMaiorOuIgual(NumeroInteiro* num1, NumeroInteiro* num2) {
    if (num1->inicio == NULL && num2->inicio == NULL) {
        return 1;
    }

    Node* atual1 = num1->inicio;
    Node* atual2 = num2->inicio;

    while (atual1 != NULL && atual1->digito == 0) {
        atual1 = atual1->proximo;
    }

    while (atual2 != NULL && atual2->digito == 0) {
        atual2 = atual2->proximo;
    }

    int tamanho1 = 0;
    int tamanho2 = 0;

    while (atual1 != NULL) {
        tamanho1++;
        atual1 = atual1->proximo;
    }

    while (atual2 != NULL) {
        tamanho2++;
        atual2 = atual2->proximo;
    }

    if (tamanho1 > tamanho2) {
        return 1;
    } else if (tamanho1 < tamanho2) {
        return 0;
    }

    atual1 = num1->inicio;
    atual2 = num2->inicio;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->digito > atual2->digito) {
            return 1;
        } else if (atual1->digito < atual2->digito) {
            return 0;
        }

        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }

    return 1;
}

int ehPrimo(NumeroInteiro* numero) {
    if (numero->inicio == NULL) {
        return 0;
    }

    int valor = 0;
    Node* atual = numero->inicio;

    while (atual != NULL) {
        valor = valor * 10 + atual->digito;
        atual = atual->proximo;
    }

    if (valor < 2) {
        return 0;
    }

    for (int i = 2; i * i <= valor; i++) {
        if (valor % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    NumeroInteiro num1, num2, resultado, subtracaoResultado, multiplicacaoResultado, divisaoResultado;
    inicializarNumero(&num1);
    inicializarNumero(&num2);
    inicializarNumero(&resultado);
    inicializarNumero(&subtracaoResultado);
    inicializarNumero(&multiplicacaoResultado);
    inicializarNumero(&divisaoResultado);

    inserirDigito(&num1, 9);
    inserirDigito(&num1, 7);
    inserirDigito(&num1, 5);

    inserirDigito(&num2, 2);
    inserirDigito(&num2, 3);
    inserirDigito(&num2, 1);

    printf("Número 1: ");
    imprimirNumero(&num1);

    printf("Número 2: ");
    imprimirNumero(&num2);

    resultado = soma(&num1, &num2);
    printf("Soma: ");
    imprimirNumero(&resultado);

    subtracaoResultado = subtracao(&num1, &num2);
    printf("Subtração: ");
    imprimirNumero(&subtracaoResultado);

    multiplicacaoResultado = multiplicacao(&num1, &num2);
    printf("Multiplicação: ");
    imprimirNumero(&multiplicacaoResultado);

    int resto;
    divisaoResultado = divisao(&num1, &num2, &resto);
    printf("Divisão: ");
    imprimirNumero(&divisaoResultado);
    printf("Resto: %d\n", resto);

    printf("É primo? %s\n", (ehPrimo(&resultado)) ? "Sim" : "Não");

    liberarMemoria(&num1);
    liberarMemoria(&num2);
    liberarMemoria(&resultado);
    liberarMemoria(&subtracaoResultado);
    liberarMemoria(&multiplicacaoResultado);
    liberarMemoria(&divisaoResultado);

    return 0;
}
