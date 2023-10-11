#include <stdio.h>

int main()
{
    int n, d, i, j, k, matriz[100][100], teste;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &d);

        if (d > 30)
            return 0;
        
        teste = 0;
        for (j = 0; j < d; j++) {
            for (k = 0; k < d; k++) scanf("%d", &matriz[j][k]);
        }

        for (j = 0; j < d; j++) {
            for (k = 0; k < d; k++) {
                if(matriz[j][k] != matriz[k][j]) teste++;
            }
        }

        if (teste > 0) printf("NAO SIMETRICA\n");
        else printf("SIMETRICA\n");
    }

    return 0;
}
