#include <stdio.h>

void revertNumber(unsigned long int n, unsigned long int i) {
    if (i<=n) {
        printf("%ld ", i);

        i++;
        revertNumber(n, i);
    }
}

int main() {
    unsigned long int num, init=1;
    scanf("%ld", &num);

    revertNumber(num, init);

    return 0;
}