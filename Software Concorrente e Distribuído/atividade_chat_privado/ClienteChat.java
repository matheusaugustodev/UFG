import java.io.*;
import java.net.*;
import java.util.*;

public class ClienteChat {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("127.0.0.1", 12345);
        System.out.println("Conectado ao servidor!");

        Scanner teclado = new Scanner(System.in);
        Scanner entrada = new Scanner(socket.getInputStream());
        PrintStream saida = new PrintStream(socket.getOutputStream());

        new Thread(() -> {
            while (entrada.hasNextLine()) {
                System.out.println(entrada.nextLine());
            }
        }).start();

        while (teclado.hasNextLine()) {
            String mensagem = teclado.nextLine();
            if (mensagem.equalsIgnoreCase("sair")) {
                socket.close();
                System.exit(0);
            }
            saida.println(mensagem);
        }
    }
}