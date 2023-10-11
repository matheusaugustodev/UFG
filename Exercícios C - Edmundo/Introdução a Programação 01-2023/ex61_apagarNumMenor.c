#include <stdio.h>

int main()
{
    char num[100001], numFinal[100001];
    int n, d, i, j, k, indiceMaior;

    scanf("%d %d", &n, &d);
    getchar();

    while (n != 0 || d != 0) {
        i = 1;
        j = n - d;
        k = 0;
        indiceMaior = 0;
        scanf("%s", num);
        while (k < d) {
            while (i <= j) {
                if (num[indiceMaior] < num[i]) indiceMaior = i;
                i++;
            }

            numFinal[k++] = num[indiceMaior];
            indiceMaior++;
            i = indiceMaior + 1;

            if (n - 1 < j + 1) j = n - 1;
            else j = j + 1;
        }
        numFinal[d] = '\0';
        printf("%s\n", numFinal);

        scanf("%d %d", &n, &d);
        getchar();
    }

    return 0;
}