#include <stdio.h>

int main() {
    long int num;
    int i, j, temp, N;

    scanf("%d", &N);

    for (i=0; i<N; i++) {
        scanf("%ld", &num);
        temp = 0;
        for (j=2; j<num; j++) {
            if (num%j == 0) temp++;
        }
        if (temp == 0) printf("primo\n");
        else printf("composto\n");
    }

    
    return 0;
}
