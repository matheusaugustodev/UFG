#include <stdio.h>

int main() {

    int n;
    float impares, pares, numPares, numImpares;
    impares = pares = numPares = numImpares = 0;
    do{
        scanf("%d", &n);
        if(n%2==0 && n!=0) {
            pares = pares + n;
            numPares = numPares + 1;
        } else if(n!=0){
            impares = impares + n;
            numImpares = numImpares + 1;
        }
    }
    while(n!=0);
    
    printf("MEDIA PAR: %.6f\nMEDIA IMPAR: %.6f\n", pares/numPares, impares/numImpares);

    return 0;
}
