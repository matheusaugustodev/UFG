#include <stdio.h>

int main() {
    int a, b;
    float media;
    scanf("%i %i", &a, &b);
    media = (float)(a+b)/2;
    printf("%.3f\n", media);
    
    return 0;
}
