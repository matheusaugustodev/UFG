public class Exercicio {
    
    public static class Empresa {
        private static Empresa instance;
        private String nome;
        private String cnpj;
        private String endereco;
        private String cep;

        private Empresa() {
            this.nome = "EBM INCORPORACOES S/A";
            this.cnpj = "03.025.881/0002-74";
            this.endereco = "Rua T 55, 930 SETOR BUENO GOIANIA – GO";
            this.cep = "74215-170";
        }

        public static Empresa getInstance() {
            if (instance == null) {
                instance = new Empresa();
            }
            return instance;
        }

        public String getNome() {
            return nome;
        }

        public String getCnpj() {
            return cnpj;
        }

        public String getEndereco() {
            return endereco;
        }

        public String getCep() {
            return cep;
        }
    }

    public static class Projeto {
        private String nome;
        private String descricao;
        private Empresa empresa;

        public Projeto(String nome, String descricao) {
            this.nome = nome;
            this.descricao = descricao;
            this.empresa = Empresa.getInstance();
        }

        public String getNome() {
            return nome;
        }

        public String getDescricao() {
            return descricao;
        }

        public Empresa getEmpresa() {
            return empresa;
        }
    }

    public static void main(String[] args) {
        Empresa empresa = Empresa.getInstance();
        System.out.println("Empresa: " + empresa.getNome());
        System.out.println("CNPJ: " + empresa.getCnpj());
        System.out.println("Endereco: " + empresa.getEndereco());
        System.out.println("CEP: " + empresa.getCep());

        Projeto projeto1 = new Projeto("Projeto Alpha", "Desenvolvimento do sistema Alpha.");
        Projeto projeto2 = new Projeto("Projeto Beta", "Desenvolvimento do sistema Beta.");

        System.out.println("\nProjetos:");
        System.out.println("Nome: " + projeto1.getNome() + ", Descricao: " + projeto1.getDescricao() + ", Empresa: " + projeto1.getEmpresa().getNome());
        System.out.println("Nome: " + projeto2.getNome() + ", Descricao: " + projeto2.getDescricao() + ", Empresa: " + projeto2.getEmpresa().getNome());
    }
    
}