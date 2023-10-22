#include <stdio.h>

int main() {
    int m, n, i, j, k, temp;
    char operator;

    scanf("%d %d", &m, &n);

    int matrixX[m][n], matrixY[m][n], result[m][n];

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) scanf("%d", &matrixX[i][j]);
    }

    scanf(" %c", &operator);

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) scanf("%d", &matrixY[i][j]);
    }

    if (operator == '+') {
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                printf("%d", matrixY[i][j] + matrixX[i][j]);
                if (j == n-1) printf("\n");
                else printf(" ");
            }
        }
    } else {
        if (m != n) return printf("Error\n");

        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                result[i][j] = 0;
                for(k=0; k<m; k++) {
                    result[i][j] += matrixX[i][k] * matrixY[k][j];
                }
            }
        }

        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                printf("%d", result[i][j]);
                if (j == n-1) printf("\n");
                else printf(" ");
            }
        }
    }
    
    return 0;
}
