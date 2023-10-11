#include <stdio.h>

int main()
{
    int senha;
    char tipo;
    
    scanf("%d %c", &senha, &tipo);
    
    //  (A)dministrador senha: 321456
    //  (G)erente senha: 9510753
    //  (U)suário senha: 78955632
    
    if(senha<100000) {
        
        printf("SENHA INVALIDA: %d - MINIMO 6 DIGITOS\n", senha);
        
    } else if(tipo != 'A' && tipo != 'G' && tipo != 'U') {
        printf("CATEGORIA INVALIDA: %c\n", tipo);
        
    } else if(tipo == 'A'){
        
        if(senha== 321456) {
            printf("ACESSO PERMITIDO A CATEGORIA A\n");
        } else {
            printf("ACESSO NEGADO\n");
        }
    } else if(tipo == 'G'){
        if(senha== 9510753) {
            printf("ACESSO PERMITIDO A CATEGORIA G\n");
        } else {
            printf("ACESSO NEGADO\n");
        }
    } else {
        if(senha== 78955632) {
            printf("ACESSO PERMITIDO A CATEGORIA U\n");
        } else {
            printf("ACESSO NEGADO\n");
        }
    }


    return 0;
}