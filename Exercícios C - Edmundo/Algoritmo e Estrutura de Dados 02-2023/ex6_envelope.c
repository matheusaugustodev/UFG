#include <stdio.h>

int main() {
    int num, type, i, ni, min_envelopes, labels[20] = {0};
    scanf("%d %d", &num, &type);

    min_envelopes = num;
    for (i=0; i<num; i++) {
        scanf("%d", &ni);
        labels[ni - 1]++;
    }

    for (i=0; i<type; i++) {
        if (labels[i] < min_envelopes) {
            min_envelopes = labels[i];
        }
    }

    printf("%d\n", min_envelopes);
    
    return 0;
}
