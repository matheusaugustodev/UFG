import java.util.Date;

public abstract class Reacao {
    private Date data;
    private Usuario usuario;

    public Reacao(Date data, Usuario usuario) {
        this.data = data;
        this.usuario = usuario;
    }

    public Date getData() {
        return data;
    }

    public Usuario getUsuario() {
        return usuario;
    }
}