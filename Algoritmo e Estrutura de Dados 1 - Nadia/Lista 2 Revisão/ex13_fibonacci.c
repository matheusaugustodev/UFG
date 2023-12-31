#include <stdio.h>

int main() {
    int i, j, k, n;
    long int fibonacci[1000];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (i=2; i<1000; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

    scanf("%d", &k);

    for (i=0; i<k; i++) {
        scanf("%d", &n);
        printf("%ld\n", fibonacci[n]);
    }

    return 0;
}
