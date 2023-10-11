#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double x, y, z, x1, y1, z1, distancia;
    
    scanf("%d", &n);
    scanf("%lf %lf %lf", &x, &y, &z);
    scanf("%lf %lf %lf", &x1, &y1, &z1);

    for(i=2; i<=n; i++) {
        distancia = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1) + (z-z1)*(z-z1));
        printf("%.2lf\n", distancia);
        x=x1;
        y=y1;
        z=z1;
        if(i!=n) {
            scanf("%lf %lf %lf", &x1, &y1, &z1);     
        }
    }


    return 0;
}