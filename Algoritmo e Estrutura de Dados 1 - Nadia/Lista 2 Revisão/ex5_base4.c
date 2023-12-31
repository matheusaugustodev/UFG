#include <stdio.h>

int main() {
    int i, j, k, x, number, temp, factor[9999];
    char character[4] = {'A', 'C', 'G', 'T'};

    scanf("%d", &x);
    for (i=0; i<x; i++) {

        scanf("%d", &number);
        j=0;
        temp = number;

        while (temp/4 != 0) {
            factor[j] = temp%4;
            temp /= 4;
            j++;
        }

        if (temp>0) {
            factor[j] = temp;
            j++;
        }

        for (k=j-1; k>=0; k--) printf("%c", character[factor[k]]);
        printf("\n");
    }

    return 0;
}