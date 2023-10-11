#include <stdio.h>
#include <math.h>

int main()
{
    float altura, aresta, volume, areaBase;
    scanf("%f %f", &altura, &aresta);
    areaBase = (3 * (aresta * aresta) * sqrt(3))/2;
    volume = (areaBase * altura)/3;
    printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS\n", volume);

    return 0;
}
