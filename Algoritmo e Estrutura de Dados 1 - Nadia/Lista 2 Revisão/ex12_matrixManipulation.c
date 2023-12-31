#include <stdio.h>

int n;

void getCofactor(int mat[n][n], int temp[n][n], int p, int q, int n) {
    int x = 0, z = 0, row, col;

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[x][z++] = mat[row][col];

                if (z == n - 1) {
                    z = 0;
                    x++;
                }
            }
        }
    }
}

int determinantOfMatrix(int mat[n][n], int n) {
    int D = 0; 
    if (n == 1) return mat[0][0];
    int temp[n][n]; 
    int sign = 1; 

    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }

    return D;
}

int main() {
    int m, i, j, k;
    char operator;

    scanf("%d %d", &m, &n);

    int matrix[m][n], list[m*n];

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) scanf("%d", &matrix[i][j]);
    }

    scanf(" %c", &operator);

    if (operator == 'T') {
        k = 0;
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) list[k++] = matrix[i][j];
        }
        k = 0;
        for (i=0; i<n; i++) {
            for (j=0; j<m; j++) {
                printf("%d", list[k++]);
                if (j == m-1) printf("\n");
                else printf(" ");
            }
        }
    } else if (operator == 'D') {
        if (m != n) return printf("Error\n");
        printf("%d\n", determinantOfMatrix(matrix, n));
    } else if (operator == 'I') {
        for (i=m-1; i>=0; i--) {
            for (j=n-1; j>=0; j--) {
                printf("%d", matrix[i][j]);
                if (j == 0) printf("\n");
                else printf(" ");
            }
        }
    }
    
    return 0;
}
