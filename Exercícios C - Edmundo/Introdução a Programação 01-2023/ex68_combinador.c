#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, tamanho, tamX, tamY;
    char x[50], y[50], palavrasOrdenadas[1000];
    int posicao = 0;
    
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%s %s", x, y);

        tamX = strlen(x);
        tamY = strlen(y);

        tamanho = (tamX > tamY) ? tamX : tamY;

        for (j = 0; j < tamanho; j++) {
            if (x[j] != '\0') {
                palavrasOrdenadas[posicao] = x[j];
                posicao++;
            }
            if (y[j] != '\0') {
                palavrasOrdenadas[posicao] = y[j];
                posicao++;
            }
        }
        palavrasOrdenadas[posicao] = '\n';
        posicao++;
    }

    palavrasOrdenadas[posicao] = '\0';
    printf("%s", palavrasOrdenadas);

    return 0;
}
