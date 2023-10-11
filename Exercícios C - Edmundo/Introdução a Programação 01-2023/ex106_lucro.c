#include <stdio.h>

int main()
{
    unsigned long int codigo;
    float venda, compra, maiorLucro, lucro, lucroTotal, vendaTotal, compraTotal;
    int n, num, lucro10, lucro10e20, lucro20, numMaisVendido, codMaiorLucro, codMaisVendido;
    
    compraTotal = 0;
    vendaTotal = 0;
    lucroTotal = 0;
    lucro20 = 0;
    lucro10 = 0;
    lucro10e20 = 0;
    numMaisVendido = -1;
    maiorLucro= -1;
    codMaisVendido = -1;
    codMaiorLucro = -1;
    
    while(scanf("%lu %f %f %d", &codigo, &compra, &venda, &num)!=EOF) {
        lucro = (num*venda)/(num*compra);
        
        if(num>numMaisVendido) {
            numMaisVendido = num;
            codMaisVendido = codigo;
        }
        if(lucro>maiorLucro) {
            maiorLucro = lucro;
            codMaiorLucro = codigo;
        }

        if(lucro>1.20) lucro20++;
        else if(lucro>=1.10 && lucro<=1.20) lucro10e20++;
        else lucro10++;
        
        vendaTotal += venda*num;
        compraTotal += compra*num;
    }        
    lucroTotal = (((vendaTotal-compraTotal))/compraTotal)*100;

    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", lucro10);
    printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", lucro10e20);
    printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", lucro20);
    printf("Codigo da mercadoria que gerou maior lucro: %d\n", codMaiorLucro);
    printf("Codigo da mercadoria mais vendida: %d\n", codMaisVendido);
    printf("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%\n", compraTotal, vendaTotal, lucroTotal);
    

    return 0;
}