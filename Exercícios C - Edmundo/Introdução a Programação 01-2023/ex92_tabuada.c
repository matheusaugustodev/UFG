#include <stdio.h>

int main() {
    
    double n, i, k, s;
    int j;
    scanf("%lf %lf %lf %lf", &n, &i, &k, &s);

    printf("Tabuada de soma:\n");
    printf("%.2lf + %.2lf = %.2lf\n", n, i, i+n);
    for(j=1; j<k; j++) {
        printf("%.2lf + %.2lf = %.2lf\n", n, i+(s*j), i+n+(s*j));
    }
    
    printf("Tabuada de subtracao:\n");
    printf("%.2lf - %.2lf = %.2lf\n", n, i, n-i);
    for(j=1; j<k; j++) {
        printf("%.2lf - %.2lf = %.2lf\n", n, i+(s*j), n-(i+(s*j)));
    }
    
    printf("Tabuada de  multiplicacao:\n");
    printf("%.2lf x %.2lf = %.2lf\n", n, i, i*n);
    for(j=1; j<k; j++) {
        printf("%.2lf x %.2lf = %.2lf\n", n, i+(s*j), n*(i+(s*j)));
    }
    
    printf("Tabuada de divisao:\n");
    printf("%.2lf / %.2lf = %.2lf\n", n, i, n/i);
    for(j=1; j<k; j++) {
        
        printf("%.2lf / %.2lf = %.2lf\n", n, i+(s*j), n/(i+(s*j)));
    }
    
    
    

    return 0;
}
