#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void init(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';  // Caractere nulo indicando erro
    }

    Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

int main() {
    Stack stack;
    init(&stack);

    char expression[1001];
    fgets(expression, sizeof(expression), stdin);

    int i = 0;
    while (expression[i] != '\0' && expression[i] != '\n') {
        if (expression[i] == '(') {
            push(&stack, '(');
        } else if (expression[i] == ')') {
            char popped = pop(&stack);
            if (popped == '\0' || popped != '(') {
                printf("incorreta\n");
                return 0;
            }
        }
        i++;
    }

    if (isEmpty(&stack)) {
        printf("correta\n");
    } else {
        printf("incorreta\n");
    }

    return 0;
}