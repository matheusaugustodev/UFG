public class Heranca_Funcionarios {

    static class Pessoa {
        protected String nome;
        protected String telefone;

        public Pessoa(String nome, String telefone) {
            this.nome = nome;
            this.telefone = telefone;
        }

        public String getNome() {
            return nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getTelefone() {
            return telefone;
        }

        public void setTelefone(String telefone) {
            this.telefone = telefone;
        }
    }

    // Classe Funcionario (subclasse de Pessoa)
    static class Funcionario extends Pessoa {
        protected String matricula;
        protected double salario;

        public Funcionario(String nome, String telefone, String matricula, double salario) {
            super(nome, telefone);
            this.matricula = matricula;
            this.salario = salario;
        }

        public void aumentarSalario(double percentual) {
            this.salario += this.salario * (percentual / 100);
        }

        public double getRecebimentoAnual() {
            return this.salario * 12;
        }

        public String getMatricula() {
            return matricula;
        }

        public void setMatricula(String matricula) {
            this.matricula = matricula;
        }

        public double getSalario() {
            return salario;
        }

        public void setSalario(double salario) {
            this.salario = salario;
        }
    }

    // Classe Caixa (subclasse de Funcionario)
    static class Caixa extends Funcionario {
        private String horario;

        public Caixa(String nome, String telefone, String matricula, double salario, String horario) {
            super(nome, telefone, matricula, salario);
            this.horario = horario;
        }

        public String getHorario() {
            return horario;
        }

        public void setHorario(String horario) {
            this.horario = horario;
        }

        public String toString() {
            return "Nome: " + nome + "\n" +
                    "Telefone: " + telefone + "\n" +
                    "Matrícula: " + matricula + "\n" +
                    "Salário: " + salario + "\n" +
                    "Horário: " + horario + "\n";
        }
    }

    // Classe Gerente (subclasse de Funcionario)
    static class Gerente extends Funcionario {
        private double bonificacao;
        private String tipo; // PF para gerente de pessoa física, PJ para jurídica

        public Gerente(String nome, String telefone, String matricula, double salario, double bonificacao, String tipo) {
            super(nome, telefone, matricula, salario);
            this.bonificacao = bonificacao;
            this.tipo = tipo;
        }

        public void aumentarSalario(double percentual) {
            super.aumentarSalario(percentual + 20);
        }

        public double getRecebimentoAnual() {
            return super.getRecebimentoAnual() + (this.bonificacao * 12);
        }

        public double getBonificacao() {
            return bonificacao;
        }

        public void setBonificacao(double bonificacao) {
            this.bonificacao = bonificacao;
        }

        public String getTipo() {
            return tipo;
        }

        public void setTipo(String tipo) {
            this.tipo = tipo;
        }

        public String toString() {
            return "Nome: " + nome + "\n" +
                    "Telefone: " + telefone + "\n" +
                    "Matrícula: " + matricula + "\n" +
                    "Salário: " + salario + "\n" +
                    "Bonificação: " + bonificacao + "\n" +
                    "Tipo: " + tipo + "\n";
        }
    }

    // Classe Cliente
    static class Cliente extends Pessoa {
        private int idade;
        private String cpf;
        private char status; // 'A' - Ativo, 'I' - Inativo

        public Cliente(String nome, String telefone, int idade, String cpf) {
            super(nome, telefone);
            this.idade = idade;
            this.cpf = cpf;
            this.status = 'A';
        }

        public void desativar() {
            this.status = 'I';
        }

        public String toString() {
            String statusStr = (this.status == 'A') ? "ativo" : "inativo";
            return "Nome: " + nome + "\n" +
                    "Telefone: " + telefone + "\n" +
                    "Idade: " + idade + " anos\n" +
                    "CPF: " + cpf + "\n" +
                    "Status: " + statusStr + "\n";
        }

        public int getIdade() {
            return idade;
        }

        public void setIdade(int idade) {
            this.idade = idade;
        }

        public String getCpf() {
            return cpf;
        }

        public void setCpf(String cpf) {
            this.cpf = cpf;
        }

        public char getStatus() {
            return status;
        }

        public void setStatus(char status) {
            this.status = status;
        }
    }


    public static void main(String[] args) {
        // Criando um caixa
        Caixa caixa = new Caixa("João", "1234-5678", "C001", 2000.0, "09:00 - 18:00");
        caixa.aumentarSalario(10);
        System.out.println("Dados do Caixa:");
        System.out.println(caixa);

        // Criando um gerente
        Gerente gerente = new Gerente("Maria", "9876-5432", "G001", 4000.0, 500.0, "PF");
        gerente.aumentarSalario(20);
        System.out.println("\nDados do Gerente:");
        System.out.println(gerente);

        // Criando clientes
        Cliente cliente1 = new Cliente("Carlos", "1111-2222", 30, "12345678900");
        Cliente cliente2 = new Cliente("Ana", "3333-4444", 25, "98765432100");
        Cliente cliente3 = new Cliente("Pedro", "5555-6666", 45, "45678912300");

        // Desativando um cliente
        cliente2.desativar();

        // Mostrando os dados dos clientes
        System.out.println("\nDados do Cliente 1:");
        System.out.println(cliente1);

        System.out.println("\nDados do Cliente 2:");
        System.out.println(cliente2);

        System.out.println("\nDados do Cliente 3:");
        System.out.println(cliente3);
    }

}