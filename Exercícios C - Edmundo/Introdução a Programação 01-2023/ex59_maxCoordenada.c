#include <stdio.h>

int main()
{
    int n, i, j;
    float maior, subtracao, A[3], B[3];
    
    scanf("%d", &n);
    for(i=0; i<3; i++) scanf("%f", &A[i]);

    for(j = 1; j < n; j++) {
        for(i=0; i<3; i++) scanf("%f", &B[i]);
        maior=-99;
        for(i=0; i<3; i++) {
            subtracao = A[i]-B[i];
            if(subtracao<0) subtracao = subtracao*(-1);  
            if(subtracao>maior) maior = subtracao;
        }
        printf("%.2f\n", maior);
        for(i=0; i<3; i++) A[i] = B[i];
    }

    return 0;
}
