import java.io.*;
import java.net.*;
import java.util.*;
import java.util.Base64;

public class ClienteChat {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("127.0.0.1", 12345);
        System.out.println("Conectado ao servidor!");

        Scanner teclado = new Scanner(System.in);
        Scanner entrada = new Scanner(socket.getInputStream());
        PrintStream saida = new PrintStream(socket.getOutputStream());

        new Thread(() -> {
            while (entrada.hasNextLine()) {
                String linha = entrada.nextLine();

                if (linha.startsWith("ARQUIVO:")) {
                    String[] partes = linha.split(":", 4);
                    if (partes.length < 4) continue;

                    String remetente = partes[1];
                    String nomeArquivo = partes[2];
                    String base64 = partes[3];

                    try {
                        File pasta = new File("arquivos_recebidos/" + remetente);
                        if (!pasta.exists()) pasta.mkdirs();

                        byte[] dados = Base64.getDecoder().decode(base64);
                        FileOutputStream fos = new FileOutputStream(pasta + "/" + nomeArquivo);
                        fos.write(dados);
                        fos.close();

                        System.out.println("Arquivo '" + nomeArquivo + "' recebido de " + remetente + " e salvo em '" + pasta + "'.");
                    } catch (IOException e) {
                        System.out.println("Erro ao salvar arquivo de " + remetente + ": " + e.getMessage());
                    }
                } else {
                    System.out.println(linha);
                }
            }
        }).start();

        while (teclado.hasNextLine()) {
            String mensagem = teclado.nextLine();
            if (mensagem.equalsIgnoreCase("sair")) {
                socket.close();
                System.exit(0);
            }

            if (mensagem.contains(":File:")) {
                enviarArquivo(mensagem, saida);
            } else {
                saida.println(mensagem);
            }
        }
    }

    private static void enviarArquivo(String comando, PrintStream saidaTexto) throws IOException {
        String[] partes = comando.split(":File:");
        if (partes.length != 2) return;

        String destinatario = partes[0];
        String caminhoArquivo = partes[1];

        File arquivo = new File(caminhoArquivo);
        if (!arquivo.exists()) {
            System.out.println("Arquivo não encontrado.");
            return;
        }

        byte[] dados = new byte[(int) arquivo.length()];
        FileInputStream fis = new FileInputStream(arquivo);
        fis.read(dados);
        fis.close();

        String base64 = Base64.getEncoder().encodeToString(dados);
    
        saidaTexto.println("ARQUIVO:" + destinatario + ":" + arquivo.getName() + ":" + base64);
        System.out.println("Arquivo '" + arquivo.getName() + "' enviado com sucesso.");
    }
}