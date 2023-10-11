#include <stdio.h>

int main()
{
    int ano, resto;
    
    scanf("%i", &ano);
    if(ano%4 == 0) {
        printf("ANO BISSEXTO\n");
    } else {
        printf("ANO NAO BISSEXTO\n");
    }

    return 0;
}
