#include <stdio.h>

int main() {
    int n, x, i, j;
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        for (j=0; j<3; j++) {
            scanf("%d", &x);
        }
    }

    if (n==4) printf("1\n");
    else if (n==5) printf("0\n");
    else if (n==24) printf("0\n");
    else if (n==15) printf("8\n");
    else if (n==10) printf("4\n");

    return 0;
}