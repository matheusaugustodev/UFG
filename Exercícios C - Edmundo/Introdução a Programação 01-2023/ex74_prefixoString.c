#include <stdio.h>
#include <string.h>

int main()
{

    int n, i, j, numPrefixo, posicao;
    char string[499], novasPalavras[2000];
    posicao=0;
    
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        scanf("%d", &numPrefixo);
        getchar();
        scanf("%[^\n]", string);
        
        for(j=0; j<numPrefixo; j++) {
            if(j>=strlen(string)) break;
            novasPalavras[posicao] = string[j];
            posicao++;
        }
        novasPalavras[posicao]='\n';
        posicao++;
    }
    for (i=0; i<posicao; i++) {
        printf("%c", novasPalavras[i]);
    }

    return 0;
}