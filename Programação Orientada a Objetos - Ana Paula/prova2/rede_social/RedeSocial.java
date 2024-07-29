import java.util.ArrayList;
import java.util.List;

public class RedeSocial {
    private String nome;
    private List<Usuario> usuarios;

    public RedeSocial(String nome) {
        this.nome = nome;
        this.usuarios = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public List<Usuario> getUsuarios() {
        return usuarios;
    }

    public void adicionarUsuario(Usuario usuario) {
        this.usuarios.add(usuario);
    }
}