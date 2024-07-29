import static org.junit.Assert.*;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

class Main {

    public static class Pessoa {
        private String nome;
        private double salario;
        private int numeroDependentes;
        private int idade;

        public Pessoa(String nome, double salario, int numeroDependentes, int idade) {
            this.nome = nome;
            this.salario = salario;
            this.numeroDependentes = numeroDependentes;
            this.idade = idade;
        }

        public double calculaImposto() {
            if (idade >= 65) {
                return 0;
            }

            double imposto = 0;
            if (salario <= 1787.77) {
                imposto = 0;
            } else if (salario <= 2679.29) {
                imposto = salario * 0.075 - 134.08;
            } else if (salario <= 3572.43) {
                imposto = salario * 0.15 - 335.03;
            } else if (salario <= 4463.81) {
                imposto = salario * 0.225 - 602.96;
            } else {
                imposto = salario * 0.275 - 826.15;
            }

            imposto -= numeroDependentes * 179.71;

            return Math.max(imposto, 0); // Garantir que o imposto não seja negativo
        }
    }

    public static class PessoaTest {

        @BeforeClass
        public static void inicializaClass() {
            System.out.println("Iniciou série de teste");
        }

        @AfterClass
        public static void finalizaClass() {
            System.out.println("Finalizou série de teste");
        }

        @Before
        public void setUp() throws Exception {
            // Código de configuração antes de cada teste, se necessário
        }

        @After
        public void tearDown() throws Exception {
            // Código de limpeza após cada teste, se necessário
        }

        @Test
        public void testFaixa1() {
            Pessoa p = new Pessoa("joão", 1500.00, 0, 20);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("maria", 1500.00, 1, 50);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste 1 - primeira faixa");
        }

        @Test
        public void testFaixa2() {
            Pessoa p = new Pessoa("joão", 2000.00, 0, 60);
            assertEquals(15.91, p.calculaImposto(), 0.1);

            p = new Pessoa("joão", 2000.00, 2, 50);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste 2 - segunda faixa");
        }

        @Test
        public void testFaixa3() {
            Pessoa p = new Pessoa("paulo", 3500.00, 0, 20);
            assertEquals(189.97, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 3500.00, 1, 20);
            assertEquals(10.26, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 3500.00, 2, 40);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste 3 - terceira faixa");
        }

        @Test
        public void testFaixa4() {
            Pessoa p = new Pessoa("paulo", 4400.00, 0, 40);
            assertEquals(387.04, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 4400.00, 1, 30);
            assertEquals(207.33, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 4400.00, 2, 40);
            assertEquals(27.62, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 4400.00, 3, 20);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste 4 - quarta faixa");
        }

        @Test
        public void testFaixa5() {
            Pessoa p = new Pessoa("jose", 7000.00, 0, 50);
            assertEquals(1098.85, p.calculaImposto(), 0.1);

            p = new Pessoa("jose", 7000.00, 2, 30);
            assertEquals(739.43, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 7000.00, 6, 40);
            assertEquals(20.59, p.calculaImposto(), 0.1);

            p = new Pessoa("paulo", 7000.00, 7, 20);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste 5 - quinta faixa");
        }

        @Test
        public void testFaixaIdade65Dependentes0() {
            Pessoa p = new Pessoa("ana", 1500.00, 0, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 2000.00, 0, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 3500.00, 0, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 4400.00, 0, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 7000.00, 0, 66);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste - faixa de idade 65, dependentes 0");
        }

        @Test
        public void testFaixaIdade65Dependentes2() {
            Pessoa p = new Pessoa("ana", 1500.00, 2, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 2000.00, 2, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 3500.00, 2, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 4400.00, 2, 66);
            assertEquals(0, p.calculaImposto(), 0);

            p = new Pessoa("ana", 7000.00, 2, 66);
            assertEquals(0, p.calculaImposto(), 0);

            System.out.println("Passou Teste - faixa de idade 65, dependentes 2");
        }
    }

    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(PessoaTest.class);

        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }

        System.out.println(result.wasSuccessful());
    }
}