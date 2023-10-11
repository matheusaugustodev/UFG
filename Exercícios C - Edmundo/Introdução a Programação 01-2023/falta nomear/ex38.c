#include <stdio.h>

int main() {
    
    float n1, n2, n3, n4, temp;
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    
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
    if(n1>n4) {
        temp = n1;
        n1 = n4;
        n4 = temp;
    }
    if (n2>n3) {
        temp = n2;
        n2 = n3;
        n3 = temp;
    }
    if (n2>n4) {
        temp = n2;
        n2 = n4;
        n4 = temp;
    }
    if (n3>n4) {
        temp = n3;
        n3 = n4;
        n4 = temp;
    }
    printf("%.2f, %.2f, %.2f, %.2f\n", n1, n2, n3, n4);

    return 0;
}
