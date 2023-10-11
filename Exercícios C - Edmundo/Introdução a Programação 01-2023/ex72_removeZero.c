#include <stdio.h>
#include <string.h>

int main()
{

    int n, m, i, resultado;
    char soma[20];
    
    n=-1, m=-1;
    while (1) {
        scanf("%d %d", &n, &m);
        if(n==0 || m==0) {
            break;
        }
        if(n<1 || m<1 || n>999999999 || m>999999999) {
            break;
        }
        resultado = n+m;
        sprintf(soma, "%d", resultado);
        for(i=0; i<strlen(soma); i++) {
            if(soma[i]!=0) {
                printf("%c", soma[i]);
            }
        }    
        printf("\n");
    }

    return 0;
}