#include <stdio.h>

int main()
{
    int n, d, i, j, k, resultado, matriz[100][100], teste1, teste0;
    
    scanf("%d", &n);
    
    if(n>100) return 0;
    
    for(i=0; i<n; i++) {
        scanf("%d", &d);
        
        if(d>20) return 0;
        
        resultado = 0;
        for(j=0; j<d; j++) {
            teste1 = 0;     
            teste0 = 0;
            for(k=0; k<d; k++) {
                scanf("%d", &matriz[j][k]);
                if(matriz[j][k] == 1) teste1++;
                if(matriz[j][k] != 1 && matriz[j][k] != 0) teste0++;
            }
            if(teste1!=1 || teste0!=0) resultado++;
        }
        for(j=0; j<d; j++) {
            teste1 = 0; 
            teste0 = 0;
            for(k=0; k<d; k++) {
                if(matriz[k][j] == 1) teste1++;
                if(matriz[k][j] != 1 && matriz[k][j] != 0) teste0++;
            }
            if(teste1!=1 || teste0!=0) resultado++;
        }
        
        if(resultado==0) printf("Matriz permutacao\n");
        else printf("Nao permutacao\n");
        
    }
        
        
        
    
    return 0;
}
