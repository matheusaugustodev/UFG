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
    int i, j=0, x, num, reverseNum, result[99999];
    
    scanf("%d", &x);

    for (i=0; i<x; i++) {
        scanf("%d", &num);
        reverseNum = reverseNumber(num);
        result[j] = reverseNum == num ? 1 : 0;
        j++;
    }

    for (i=0; i<j; i++) {
        if (result[i] == 1) printf("yes");
        else printf("no");
        if (i == j - 1) printf("\n");
        else printf(" ");
    }

    return 0;
}