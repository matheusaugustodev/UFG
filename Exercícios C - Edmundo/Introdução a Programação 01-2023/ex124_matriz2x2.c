#include <stdio.h>

int main()
{
    int i, j;
    float vet[4], res[4];
    
    for(i=0; i<4; i++) scanf("%f", &vet[i]);
    res[0] = vet[0]*vet[0]+vet[1]*vet[2];
    res[1] = vet[0]*vet[1]+vet[1]*vet[3];
    res[2] = vet[2]*vet[0]+vet[3]*vet[2];
    res[3] = vet[2]*vet[1]+vet[3]*vet[3];
    
    printf("%.3f %.3f\n%.3f %.3f\n", res[0], res[1], res[2], res[3]);

    return 0;
}
