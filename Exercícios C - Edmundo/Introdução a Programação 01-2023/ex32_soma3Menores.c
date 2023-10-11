#include <stdio.h>

int main() {
    
    int n1, n2, n3, n4, soma, temp;
    scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
    

    if (n1 > n2) {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    if (n1 > n3) {
        temp = n1;
        n1 = n3;
        n3 = temp;
    }
    
    if (n1 > n4) {
        temp = n1;
        n1 = n4;
        n4 = temp;
    }
    
    if (n2 > n3) {
        temp = n2;
        n2 = n3;
        n3 = temp;
    }
    
    if (n2 > n4) {
        temp = n2;
        n2 = n4;
        n4 = temp;
    }
    
    if (n3 > n4) {
        temp = n3;
        n3 = n4;
        n4 = temp;
    }
    soma = n1+n2+n3;

    printf("%i\n", soma);

    
    return 0;
}
