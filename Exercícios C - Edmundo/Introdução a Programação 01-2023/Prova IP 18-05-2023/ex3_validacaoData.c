#include <stdio.h>

int main()
{
    int dia, mes, ano;
    scanf("%i %i %i", &dia, &mes, &ano);

    if(ano<1900 || ano> 2036) {
        printf("DATA FORA DO INTERVALO ESTIPULADO\n");
    } else if (mes>12 || dia>31){
        printf("DATA INVALIDA\n");
    } else {
        if(mes!=1 && mes!=3 && mes!=5 && mes!=7 && mes !=8 && mes!=10 && mes!=12) {
            if(dia>30) {
                printf("DATA INVALIDA\n");
            } else if(mes==2){
                if(ano%4!=0 || (ano%100==0 && ano%400!=0)) {
                    if(dia>28) {
                        printf("DATA INVALIDA\n");
                    }
                } else {
                    if(dia>29) {
                        printf("DATA INVALIDA\n");
                    }
                }
            }  
            
        } else {
                printf("%i/%i/%i\n", dia, mes, ano);
        } 
       
    } 
    return 0;
}