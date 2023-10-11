#include <stdio.h>
#include <math.h>

int main()
{
    int n1, n2, n3, resultado;
    scanf("%i %i %i", &n1, &n2, &n3);
    if(n1>9 || n2> 9 || n3>9){
        printf("DIGITO INVALIDO\n");
    } else {
        resultado = (n1*100)+(n2*10)+n3;
        printf("%i, %i\n", resultado, resultado*resultado);
    }

    return 0;
}
