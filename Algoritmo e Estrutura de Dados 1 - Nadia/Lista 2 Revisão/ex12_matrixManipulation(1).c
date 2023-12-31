#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;

int determinantOfMatrix(int mat[n][n], int n) {
    int x, y, z, num1, num2, det = 1, index, total = 1;

    int temp[n + 1];
 
    for (x = 0; x < n; x++) {
        index = x;
 
        while (index < n && mat[index][x] == 0) index++;
        if (index == n) continue;
        if (index != x) {
            for (y = 0; y < n; y++) {
                int temp = mat[index][y];
                mat[index][y] = mat[x][y];
                mat[x][y] = temp;
            }
            det = det * pow(-1, index - x);
        }
 
        for (y = 0; y < n; y++) temp[y] = mat[x][y];
        for (y = x + 1; y < n; y++) {
            num1 = temp[x];
            num2 = mat[y][x];
            for (z = 0; z < n; z++) {
                mat[y][z] = (num1 * mat[y][z]) - (num2 * temp[z]);
            }
            total = total * num1;
        }
    }
 
    for (x = 0; x < n; x++) det = det * mat[x][x];
   
    return (det / total);
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
