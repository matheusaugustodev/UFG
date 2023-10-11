#include <stdio.h>

int main() {

    int x, y, i;
    scanf("%d %d", &x, &y);

    if(x%2!=0) {
        printf("O PRIMEIRO NUMERO NAO E PAR");
    } else {
        printf("%d ", x);
        for(i=1; i<y; i++) {
            x = x + 2;
            printf("%d ", x);
        }
    }


    return 0;
}