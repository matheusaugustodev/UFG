#include <stdio.h>

int main()
{
    int n1, n2, n3;
    scanf("%i %i %i", &n1, &n2, &n3);
    
    if(n1>=n2 && n1>=n3) {
        if(n1*n1 < (n2*n2 + n3*n3)) {
            printf("acutangulo\n");
        } else if(n1*n1 > (n1*n2 + n3*n3)) {
            printf("obtusângulo\n");
        } else {
            printf("retangulo\n");
        }
    } else if(n2>=n1 && n2>=n3) {
        if(n2*n2 < (n1*n1 + n3*n3)) {
            printf("acutangulo\n");
        } else if(n2*n2 > (n2*n1 + n3*n3)) {
            printf("obtusângulo\n");
        } else {
            printf("retangulo\n");
        }
    } else {
        if(n3*n3 < (n2*n2 + n1*n1)) {
            printf("acutangulo\n");
        } else if(n3*n3 > (n3*n2 + n1*n1)) {
            printf("obtusângulo\n");
        } else {
            printf("retangulo\n");
        }
    }

    


    return 0;
}