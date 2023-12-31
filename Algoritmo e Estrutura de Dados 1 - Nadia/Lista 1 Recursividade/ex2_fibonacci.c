#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacci(int n, int i) {
    if (i <= n) {
        printf("%d ", fibonacci(i));
        printFibonacci(n, i + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printFibonacci(n, 0);

    return 0;
}
