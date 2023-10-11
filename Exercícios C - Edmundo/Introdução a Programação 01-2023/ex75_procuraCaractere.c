#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, indice;
    char string[503], caractere[1];
    scanf("%d", &n);
    getchar();
    
    for (i = 0; i < n; i++) {
        fgets(string, sizeof(string), stdin);
        caractere[0] = string[0];
        indice=-1;
        for(j=3; j<strlen(string)-1; j++) {
            if(caractere[0]==string[j]) {
                indice = j-2;
                break;
            }
        }
        if(indice==-1) {
            printf("Caractere %c nao encontrado.\n", caractere[0]);
        } else {
            printf("Caractere %c encontrado no indice %d da string.\n", caractere[0], indice);
        }
    }

    return 0;
}
