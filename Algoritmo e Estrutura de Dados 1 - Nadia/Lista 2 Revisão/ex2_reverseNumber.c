#include <stdio.h>

int reverseNumber(int num) {
    int reverse = 0;
    while (num > 0) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return reverse;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int x1 = reverseNumber(n1);
    int x2 = reverseNumber(n2);

    if (x1 > x2) printf("%d\n", x1);
    else printf("%d\n", x2);

    return 0;
}