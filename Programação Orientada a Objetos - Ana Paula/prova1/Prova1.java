package prova1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Usuario {
    private String nome;
    private String email;
    private String senha;
    private List<Evento> eventos;

    public Usuario(String nome, String email, String senha) {
        this.nome = nome;
        this.email = email;
        this.senha = senha;
        this.eventos = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public List<Evento> getEventos() {
        return eventos;
    }

    public void addEvento(Evento evento) {
        this.eventos.add(evento);
    }

    @Override
    public String toString() {
       return "\n\nUsuário: {Nome: " + nome + ", Email: " + email + ", Senha: " + senha + " Eventos: " + eventos + "}\n\n";
    }
}

class Evento {
    private String descricao;
    private String dataInicio;
    private String dataFim;
    private List<Palestra> palestras;

    public Evento(String descricao) {
        this.descricao = descricao;
        this.palestras = new ArrayList<>();
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(String dataInicio) {
        this.dataInicio = dataInicio;
    }

    public String getDataFim() {
        return dataFim;
    }

    public void setDataFim(String dataFim) {
        this.dataFim = dataFim;
    }

    public List<Palestra> getPalestras() {
        return palestras;
    }

    public void adicionarPalestra(Palestra palestra) {
        this.palestras.add(palestra);
    }

    @Override
    public String toString() {
        return "\nEvento: {Descrição: " + descricao + ", Data de Início: " + dataInicio + ", Data de Fim: " + dataFim + ", Palestras: " + palestras + "}\n";
    }
}

class Palestra {
    private String nome;
    private String data;
    private String horaInicial;
    private String horaFinal;
    private String comentarios;

    public Palestra(String nome, String data) {
        this.nome = nome;
        this.data = data;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public String getHoraInicial() {
        return horaInicial;
    }

    public void setHoraInicial(String horaInicial) {
        this.horaInicial = horaInicial;
    }

    public String getHoraFinal() {
        return horaFinal;
    }

    public void setHoraFinal(String horaFinal) {
        this.horaFinal = horaFinal;
    }

    public String getComentarios() {
        return comentarios;
    }

    public void setComentarios(String comentarios) {
        this.comentarios = comentarios;
    }

    @Override
    public String toString() {
        return "\nPalestra: {Nome: " + nome + ", Data: " + data + ", Hora Inicial: " + horaInicial + ", Hora Final: " + horaFinal + ", Comentários: " + comentarios + "}\n";
    }
}

class EventoPatrocinado extends Evento {
    private String nomePatrocinador;
    private double valor;

    public EventoPatrocinado(String descricao, String nomePatrocinador, double valor) {
        super(descricao);
        this.nomePatrocinador = nomePatrocinador;
        this.valor = valor;
    }

    public String getNomePatrocinador() {
        return nomePatrocinador;
    }

    public void setNomePatrocinador(String nomePatrocinador) {
        this.nomePatrocinador = nomePatrocinador;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    @Override
    public String toString() {
        return "\n\nEvento Patrocinado: {Descrição: " + getDescricao() + ", Data de Início: " + getDataInicio() + ", Data de Fim: " + getDataFim() + ", Nome do Patrocinador: " + nomePatrocinador + ", Valor: " + valor + "}\n\n";
    }
}

public class Prova1 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o nome da palestra 1: ");
        String nomePalestra1 = scanner.nextLine();
        System.out.println("Digite a data da palestra 1: ");
        String dataPalestra1 = scanner.nextLine();
        System.out.println("Digite a hora inicial da palestra 1: ");
        String horaInicialPalestra1 = scanner.nextLine();
        System.out.println("Digite a hora final da palestra 1: ");
        String horaFinalPalestra1 = scanner.nextLine();
        System.out.println("Digite os comentários da palestra 1: ");
        String comentariosPalestra1 = scanner.nextLine();

        System.out.println("Digite o nome da palestra 2: ");
        String nomePalestra2 = scanner.nextLine();
        System.out.println("Digite a data da palestra 2: ");
        String dataPalestra2 = scanner.nextLine();
        System.out.println("Digite a hora inicial da palestra 2: ");
        String horaInicialPalestra2 = scanner.nextLine();
        System.out.println("Digite a hora final da palestra 2: ");
        String horaFinalPalestra2 = scanner.nextLine();
        System.out.println("Digite os comentários da palestra 2: ");
        String comentariosPalestra2 = scanner.nextLine();

        System.out.println("Digite o nome da palestra 3: ");
        String nomePalestra3 = scanner.nextLine();
        System.out.println("Digite a data da palestra 3: ");
        String dataPalestra3 = scanner.nextLine();
        System.out.println("Digite a hora inicial da palestra 3: ");
        String horaInicialPalestra3 = scanner.nextLine();
        System.out.println("Digite a hora final da palestra 3: ");
        String horaFinalPalestra3 = scanner.nextLine();

        System.out.println("Digite o nome da palestra 4: ");
        String nomePalestra4 = scanner.nextLine();
        System.out.println("Digite a data da palestra 4: ");
        String dataPalestra4 = scanner.nextLine();
        System.out.println("Digite a hora inicial da palestra 4: ");
        String horaInicialPalestra4 = scanner.nextLine();
        System.out.println("Digite a hora final da palestra 4: ");
        String horaFinalPalestra4 = scanner.nextLine();

        System.out.println("Digite o nome da palestra 5: ");
        String nomePalestra5 = scanner.nextLine();
        System.out.println("Digite a data da palestra 5: ");
        String dataPalestra5 = scanner.nextLine();
        System.out.println("Digite a hora inicial da palestra 5: ");
        String horaInicialPalestra5 = scanner.nextLine();
        System.out.println("Digite a hora final da palestra 5: ");
        String horaFinalPalestra5 = scanner.nextLine();

        System.out.println("Digite o nome da palestra 6: ");
        String nomePalestra6 = scanner.nextLine();
        System.out.println("Digite a data da palestra 6: ");
        String dataPalestra6 = scanner.nextLine();
        System.out.println("Digite a hora inicial da palestra 6: ");
        String horaInicialPalestra6 = scanner.nextLine();
        System.out.println("Digite a hora final da palestra 6: ");
        String horaFinalPalestra6 = scanner.nextLine();

        Palestra palestra1 = new Palestra(nomePalestra1, dataPalestra1);
        Palestra palestra2 = new Palestra(nomePalestra2, dataPalestra2);
        Palestra palestra3 = new Palestra(nomePalestra3, dataPalestra3);
        Palestra palestra4 = new Palestra(nomePalestra4, dataPalestra4);
        Palestra palestra5 = new Palestra(nomePalestra5, dataPalestra5);
        Palestra palestra6 = new Palestra(nomePalestra6, dataPalestra6);

        palestra1.setHoraInicial(horaInicialPalestra1);
        palestra1.setHoraFinal(horaFinalPalestra1);
        palestra1.setComentarios(comentariosPalestra1);

        palestra2.setHoraInicial(horaInicialPalestra2);
        palestra2.setHoraFinal(horaFinalPalestra2);
        palestra2.setComentarios(comentariosPalestra2);

        palestra3.setHoraInicial(horaInicialPalestra3);
        palestra3.setHoraFinal(horaFinalPalestra3);
        palestra3.setComentarios(comentariosPalestra1);

        palestra4.setHoraInicial(horaInicialPalestra4);
        palestra4.setHoraFinal(horaFinalPalestra4);
        palestra4.setComentarios(comentariosPalestra1);

        palestra5.setHoraInicial(horaInicialPalestra5);
        palestra5.setHoraFinal(horaFinalPalestra5);
        palestra5.setComentarios(comentariosPalestra1);

        palestra6.setHoraInicial(horaInicialPalestra6);
        palestra6.setHoraFinal(horaFinalPalestra6);
        palestra6.setComentarios(comentariosPalestra1);


        System.out.println("Digite a descrição do evento 1: ");
        String descricaoEvento1 = scanner.nextLine();
        System.out.println("Digite a data de início do evento 1: ");
        String dataInicioEvento1 = scanner.nextLine();
        System.out.println("Digite a data de fim do evento 1: ");
        String dataFimEvento1 = scanner.nextLine();

        System.out.println("Digite a descrição do evento 2: ");
        String descricaoEvento2 = scanner.nextLine();
        System.out.println("Digite a data de início do evento 2: ");
        String dataInicioEvento2 = scanner.nextLine();
        System.out.println("Digite a data de fim do evento 2: ");
        String dataFimEvento2 = scanner.nextLine();

        System.out.println("Digite a descrição do evento 3: ");
        String descricaoEvento3 = scanner.nextLine();
        System.out.println("Digite a data de início do evento 3: ");
        String dataInicioEvento3 = scanner.nextLine();
        System.out.println("Digite a data de fim do evento 3: ");
        String dataFimEvento3 = scanner.nextLine();

        System.out.println("Digite a descrição do evento 4: ");
        String descricaoEvento4 = scanner.nextLine();
        System.out.println("Digite a data de início do evento 4: ");
        String dataInicioEvento4 = scanner.nextLine();
        System.out.println("Digite a data de fim do evento 4: ");
        String dataFimEvento4 = scanner.nextLine();

        Evento evento1 = new Evento(descricaoEvento1);
        evento1.setDataInicio(dataInicioEvento1);
        evento1.setDataFim(dataFimEvento1);

        Evento evento2 = new Evento(descricaoEvento2);
        evento2.setDataInicio(dataInicioEvento2);
        evento2.setDataFim(dataFimEvento2);

        Evento evento3 = new Evento(descricaoEvento3);
        evento3.setDataInicio(dataInicioEvento3);
        evento3.setDataFim(dataFimEvento3);

        Evento evento4 = new Evento(descricaoEvento4);
        evento4.setDataInicio(dataInicioEvento4);
        evento4.setDataFim(dataFimEvento4);

        evento1.adicionarPalestra(palestra1);
        evento1.adicionarPalestra(palestra2);
        evento1.adicionarPalestra(palestra3);

        evento2.adicionarPalestra(palestra4);
        evento2.adicionarPalestra(palestra5);
        evento2.adicionarPalestra(palestra6);

        evento3.adicionarPalestra(palestra1);
        evento3.adicionarPalestra(palestra2);
        evento3.adicionarPalestra(palestra3);

        evento4.adicionarPalestra(palestra4);
        evento4.adicionarPalestra(palestra5);
        evento4.adicionarPalestra(palestra6);

        System.out.println("Digite o nome do usuário 1: ");
        String nomeUsuario1 = scanner.nextLine();
        System.out.println("Digite o email do usuário 1: ");
        String emailUsuario1 = scanner.nextLine();
        System.out.println("Digite a senha do usuário 1: ");
        String senhaUsuario1 = scanner.nextLine();

        System.out.println("Digite o nome do usuário 2: ");
        String nomeUsuario2 = scanner.nextLine();
        System.out.println("Digite o email do usuário 2: ");
        String emailUsuario2 = scanner.nextLine();
        System.out.println("Digite a senha do usuário 2: ");
        String senhaUsuario2 = scanner.nextLine();

        Usuario usuario1 = new Usuario(nomeUsuario1, emailUsuario1, senhaUsuario1);
        Usuario usuario2 = new Usuario(nomeUsuario2, emailUsuario2, senhaUsuario2);

        usuario1.addEvento(evento1);
        usuario1.addEvento(evento2);
        usuario1.addEvento(evento3);

        usuario2.addEvento(evento1);
        usuario2.addEvento(evento2);
        usuario2.addEvento(evento3);

        System.out.println(usuario1);
        System.out.println(usuario2);

        scanner.close();
    }
}