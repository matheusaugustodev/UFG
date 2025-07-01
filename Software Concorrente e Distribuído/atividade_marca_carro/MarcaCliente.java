import java.io.*;
import java.net.*;
import java.util.Scanner;

public class MarcaCliente {
    public static void main(String[] args) {
        final String servidor = "127.0.0.1";
        final int porta = 12345;

        try (
            Socket socket = new Socket(servidor, porta);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            Scanner scanner = new Scanner(System.in)
        ) {
            System.out.println("Conectado ao servidor!");
            System.out.println("Digite uma marca de carro (ou 'sair' para encerrar):");

            while (true) {
                System.out.print("Marca: ");
                String entrada = scanner.nextLine();
                out.println(entrada);

                String resposta = in.readLine();
                System.out.println("Servidor: " + resposta);

                if ("sair".equalsIgnoreCase(entrada)) {
                    break;
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}