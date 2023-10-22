#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main() {
    double R, r, a, b, c, B, H, p, area;
    int i, N;
    char type;

    scanf("%d", &N);

    for (i=0; i<N; i++) {
        scanf(" %c", &type);

        if (type == 'C') {
            scanf("%lf", &R);
            area = R*R*PI;
        } else if (type == 'E') {
            scanf("%lf %lf", &R, &r);
            area = R*r*PI;
        } else if (type == 'T') {
            scanf("%lf %lf %lf", &a, &b, &c);
            p = (a+b+c)/2;
            area = sqrt(p*(p-a)*(p-b)*(p-c));
        } else {
            scanf("%lf %lf %lf", &B, &b, &H);
            area = ((B+b)*H)/2;
        }
        printf("%0.lf\n", round(area));
    }


    
    return 0;
}
