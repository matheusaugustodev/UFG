#include <stdio.h>

double le_numero(int n) {
    double temp;
    double media = 0;

    int i = 1;
    for(; i <= n; i++){
        scanf("%lf", &temp);
        media += temp;
    }

    media /= n;

    printf("%.2f\n", media);

    return media;
}


int main()
{
    int n;
    
    scanf("%d", &n);

    le_numero(n);
    
    return 0;
}
