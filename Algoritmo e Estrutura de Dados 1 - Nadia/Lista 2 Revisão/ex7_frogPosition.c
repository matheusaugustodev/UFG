#include <stdio.h>

int main() {
    int P, S, i, temp, p, d, pedras[101];
    scanf("%d %d", &P, &S);

    for(i=0; i<P; i++) pedras[i] = 0;
    for (i=0; i<S; i++) {
        scanf("%d %d", &p, &d);
        temp = p - 1;
        while (temp < P) {
          pedras[temp] = 1;
          temp += d;  
        }
        temp = p - 1;
        while (temp >= 0) {
            pedras[temp] = 1;
            temp -= d;  
        }
    }
    for (i=0; i<P; i++) printf("%d\n", pedras[i]);
    
    return 0;
}
