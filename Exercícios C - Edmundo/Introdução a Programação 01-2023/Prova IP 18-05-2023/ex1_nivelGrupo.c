#include <stdio.h>

int main()
{
    int n1, n2, n3, n4;
    scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
    
    int temp;
    if(n1==0 || n2== 0 || n3==0 || n4==0) {
        printf("Grupo invalido\n");
    } else {
        if(n1>=n2 && n1>=n3 && n1>=n4) {
            if(n1<10) {
                printf("Nível 1\n");
            } else if(n1>=10 && n1<20) {
                printf("Nível 2\n");
            } else {
                printf("Nível 3\n");
            }
        } else if(n2>=n1 && n2>=n3 && n2>=n4) {
            if(n2<10) {
                printf("Nível 1\n");
            } else if(n2>=10 && n2<20) {
                printf("Nível 2\n");
            } else {
                printf("Nível 3\n");
            }

        } else if(n3>=n1 && n3>=n2 && n3>=n4) {
            if(n3<10) {
                printf("Nível 1\n");
            } else if(n3>=10 && n3<20) {
                printf("Nível 2\n");
            } else {
                printf("Nível 3\n");
            }
        } else {
            if(n4<10) {
                printf("Nível 1\n");
            } else if(n4>=10 && n4<20) {
                printf("Nível 2\n");
            } else {
                printf("Nível 3\n");
            }
        }
    }
    


    return 0;
}