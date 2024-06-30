public class Exercicio {

    abstract class Fabrica {
        public abstract Documento criarDocumento(int numero, String remetente, String tipo);
    }

    public class FabricaDocumentos extends Fabrica {
        @Override
        public Documento criarDocumento(int numero, String remetente, String tipo) {
            switch (tipo.toLowerCase()) {
                case "carta":
                    return new Carta(numero, remetente);
                case "notificacao":
                    return new Notificacao(numero, remetente);
                case "telegrama":
                    return new Telegrama(numero, remetente);
                default:
                    throw new IllegalArgumentException("Tipo de documento desconhecido: " + tipo);
            }
        }
    }

    public abstract class Documento {
        private int numero;
        private String remetente;

        public Documento(int numero, String remetente) {
            this.numero = numero;
            this.remetente = remetente;
        }

        public int getNumero() {
            return numero;
        }

        public String getRemetente() {
            return remetente;
        }

        public abstract String getTipo();
    }

    public class Carta extends Documento {
        public Carta(int numero, String remetente) {
            super(numero, remetente);
        }

        @Override
        public String getTipo() {
            return "Carta";
        }
    }

    public class Telegrama extends Documento {
        public Telegrama(int numero, String remetente) {
            super(numero, remetente);
        }

        @Override
        public String getTipo() {
            return "Telegrama";
        }
    }

    public class Notificacao extends Documento {
        public Notificacao(int numero, String remetente) {
            super(numero, remetente);
        }

        @Override
        public String getTipo() {
            return "Notificacao";
        }
    }

    class CadastroDocumentos {
        private Fabrica fabrica;

        public CadastroDocumentos(Fabrica fabrica) {
            this.fabrica = fabrica;
        }

        public Documento cadastrarDocumento(int numero, String remetente, String tipo) {
            return fabrica.criarDocumento(numero, remetente, tipo);
        }
    }

    public static void main(String[] args) {
        Exercicio exercicio = new Exercicio();
        Fabrica fabrica = exercicio.new FabricaDocumentos();
        CadastroDocumentos cadastro = exercicio.new CadastroDocumentos(fabrica);

        Documento doc1 = cadastro.cadastrarDocumento(1, "Remetente A", "carta");
        System.out.println("Documento: " + doc1.getTipo() + ", Numero: " + doc1.getNumero() + ", Remetente: "
                + doc1.getRemetente());

        Documento doc2 = cadastro.cadastrarDocumento(2, "Remetente B", "notificacao");
        System.out.println("Documento: " + doc2.getTipo() + ", Numero: " + doc2.getNumero() + ", Remetente: "
                + doc2.getRemetente());

        Documento doc3 = cadastro.cadastrarDocumento(3, "Remetente C", "telegrama");
        System.out.println("Documento: " + doc3.getTipo() + ", Numero: " + doc3.getNumero() + ", Remetente: "
                + doc3.getRemetente());
    }
}