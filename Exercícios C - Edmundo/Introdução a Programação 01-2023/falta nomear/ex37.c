#include <stdio.h>

int main() {
    int n1, n2, n3, temp, x1, x2, x3;
    char x, y, z;

    scanf("%d %d %d\n", &n1, &n2, &n3);
    scanf("%c %c %c", &x, &y, &z);
    

    if(n1>n2){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if(n1>n3) {
        temp = n1;
        n1 = n3;
        n3 = temp;
    } 
    if (n2>n3) {
        temp = n2;
        n2 = n3;
        n3 = temp;
    }
    if(x == 'A') {
        x1 = n1;
    } else if(x == 'B') {
        x1 = n2;
    } else {
        x1 = n3;
    }
    if(y == 'A') {
        x2 = n1;
    } else if(y == 'B') {
        x2 = n2;
    } else {
        x2 = n3;
    }
    if(z == 'A') {
        x3 = n1;
    } else if(z == 'B') {
        x3 = n2;
    } else {
        x3 = n3;
    }
    printf("%i %i %i\n", x1, x2, x3);

    return 0;
}
