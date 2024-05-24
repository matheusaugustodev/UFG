import java.util.Scanner; 

public class Lab_2_1 {

    static class Produto {
        int codigo;
        String nome;
        int quantidade;
        String tipo;
        double preco;
        
        public String toString() {
            return "Código: " + codigo + "\nNome: " + nome + "\nQuantidade: " + quantidade + "\nTipo: " + tipo + "\nPreço: " + preco;
        }

        // Construtores

        Produto(int codigo) {
            this.codigo = codigo;
        }

        Produto(int codigo, String nome) {
            this.codigo = codigo;
            this.nome = nome;
        }

        Produto(int codigo, String nome, int quantidade) {
            this.codigo = codigo;
            this.nome = nome;
            this.quantidade = quantidade;
        }

        Produto(int codigo, String nome, int quantidade, String tipo, double preco) {
            this.codigo = codigo;
            this.nome = nome;
            this.quantidade = quantidade;
            this.tipo = tipo;
            this.preco = preco;
        }
        
        void vender(int quantidade) {
            if (quantidade > this.quantidade) {
                System.out.println("Estoque insuficiente.");
            } else {
                this.quantidade -= quantidade;
                System.out.println("Venda realizada com sucesso. Valor total da venda: " + quantidade * preco);
            }
        }

        void comprar(int quantidade, double novoPreco) {
            this.quantidade += quantidade;
            this.preco = novoPreco;
        }

        void comprar(int quantidade) {
            this.quantidade += quantidade;
        }

        void inserir(String nome, int quantidade, String tipo, double preco) {
            this.nome = nome;
            this.quantidade = quantidade;
            this.tipo = tipo;
            this.preco = preco;
        }

        void igual(Produto produto) {
            System.out.println(this.nome.equals(produto.nome) && this.tipo.equals(produto.tipo));
        }

    }

    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o código do produto 1: ");
        int codigo = sc.nextInt();
        Produto produto1 = new Produto(codigo);

        System.out.println("Digite o código do produto 2: ");
        int codigo2 = sc.nextInt();
        System.out.println("Digite o nome do produto 2: ");
        String nome = sc.next();
        System.out.println("Digite a quantidade do produto 2: ");
        int quantidade = sc.nextInt();
        System.out.println("Digite o tipo do produto 2: ");
        String tipo = sc.next();
        System.out.println("Digite o preço do produto 2: ");
        double preco = sc.nextDouble();
        Produto produto2 = new Produto(codigo2, nome, quantidade, tipo, preco);

        System.out.println("Digite o código do produto 3: ");
        int codigo3 = sc.nextInt();
        System.out.println("Digite o nome do produto 3: ");
        String nome3 = sc.next();
        System.out.println("Digite a quantidade do produto 3: ");
        int quantidade3 = sc.nextInt();
        System.out.println("Digite o tipo do produto 3: ");
        String tipo3 = sc.next();
        System.out.println("Digite o preço do produto 3: ");
        double preco3 = Double.parseDouble(sc.next());
        Produto produto3 = new Produto(codigo3, nome3, quantidade3, tipo3, preco3);

        produto1.inserir("Jogo Batalha Naval", 10, "jogo", 100.00);
        produto1.vender(5);
        produto1.comprar(10, 150.00);
        produto1.igual(produto2);

        produto2.vender(1);
        produto2.comprar(8, 20.00);
        produto2.igual(produto3);

        produto3.vender(2);
        produto3.comprar(2, 10.00);
        produto3.igual(produto1);

        System.out.println("Produto 1: ");
        System.out.println(produto1);

        System.out.println("Produto 2: ");
        System.out.println(produto2);

        System.out.println("Produto 3: ");
        System.out.println(produto3);

        sc.close();
    }
}