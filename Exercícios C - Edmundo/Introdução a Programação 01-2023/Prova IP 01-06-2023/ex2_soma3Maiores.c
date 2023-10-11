#include <stdio.h>

int main()
{
    
    long int n1, n2, n3, n4, soma;
    
    scanf("%ld", &n1);
    scanf("%ld", &n2);
    scanf("%ld", &n3);
    scanf("%ld", &n4);
    
    if(n1>=n2 && n1>=n3 && n1 >=n4) {
        soma = n2+n3+n4;
    }
    if(n2>=n1 && n2>=n3 && n2>=n4) {
        soma = n1+n3+n4;
    }
    if(n3>=n1 && n3>=n2 && n3>=n4) {
        soma = n1+n2+n4;
    } 
    if(n4>=n1 && n4>=n2 && n4>=n3) {
        soma = n1+n2+n3;
    }
    printf("%ld\n", soma);



    return 0;
}
