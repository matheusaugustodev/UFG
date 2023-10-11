#include <stdio.h>

int main() {
    
    float n1, n2, n3, x1, x2, x3;
    scanf("%f %f %f", &n1, &n2, &n3);
    if(n1>n2 && n2>n3) {
        x1 = n3;
        x2 = n2;
        x3 = n1;
    } else if(n1>n3 && n3>n2) {
        x1 = n2;
        x2 = n3;
        x3 = n1;
    } else if(n3>n2 && n2>n1) {
        x1 = n1;
        x2 = n2;
        x3 = n3;
    } else if(n2>n3 && n3>n1) {
        x1 = n1;
        x2 = n3;
        x3 = n2;
    } else if(n2>n1 && n1>n3) {
        x1 = n3;
        x2 = n1;
        x3 = n2;
    } else {
        // (n3>n1 && n1>n2)
        x1 = n2;
        x2 = n1;
        x3 = n3;
    } 

    printf("%.2f, %.2f, %.2f\n", x1, x2, x3);

    
    return 0;
}
