// em c, escreva o método reverseFirstKElements(Fila q, int k, int n) que inverte os primeiros k elementos de uma fila q de tamanho n

// por exemplo, se a fila contina 1 -> 2 -> 3-> 4 e k=2, apos o codigo a fila q contem 2 -> 1 -> 3 -> 4

// suponha que voce ja tenha implementado as operacoes enqueue() e dequeue() e isEmpty()

// assuma que exista uma arquivo Pilha.c com metodos implementados push(), pop() e isEmpty()


#include "Pilha.c"
#include "Fila.c"

void reverseFirstKElements(Fila* q, int k, int n) {
    Pilha* stack = createStack(k);
    int i;

    // Desenfileira os primeiros k elementos da fila e empilha na pilha
    for(i = 0; i < k; i++) {
        push(stack, dequeue(q));
    }

    // Desempilha os elementos da pilha e enfileira de volta na fila
    while(!isEmptyStack(stack)) {
        enqueue(q, pop(stack));
    }

    // Desenfileira os elementos restantes da fila e enfileira de volta
    for(i = 0; i < n - k; i++) {
        enqueue(q, dequeue(q));
    }
}