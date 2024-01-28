#include <stdio.h>
#include <stdlib.h>

typedef struct {
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
        return '\0';
    }

    Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

int isWellFormed(char* expression) {
    Stack stack;
    init(&stack);

    int i = 0;
    while (expression[i] != '\0') {
        char current = expression[i];

        if (current == '(' || current == '[' || current == '{') {
            push(&stack, current);
        } else if (current == ')' || current == ']' || current == '}') {
            char popped = pop(&stack);

            if (popped == '\0' ||
                (current == ')' && popped != '(') ||
                (current == ']' && popped != '[') ||
                (current == '}' && popped != '{')) {
                return 0;
            }
        }

        i++;
    }

    return isEmpty(&stack);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char expression[1001];
        scanf(" %[^\n]", expression);

        if (isWellFormed(expression)) {
            printf("bem-formada\n");
        } else {
            printf("mal-formada\n");
        }
    }

    return 0;
}