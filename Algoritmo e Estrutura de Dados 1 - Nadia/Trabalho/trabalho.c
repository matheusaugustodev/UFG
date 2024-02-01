#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_NOME 100
#define TAMANHO_MAXIMO_VENDAS 100
#define TAMANHO_MAXIMO_HISTORICO 1000
#define TAMANHO_MAXIMO_ESTOQUE 200

typedef struct {
    char tipo_movimentacao; // 'E' para entrada, 'V' para venda e 'R' para remoção

    int codigo; // Codigo do produto movimentado
    char nome[TAMANHO_NOME]; // Nome do produto
    char marca[TAMANHO_NOME]; // Marca do produto
    float preco;

    char tipo_produto[TAMANHO_NOME]; // bebida, higiene, hortifruti, perecivel, padaria, limpeza, nao perecivel
} Movimentacao;

typedef struct {
    int numero_movimentacao; // Número da movimentação no historico

    Movimentacao movimentacoes[TAMANHO_MAXIMO_HISTORICO];
} Historico;

typedef struct {
    int codigo;
    float preco;
    char nome[TAMANHO_NOME];
    char marca[TAMANHO_NOME];

    char tipo[TAMANHO_NOME]; // bebida, higiene, hortifruti, perecivel, padaria, limpeza, nao perecivel
} Produto;

typedef struct {
    Produto produtos[TAMANHO_MAXIMO_ESTOQUE];

    int quantidade_bebidas;
    int quantidade_higiene;
    int quantidade_hortifruti;
    int quantidade_perecivel;
    int quantidade_padaria;
    int quantidade_limpeza;
    int quantidade_nao_perecivel;

    int quantidade_total;
} Estoque;

int verificar_se_existe_codigo(int codigo, Estoque *estoque) {
    int i;
    int ja_existe = 0;

    for (i = 0; i < estoque->quantidade_total; i++) {
        if (codigo == estoque->produtos[i].codigo) {
            printf("Codigo ja existente no estoque.\n\n");

            ja_existe = 1;
            break;
        }
    }

    return ja_existe;
}

char* selecionar_tipo_produto() {
    printf("\nTipos de produto:\n");
    printf("-----------------\n");
    printf("1. Bebida\n");
    printf("2. Higiene\n");
    printf("3. Hortifruti\n");
    printf("4. Perecivel\n");
    printf("5. Padaria\n");
    printf("6. Limpeza\n");
    printf("7. Nao Perecivel\n");
    printf("-----------------\n");

    char *listaTipos[] = {"Bebida", "Higiene", "Hortifruti", "Perecivel", "Padaria", "Limpeza", "Nao Perecivel"};

    int numero_tipo;
    int digito_invalido = 0;

    do {
        printf("Digite o numero do tipo de produto (1 - 7): ");

        if (scanf("%d", &numero_tipo) != 1 || numero_tipo < 1 || numero_tipo > 7) {
            printf("Tipo invalido.\n\n");

            // Limpar o buffer de entrada
            while (getchar() != '\n');
        } else {
            digito_invalido = 1;
        }

    } while (digito_invalido == 0);

    char* tipoProduto = listaTipos[numero_tipo - 1];

    return tipoProduto;
}

int inserir_codigo_produto(Estoque *estoque) {
    int codigo;
    int codigo_invalido = 0;

    do {
        printf("Digite o codigo do produto (1 - 200): ");

        if (scanf("%d", &codigo) != 1 || codigo < 1 || codigo > 200) {
            printf("Codigo invalido.\n\n");

            // Limpar o buffer de entrada
            while (getchar() != '\n');
            codigo_invalido = 0;
        } else if (verificar_se_existe_codigo(codigo, estoque) != 0) {
            codigo_invalido = 0; 
        } else {
            codigo_invalido = 1;
        }

    } while (codigo_invalido == 0);

    return codigo;
}

float inserir_preco_produto() {
    float preco;
    int preco_invalido = 0;

    do {
        printf("Preco em R$ (1 - 10000): ");

        if (scanf("%f", &preco) != 1 || preco < 1 || preco > 10000) {
            printf("Preco invalido.\n\n");

            // Limpar o buffer de entrada
            while (getchar() != '\n');
            preco_invalido = 0;
        } else {
            preco_invalido = 1;
        }

    } while (preco_invalido == 0);

    return preco;
}

void exibir_produto(Produto produto) {
    printf("-------------------------------------------\n");
    printf("Codigo: %d\n", produto.codigo);
    printf("Nome: %s\n", produto.nome);
    printf("Marca: %s\n", produto.marca);
    printf("Preco: %.2f\n", produto.preco);
    printf("-------------------------------------------\n");
}

void adicionar_produto(Estoque *estoque, Historico* historico) {

    Produto novo_produto;
    
    char* tipo = selecionar_tipo_produto();

    if (strcmp(tipo, "Bebida") == 0) {
        estoque->quantidade_bebidas++;
    } else if (strcmp(tipo, "Higiene") == 0) {
        estoque->quantidade_higiene++;
    } else if (strcmp(tipo, "Hortifruti") == 0) {
        estoque->quantidade_hortifruti++;
    } else if (strcmp(tipo, "Perecivel") == 0) {
        estoque->quantidade_perecivel++;
    } else if (strcmp(tipo, "Padaria") == 0) {
        estoque->quantidade_padaria++;
    } else if (strcmp(tipo, "Limpeza") == 0) {
        estoque->quantidade_limpeza++;
    } else if (strcmp(tipo, "Nao Perecivel") == 0) {
        estoque->quantidade_nao_perecivel++;
    }

    strcpy(novo_produto.tipo, tipo);

    novo_produto.codigo = inserir_codigo_produto(estoque);
    novo_produto.preco = inserir_preco_produto();

    printf("Marca: ");
    scanf(" %[^\n]", novo_produto.marca);
    getchar(); // Limpar o buffer do teclado

    printf("Nome do produto: ");
    scanf(" %[^\n]", novo_produto.nome);
    getchar(); // Limpar o buffer do teclado

    estoque->produtos[estoque->quantidade_total] = novo_produto;

    Movimentacao nova_movimentacao;

    // adicionar movimentacao no historico
    nova_movimentacao.tipo_movimentacao = 'E';
    nova_movimentacao.codigo = novo_produto.codigo;
    strcpy(nova_movimentacao.nome, novo_produto.nome);
    strcpy(nova_movimentacao.marca, novo_produto.marca);
    nova_movimentacao.preco = novo_produto.preco;
    strcpy(nova_movimentacao.tipo_produto, novo_produto.tipo);

    historico->movimentacoes[historico->numero_movimentacao] = nova_movimentacao;
    historico->numero_movimentacao++;

    printf("\n============ Produto adicionado ===========\n");
    printf("Codigo: %d\n", estoque->produtos[estoque->quantidade_total].codigo);
    printf("Nome: %s\n", estoque->produtos[estoque->quantidade_total].nome);
    printf("Marca: %s\n", estoque->produtos[estoque->quantidade_total].marca);
    printf("Preco: R$ %.2f\n", estoque->produtos[estoque->quantidade_total].preco);
    printf("Tipo: %s\n", estoque->produtos[estoque->quantidade_total].tipo);
    printf("===========================================\n");

    estoque->quantidade_total++;
}

void remover_produto(Estoque *estoque, Historico* historico) {
    
    if (estoque->quantidade_total == 0) {
        printf("\n-------------- Estoque Vazio --------------\n");
        return;
    }

    int codigo;
    int i;
    int produto_encontrado = 0;

    printf("\nDigite o codigo do produto a ser removido: ");
    scanf("%d", &codigo);

    for (i = 0; i < estoque->quantidade_total; i++) {
        if (codigo == estoque->produtos[i].codigo) {
            produto_encontrado = 1;
            break;
        }
    }

    if (produto_encontrado == 1) {
        // adicionar movimentacao no historico
        Movimentacao nova_movimentacao;
        nova_movimentacao.tipo_movimentacao = 'R';
        nova_movimentacao.codigo = estoque->produtos[i].codigo;
        strcpy(nova_movimentacao.nome, estoque->produtos[i].nome);
        strcpy(nova_movimentacao.marca, estoque->produtos[i].marca);
        nova_movimentacao.preco = estoque->produtos[i].preco;
        historico->movimentacoes[historico->numero_movimentacao] = nova_movimentacao;
        historico->numero_movimentacao++;

        printf("---------- Produto removido ----------\n");
        printf("Codigo: %d\n", estoque->produtos[i].codigo);
        printf("Nome: %s\n", estoque->produtos[i].nome);
        printf("Marca: %s\n", estoque->produtos[i].marca);
        printf("Preco: R$ %.2f\n", estoque->produtos[i].preco);
        printf("Tipo: %s\n", estoque->produtos[i].tipo);
        printf("-------------------------------------------\n");

        for (int j = i; j < estoque->quantidade_total - 1; j++) {
            estoque->produtos[j] = estoque->produtos[j + 1];
        }

        estoque->quantidade_total--;
    }
    else {
        printf("---------- Produto nao encontrado ----------\n");
    }
}

void realizar_venda(Estoque *estoque, Historico* historico) {

    if (estoque->quantidade_total == 0) {
        printf("\n-------------- Estoque Vazio --------------\n");
        return;
    }

    int codigo;
    int i, j;
    int produto_encontrado = 0;

    printf("\nDigite o codigo do produto a ser vendido: ");
    scanf("%d", &codigo);

    for (i = 0; i < estoque->quantidade_total; i++) {
        if (codigo == estoque->produtos[i].codigo) {
            produto_encontrado = 1;
            break;
        }
    }

    if (produto_encontrado == 1) {

        // adicionar movimentacao no historico
        Movimentacao nova_movimentacao;
        nova_movimentacao.tipo_movimentacao = 'V';
        nova_movimentacao.codigo = estoque->produtos[i].codigo;
        strcpy(nova_movimentacao.nome, estoque->produtos[i].nome);
        strcpy(nova_movimentacao.marca, estoque->produtos[i].marca);
        nova_movimentacao.preco = estoque->produtos[i].preco;
        strcpy(nova_movimentacao.tipo_produto, estoque->produtos[i].tipo);

        historico->movimentacoes[historico->numero_movimentacao] = nova_movimentacao;
        historico->numero_movimentacao++;

        // diminuir quantidade do estoque
        if (strcmp(estoque->produtos[i].tipo, "Bebida") == 0) {
            estoque->quantidade_bebidas--;
        } else if (strcmp(estoque->produtos[i].tipo, "Higiene") == 0) {
            estoque->quantidade_higiene--;
        } else if (strcmp(estoque->produtos[i].tipo, "Hortifruti") == 0) {
            estoque->quantidade_hortifruti--;
        } else if (strcmp(estoque->produtos[i].tipo, "Perecivel") == 0) {
            estoque->quantidade_perecivel--;
        } else if (strcmp(estoque->produtos[i].tipo, "Padaria") == 0) {
            estoque->quantidade_padaria--;
        } else if (strcmp(estoque->produtos[i].tipo, "Limpeza") == 0) {
            estoque->quantidade_limpeza--;
        } else if (strcmp(estoque->produtos[i].tipo, "Nao Perecivel") == 0) {
            estoque->quantidade_nao_perecivel--;
        }

        // Remover o produto do estoque
        for (j = i; j < estoque->quantidade_total - 1; j++) {
            estoque->produtos[j] = estoque->produtos[j + 1];
        }

        estoque->quantidade_total--;
        printf("-------------- Produto vendido --------------\n");
        printf("Codigo: %d\n", estoque->produtos[i].codigo);
        printf("Nome: %s\n", estoque->produtos[i].nome);
        printf("Marca: %s\n", estoque->produtos[i].marca);
        printf("Preco: R$ %.2f\n", estoque->produtos[i].preco);
        printf("Tipo: %s\n", estoque->produtos[i].tipo);
        printf("-------------------------------------------\n");
    }
    else {
        printf("---------- Produto nao encontrado ----------\n");
    }
}

void exibir_estoque(Estoque *estoque) {
    
    int i;       

    if (estoque->quantidade_total == 0) {

        printf("\n-------------- Estoque Vazio --------------\n");
    } else {

        printf("\n----------- Estoque / Total: %d ------------\n", estoque->quantidade_total);

        printf("\n--------- Bebidas / Quantidade: %d ---------\n", estoque->quantidade_bebidas);

        if (estoque->quantidade_bebidas > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Bebida") == 0) {
                    exibir_produto(estoque->produtos[i]);
                }
            }
        }

        
        printf("\n--------- Higiene / Quantidade: %d ---------\n", estoque->quantidade_higiene);

        if (estoque->quantidade_higiene > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Higiene") == 0) {
                    printf("-------------------------------------------\n");
                    printf("Codigo: %d\n", estoque->produtos[i].codigo);
                    printf("Nome: %s\n", estoque->produtos[i].nome);
                    printf("Marca: %s\n", estoque->produtos[i].marca);
                    printf("Preco: %.2f\n", estoque->produtos[i].preco);
                    printf("-------------------------------------------\n");
                }
            }
        }

        printf("\n-------- Hortifruti / Quantidade: %d -------\n", estoque->quantidade_hortifruti);

        if (estoque->quantidade_hortifruti > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Hortifruti") == 0) {
                    printf("-------------------------------------------\n");
                    printf("Codigo: %d\n", estoque->produtos[i].codigo);
                    printf("Nome: %s\n", estoque->produtos[i].nome);
                    printf("Marca: %s\n", estoque->produtos[i].marca);
                    printf("Preco: %.2f\n", estoque->produtos[i].preco);
                    printf("-------------------------------------------\n");
                }
            }
        }

        printf("\n-------- Perecivel / Quantidade: %d --------\n", estoque->quantidade_perecivel);

        if (estoque->quantidade_perecivel > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Perecivel") == 0) {
                    printf("-------------------------------------------\n");
                    printf("Codigo: %d\n", estoque->produtos[i].codigo);
                    printf("Nome: %s\n", estoque->produtos[i].nome);
                    printf("Marca: %s\n", estoque->produtos[i].marca);
                    printf("Preco: %.2f\n", estoque->produtos[i].preco);
                    printf("-------------------------------------------\n");
                }
            }
        }

        printf("\n--------- Padaria / Quantidade: %d ---------\n", estoque->quantidade_padaria);

        if (estoque->quantidade_padaria > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Padaria") == 0) {
                    printf("-------------------------------------------\n");
                    printf("Codigo: %d\n", estoque->produtos[i].codigo);
                    printf("Nome: %s\n", estoque->produtos[i].nome);
                    printf("Marca: %s\n", estoque->produtos[i].marca);
                    printf("Preco: %.2f\n", estoque->produtos[i].preco);
                    printf("-------------------------------------------\n");
                }
            }
        }

        printf("\n--------- Limpeza / Quantidade: %d ---------\n", estoque->quantidade_limpeza);

        if (estoque->quantidade_limpeza > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Limpeza") == 0) {
                    printf("-------------------------------------------\n");
                    printf("Codigo: %d\n", estoque->produtos[i].codigo);
                    printf("Nome: %s\n", estoque->produtos[i].nome);
                    printf("Marca: %s\n", estoque->produtos[i].marca);
                    printf("Preco: %.2f\n", estoque->produtos[i].preco);
                    printf("-------------------------------------------\n");
                }
            }
        }

        printf("\n------ Nao Perecivel / Quantidade: %d ------\n", estoque->quantidade_nao_perecivel);

        if (estoque->quantidade_nao_perecivel > 0) {

            for (i = 0; i < estoque->quantidade_total; i++) {
                if (strcmp(estoque->produtos[i].tipo, "Nao Perecivel") == 0) {
                    printf("-------------------------------------------\n");
                    printf("Codigo: %d\n", estoque->produtos[i].codigo);
                    printf("Nome: %s\n", estoque->produtos[i].nome);
                    printf("Marca: %s\n", estoque->produtos[i].marca);
                    printf("Preco: %.2f\n", estoque->produtos[i].preco);
                    printf("-------------------------------------------\n");
                }
            }
        }

        printf("\n===========================================\n");
    }
}

void exibir_historico_de_vendas(Historico* historico) {
    
    int i;
    int numero_de_vendas = 0;

    for (i = 0; i < historico->numero_movimentacao; i++) {
        if (historico->movimentacoes[i].tipo_movimentacao == 'V') {
            numero_de_vendas++;
        }
    }

    if (numero_de_vendas == 0) {
        printf("\n------- Nenhuma venda foi realizada -------\n");
    } else {    
        printf("\n----------- Historico de Vendas -----------\n");

        for (i = 0; i < historico->numero_movimentacao; i++) {
            if (historico->movimentacoes[i].tipo_movimentacao == 'V') {
                printf("\n-------------------------------------------\n");
                printf("Codigo: %d\n", historico->movimentacoes[i].codigo);
                printf("Nome: %s\n", historico->movimentacoes[i].nome);
                printf("Marca: %s\n", historico->movimentacoes[i].marca);
                printf("Preco: %.2f\n", historico->movimentacoes[i].preco);
                printf("Tipo: %s\n", historico->movimentacoes[i].tipo_produto);
                printf("-------------------------------------------\n");
            }
        }
        printf("\n-------------------------------------------\n");
    }
}

void imprimir_relatorio_geral(Estoque *estoque, Historico *historico) {

    printf("\n============= Relatorio Geral =============\n");

    exibir_estoque(estoque);
    exibir_historico_de_vendas(historico);

    if (historico->numero_movimentacao == 0) {
        printf("\n---- Nenhuma movimentacao foi realizada ---\n");
    } else {
        printf("\n------- Historico de Movimentacoes --------\n");

        int i;
        for (i = 0; i < historico->numero_movimentacao; i++) {
            printf("-----------------------------------------\n");
            printf("Numero da Movimentacao %d\n", i + 1);

            if (historico->movimentacoes[i].tipo_movimentacao == 'V') {
                printf("Tipo da movimentacao : Venda\n");
            } else if (historico->movimentacoes[i].tipo_movimentacao == 'E') {
                printf("Tipo da movimentacao : Entrada\n");
            } else if (historico->movimentacoes[i].tipo_movimentacao == 'R') {
                printf("Tipo da movimentacao : Remocao\n");
            }

            printf("Codigo: %d\n", historico->movimentacoes[i].codigo);
            printf("Nome: %s\n", historico->movimentacoes[i].nome);
            printf("Marca: %s\n", historico->movimentacoes[i].marca);
            printf("Preco: %.2f\n", historico->movimentacoes[i].preco);
            printf("-------------------------------------------\n");
        }

    }
    
    printf("\n===========================================\n");
}

void menu(){
    printf("\n============== SUPERMERCADO ===============\n");
    printf("1. Adicionar Produto\n");
    printf("2. Remover Produto\n");
    printf("3. Realizar Venda\n");
    printf("4. Exibir Estoque\n");
    printf("5. Exibir Historico de Vendas\n");
    printf("6. Sair e Imprimir Relatorio Geral\n");
    printf("===========================================\n");        
}

int main() {
    Historico historico;
    historico.numero_movimentacao = 0;

    Estoque estoque;
    estoque.quantidade_bebidas = 0;
    estoque.quantidade_higiene = 0;
    estoque.quantidade_hortifruti = 0;
    estoque.quantidade_perecivel = 0;
    estoque.quantidade_padaria = 0;
    estoque.quantidade_limpeza = 0;
    estoque.quantidade_nao_perecivel = 0;
    estoque.quantidade_total = 0;

    int opcao;

    menu();

    do {
        printf("Escolha a opcao desejada (1 - 6): ");

        if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 6) {
            printf("Opcao invalida.\n\n");

            // Limpar o buffer de entrada
            while (getchar() != '\n');
        } else {
            if (opcao == 1) {
                adicionar_produto(&estoque, &historico);
            } else if (opcao == 2) {
                remover_produto(&estoque, &historico);
            } else if (opcao == 3) {
                realizar_venda(&estoque, &historico);
            } else if (opcao == 4) {
                exibir_estoque(&estoque);
            } else if (opcao == 5) {
                exibir_historico_de_vendas(&historico);
            } else if (opcao == 6) {
                imprimir_relatorio_geral(&estoque, &historico);
                printf("Saindo do programa. Obrigado!\n\n");
            }

            if (opcao != 6) {
                menu();            
            }
        }

    } while (opcao != 6);

    return 0;
}