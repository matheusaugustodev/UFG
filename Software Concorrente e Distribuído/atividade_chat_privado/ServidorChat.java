import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.*;

public class ServidorChat {
    private static final int PORTA = 12345;
    private static final Map<String, PrintStream> clientes = new ConcurrentHashMap<>();

    public static void main(String[] args) throws IOException {
        ServerSocket servidor = new ServerSocket(PORTA);
        System.out.println("Servidor iniciado na porta " + PORTA);

        while (true) {
            Socket cliente = servidor.accept();
            new Thread(new TrataCliente(cliente)).start();
        }
    }

    static class TrataCliente implements Runnable {
        private Socket socket;
        private String nome;
        private Scanner entrada;

        public TrataCliente(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try {
                entrada = new Scanner(socket.getInputStream());
                PrintStream saida = new PrintStream(socket.getOutputStream());

                saida.println("Digite seu nome:");
                nome = entrada.nextLine().trim();

                if (nome.isEmpty() || clientes.containsKey(nome)) {
                    saida.println("Nome inválido ou já em uso. Conexão encerrada.");
                    socket.close();
                    return;
                }

                clientes.put(nome, saida);
                enviarParaTodos("*", nome + " entrou no chat.");

                while (entrada.hasNextLine()) {
                    String mensagem = entrada.nextLine();
                    if (!mensagem.contains(":")) continue;

                    String[] partes = mensagem.split(":", 2);
                    if (partes.length < 2) continue;

                    String destinatario = partes[0];
                    String conteudo = partes[1];

                    if (destinatario.equals("*")) {
                        enviarParaTodos(nome, conteudo);
                    } else {
                        enviarPara(destinatario, nome + ": " + conteudo);
                    }
                }

            } catch (IOException e) {
                System.out.println("Erro com cliente: " + nome);
            } finally {
                try {
                    if (nome != null) {
                        clientes.remove(nome);
                        enviarParaTodos("*", nome + " saiu do chat.");
                    }
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        private void enviarPara(String destinatario, String mensagem) {
            PrintStream ps = clientes.get(destinatario);
            if (ps != null) {
                ps.println(mensagem);
            }
        }

        private void enviarParaTodos(String remetente, String mensagem) {
            for (Map.Entry<String, PrintStream> entry : clientes.entrySet()) {
                if (!entry.getKey().equals(remetente)) {
                    entry.getValue().println(remetente + ": " + mensagem);
                }
            }
        }
    }
}