#include <stdio.h>

int main()
{
    
    float renda;
    int numPessoas, escola, etnia, L, l1=0, l2=0, l3=0, l4=0, l5=0;
    
    do {
        scanf("%f %d %d %d", &renda, &numPessoas, &escola, &etnia);
        if(renda!=-1 && numPessoas!=-1 && escola!=-1 && etnia!=-1) {
            if(escola==2) {
                if((renda/numPessoas)<=(1.5*937.00)) {
                    if(etnia<4) {
                        l2++;
                        L=2;
                    } else {
                        l1++;
                        L=1;
                    }
                } else {
                    if(etnia<4) {
                        l4++;
                        L=4;
                    } else {
                        l3++;
                        L=3;
                    }
                }
            } else {
                l5++;
                L = 5;
            }
            printf("ALUNO COTISTA (L%d)\n", L);
        }
        
    } while(renda!=-1 && numPessoas!=-1 && escola!=-1 && etnia!=-1);
    printf("TOTAL (L1): %d\nTOTAL (L2): %d\nTOTAL (L3): %d\nTOTAL (L4): %d\nTOTAL NAO COTISTA: %d\n", l1, l2, l3, l4, l5);


    return 0;
}