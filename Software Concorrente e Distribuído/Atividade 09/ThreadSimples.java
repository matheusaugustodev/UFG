// Definindo a classe principal da aplicação
public class ThreadSimples {

    // Método para exibir mensagens junto ao nome da thread que está executando ela
    static void mensagem(String messagem) {
        // Obtendo o nome da thread
        String nomeThread = Thread.currentThread().getName();
        // Imprimindo o nome da thread e a mensagem
        System.out.println(nomeThread + " " + messagem);
    }

    // Classe Loop que implementa Runnable (uma tarefa a ser executada por uma thread)
    private static class Loop implements Runnable {
        
        // Método que será executado quando a thread for iniciada
        public void run() {
            // Definindo um array com mensagens que serão exibidas na thread
            String info[] = {
                "Java",
                "é uma boa linguagem.",
                "Com threads,",
                "é melhor ainda."
            };
            try {
                // Loop para percorrer cada elemento do array 'info'
                for (int i = 0; i < info.length; i++) {
                    // Fazendo a thread dormir por 4 segundos antes de imprimir a mensagem
                    Thread.sleep(4000);
                    // Chamando o método 'mensagem' para imprimir a mensagem da thread atual
                    mensagem(info[i]);
                }
            } catch (InterruptedException e) {
                // Caso a thread seja interrompida enquanto dorme, imprimi uma mensagem de erro
                mensagem("Nada feito!");
            }
        }
    }

    // Método principal que inicia a execução
    public static void main(String args[]) throws InterruptedException {
        // Definindo o valor padrão para 'paciencia' (quanto tempo a thread principal vai esperar)
        long paciencia = 1000 * 60 * 60; // 1 hora em milissegundos
        
        // Verificando se algum argumento foi passado na linha de comando
        if (args.length > 0) {
            try {
                // Tentando converter o primeiro argumento para um número inteiro
                paciencia = Long.parseLong(args[0]) * 1000;  // Convertendo para milissegundos
            } catch (NumberFormatException e) {
                // Se o argumento não for um número inteiro, imprime erro e encerra o programa
                System.err.println("Argumento deve ser um inteiro.");
                System.exit(1);
            }
        }

        // Imprime a mensagem dizendo que a thread Loop está sendo iniciada
        mensagem("Iniciando a thread Loop");

        // Salva o tempo de início da execução
        long inicio = System.currentTimeMillis();

        // Criando e iniciando a thread 't' que executa o código da classe Loop
        Thread t = new Thread(new Loop());
        t.start();

        // Imprime mensagem de espera
        mensagem("Esperando que a thread Loop termine");

        // Enquanto a thread 't' estiver viva (em execução), a thread principal espera
        while (t.isAlive()) {
            // Imprime que ainda está esperando pela conclusão da thread Loop
            mensagem("Ainda esperando...");
            // Faz uma pausa de 1 segundo antes de verificar novamente
            t.join(1000);
            
            // Se o tempo de espera ultrapassar o limite de paciência e a thread Loop ainda estiver viva
            if (((System.currentTimeMillis() - inicio) > paciencia) && t.isAlive()) {
                // Imprime que a paciência acabou
                mensagem("Cansado de esperar!");
                // Interrompe a execução da thread Loop
                t.interrupt();
                // Aguarda a thread terminar após a interrupção
                t.join();
            }
        }

        // Imprime que a execução da thread foi concluída
        mensagem("Finalmente!");
    }
}