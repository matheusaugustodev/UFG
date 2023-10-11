#include <stdio.h>

void calcular_dv_titulo_eleitor( int numSeq, int codUF, int *dv1, int *dv2 ) {
    int i, soma1 = 0, soma2 = 0;
        
    char vetNum[9], vetUF[3];
    
    sprintf(vetNum, "%08d", numSeq);
    sprintf(vetUF, "%02d", codUF);
    
    for(i=0; i<8; i++) {
        soma1 += (vetNum[i]- '0')*(i+2);
    }
    if(soma1%11 == 10) *dv1 = 0;
    else *dv1 = soma1%11;
    
    vetUF[2] = *dv1 + '0';
    
    for(i=0; i<3; i++) {
        soma2 += (vetUF[i]- '0')*(i+7);
    }
    *dv2 = soma2%11;
}

int main() {
    int numSeq, codUF, dv1=0, dv2=0; 
    
    scanf("%d %d", &numSeq, &codUF);
    
    calcular_dv_titulo_eleitor(numSeq, codUF, &dv1, &dv2);
    
    if(codUF > 28) printf("CODIGO DA UF INVALIDO!\n");
    else printf("%d%d/%d%d", numSeq, codUF, dv1, dv2);

   
    return 0;
}
