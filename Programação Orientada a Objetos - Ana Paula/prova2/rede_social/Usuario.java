import java.util.ArrayList;
import java.util.List;

public class Usuario {
    private String login;
    private String senha;
    private String nome;
    private String email;
    private List<Usuario> seguidores;
    private List<Usuario> seguindo;
    private List<Publicacao> publicacoes;

    public Usuario(String login, String senha, String nome, String email) {
        this.login = login;
        this.senha = senha;
        this.nome = nome;
        this.email = email;
        this.seguidores = new ArrayList<>();
        this.seguindo = new ArrayList<>();
        this.publicacoes = new ArrayList<>();
    }

    public String getLogin() {
        return login;
    }

    public String getSenha() {
        return senha;
    }

    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    public List<Usuario> getSeguidores() {
        return seguidores;
    }

    public List<Usuario> getSeguindo() {
        return seguindo;
    }

    public List<Publicacao> getPublicacoes() {
        return publicacoes;
    }

    public void seguirUsuario(Usuario usuario) {
        this.seguindo.add(usuario);
        usuario.getSeguidores().add(this);
    }

    public void adicionarPublicacao(Publicacao publicacao) {
        this.publicacoes.add(publicacao);
    }
}