import java.util.Date;

public class Curtida extends Reacao {
    private String tipo;

    public Curtida(Date data, Usuario usuario, String tipo) {
        super(data, usuario);
        this.tipo = tipo;
    }

    public String getTipo() {
        return tipo;
    }
}