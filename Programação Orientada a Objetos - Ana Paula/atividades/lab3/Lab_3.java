import java.util.ArrayList;
import java.util.Scanner;

public class Lab_3 {

    static class Produto {
        private String nome;
        private String tamanho;
        private String tipo;
        private String cor;
        private String especificacao;

        public Produto(String nome, String tamanho, String tipo, String cor, String especificacao) {
            this.nome = nome;
            this.tamanho = tamanho;
            this.tipo = tipo;
            this.cor = cor;
            this.especificacao = especificacao;
        }

        public String getNome() {
            return nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getTamanho() {
            return tamanho;
        }

        public void setTamanho(String tamanho) {
            this.tamanho = tamanho;
        }

        public String getTipo() {
            return tipo;
        }

        public void setTipo(String tipo) {
            this.tipo = tipo;
        }

        public String getCor() {
            return cor;
        }

        public void setCor(String cor) {
            this.cor = cor;
        }

        public String getEspecificacao() {
            return especificacao;
        }

        public void setEspecificacao(String especificacao) {
            this.especificacao = especificacao;
        }

        public String toString() {
            return "Produto: " + this.nome + "\nTamanho: " + this.tamanho + "\nTipo: " + this.tipo + "\nCor: " + this.cor + "\nEspecificação: " + this.especificacao;
        }
    }

    static class Empresa {
        private String nome;
        private String cnpj;
        private String contatoResponsavel;
        private String telefone;
        private ArrayList<Produto> produtos;

        public Empresa(String nome, String cnpj, String contatoResponsavel, String telefone) {
            this.nome = nome;
            this.cnpj = cnpj;
            this.contatoResponsavel = contatoResponsavel;
            this.telefone = telefone;
            this.produtos = new ArrayList<Produto>();
        }

        public String getNome() {
            return nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getCnpj() {
            return cnpj;
        }

        public void setCnpj(String cnpj) {
            this.cnpj = cnpj;
        }

        public String getContatoResponsavel() {
            return contatoResponsavel;
        }

        public void setContatoResponsavel(String contatoResponsavel) {
            this.contatoResponsavel = contatoResponsavel;
        }

        public String getTelefone() {
            return telefone;
        }

        public void setTelefone(String telefone) {
            this.telefone = telefone;
        }

        public ArrayList<Produto> getProdutos() {
            return produtos;
        }

        public void setProdutos(ArrayList<Produto> produtos) {
            this.produtos = produtos;
        }

        public void addProduto(Produto produto) {
            this.produtos.add(produto);
        }

        public String toString() {
            return "Empresa: " + this.nome + "\nCNPJ: " + this.cnpj + "\nContato do Responsável: " + this.contatoResponsavel + "\nTelefone: " + this.telefone + "\nProdutos: " + this.produtos;
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        ArrayList<Empresa> empresas = new ArrayList<Empresa>();

        char cadastrarEmpresa = 'S';
        while (cadastrarEmpresa == 'S') {
            System.out.println("Cadastrar nova empresa (S/N)?");
            cadastrarEmpresa = scanner.next().charAt(0);

            if (cadastrarEmpresa == 'S') {
                System.out.println("Digite o nome da empresa: ");
                String nome = scanner.next();
                System.out.println("Digite o CNPJ da empresa: ");
                String cnpj = scanner.next();
                System.out.println("Digite o contato do responsável: ");
                String contatoResponsavel = scanner.next();
                System.out.println("Digite o telefone da empresa: ");
                String telefone = scanner.next();

                Empresa empresa = new Empresa(nome, cnpj, contatoResponsavel, telefone);

                char cadastrarProduto = 'S';
                while (cadastrarProduto == 'S') {
                    System.out.println("Cadastrar produto para a empresa (S/N)?");
                    cadastrarProduto = scanner.next().charAt(0);

                    if (cadastrarProduto == 'S') {
                        System.out.println("Digite o nome do produto: ");
                        String nomeProduto = scanner.next();
                        System.out.println("Digite o tamanho do produto: ");
                        String tamanho = scanner.next();
                        System.out.println("Digite o tipo do produto: ");
                        String tipo = scanner.next();
                        System.out.println("Digite a cor do produto: ");
                        String cor = scanner.next();
                        System.out.println("Digite a especificação do produto: ");
                        String especificacao = scanner.next();

                        Produto produto = new Produto(nomeProduto, tamanho, tipo, cor, especificacao);
                        empresa.addProduto(produto);
                    }
                }

                empresas.add(empresa);
            }
        }

        for (Empresa empresa : empresas) {
            System.out.println("-----------------------------");
            System.out.println(empresa);
            System.out.println("-----------------------------");
        }

        scanner.close();
    }

}
