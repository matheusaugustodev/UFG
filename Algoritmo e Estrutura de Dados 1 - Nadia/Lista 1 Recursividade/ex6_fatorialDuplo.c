#include <stdio.h>

int fatorialDuplo(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else if (n % 2 == 1) {
        return n * fatorialDuplo(n - 2);
    } else {
        return fatorialDuplo(n - 1);
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    printf("%d\n", fatorialDuplo(n));

    return 0;
}
