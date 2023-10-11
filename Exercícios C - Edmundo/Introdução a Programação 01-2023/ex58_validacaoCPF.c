#include <stdio.h>

int main()
{
    int n, b1, b2, i, j, cpf[11], resto;
    scanf("%d", &n);
    resto=0;
    for(i=0; i<n; i++) {
        for(j=0; j<11; j++) {
            scanf("%d", &cpf[j]);
        }
        resto = (cpf[0]*1+cpf[1]*2+cpf[2]*3+cpf[3]*4+cpf[4]*5+cpf[5]*6+cpf[6]*7+cpf[7]*8+cpf[8]*9)%11;
        if(resto==10) {
            b1=0;
        } else{
            b1=resto;
        }
        resto=0;
        resto = (cpf[0]*9+cpf[1]*8+cpf[2]*7+cpf[3]*6+cpf[4]*5+cpf[5]*4+cpf[6]*3+cpf[7]*2+cpf[8]*1)%11;
        if(resto==10) {
            b2=0;
        } else{
            b2=resto;
        }
        if(b1==cpf[9] && b2==cpf[10]){
            printf("CPF valido\n");
        } else {
            printf("CPF invalido\n");
        }
    }

    return 0;
}
