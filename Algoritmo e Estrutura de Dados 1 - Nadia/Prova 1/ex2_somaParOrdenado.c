#include <stdio.h>

int main() {

    int n, m, i, j, k, array[10000], maiorSoma, contador;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        contador = 0;
        maiorSoma = 0;
        scanf("%d", &m);
        for (j=0; j<m; j++) scanf("%d", &array[j]);
        
        for (j=0; j<m; j++) {
            for (k=j+1; k<m; k++) {
                if (k!=j && array[j]+array[k] > maiorSoma) maiorSoma = array[j]+array[k];
            }
        }

        for (j=0; j<m; j++) {
            for (k=j+1; k<m; k++) {
                if (k!=j && array[j]+array[k] == maiorSoma) contador++;
            }
        }

        printf("%d\n", contador);
    }


    return 0;
}
