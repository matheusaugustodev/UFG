public class Pesquisa {

    private static volatile int resultIndex = -1;

    public static int parallelSearch(int x, int[] A, int numThreads) throws InterruptedException {
        resultIndex = -1;

        int length = A.length;
        int chunkSize = (length + numThreads - 1) / numThreads;

        Thread[] threads = new Thread[numThreads];

        for (int i = 0; i < numThreads; i++) {
            int start = i * chunkSize;
            int end = Math.min(start + chunkSize, length);
            threads[i] = new Thread(new SearchTask(x, A, start, end));
            threads[i].start();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        return resultIndex;
    }

    static class SearchTask implements Runnable {
        private int x;
        private int[] A;
        private int start, end;

        public SearchTask(int x, int[] A, int start, int end) {
            this.x = x;
            this.A = A;
            this.start = start;
            this.end = end;
        }

        @Override
        public void run() {
            for (int i = start; i < end && resultIndex == -1; i++) {
                if (A[i] == x) {
                    resultIndex = i;
                    break;
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int[] vetor = new int[1000000];
        vetor[567890] = 42;

        int indice = parallelSearch(42, vetor, 8);

        if (indice != -1) {
            System.out.println("Valor encontrado no índice " + indice);
        } else {
            System.out.println(indice + " Valor não encontrado");
        }
    }
}