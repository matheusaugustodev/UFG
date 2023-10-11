#include <stdio.h>

int main() {
    
    int numero, dia, mes, ano;
    const char* mesTexto;
    
    scanf("%i", &numero);
    
    dia = (numero/1000000);
    mes = (numero/10000)%100;
    ano = (numero%10000);

    if (mes>12) {
        printf("Data invalida!\n");
    } else if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes ==12) && dia>31) {
        printf("Data invalida!\n");
    } else if ((mes==4 || mes==6 || mes==9 || mes==11) && dia>30) {
        printf("Data invalida!\n");
    } else if (mes==2 && dia>28) {
        printf("Data invalida!\n");
    } else {
        mesTexto = (mes==1) ? "janeiro" :
                   (mes==2) ? "fevereiro" :
                   (mes==3) ? "março" :
                   (mes==4) ? "abril" :
                   (mes==5) ? "maio" :
                   (mes==6) ? "junho" :
                   (mes==7) ? "julho" :
                   (mes==8) ? "agosto" :
                   (mes==9) ? "setembro" :
                   (mes==10) ? "outubro" :
                   (mes==11) ? "novembro" :
                               "dezembro";
        
        printf("%i de %s de %i\n", dia, mesTexto, ano);    
    }
    return 0;
}