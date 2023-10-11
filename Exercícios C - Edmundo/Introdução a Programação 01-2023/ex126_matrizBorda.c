#include <stdio.h>

int main()
{

    int i, j, k, largura, altura, tamBorda, valorBorda, matriz[100][100];

    scanf("%d %d %d %d", &largura, &altura, &tamBorda, &valorBorda);
    printf("P2\n%d %d\n255\n", altura, largura);

    for (j = 0; j < largura; j++) {
        for (i = 0; i < tamBorda; i++) matriz[j][i] = valorBorda;
        for (k = altura; k >= (altura - tamBorda); k--) matriz[j][k] = valorBorda;
    }

    for (j = 0; j < tamBorda; j++)
        for (i = 0; i < altura; i++) matriz[j][i] = valorBorda;

    for (j = largura; j >= (largura - tamBorda); j--)
        for (i = 0; i < altura; i++) matriz[j][i] = valorBorda;

    for (j = 0; j < largura; j++) {
        for (i = 0; i < altura; i++) printf("%d ", matriz[j][i]);
        printf("\n");
    }


    return 0;
}