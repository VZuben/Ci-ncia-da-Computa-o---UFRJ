import java.awt.*;

public class Selo implements Colecionavel {
    private float valorMonetario;
    private String urlDaImagem;
    private int posicao;

    public Selo(int posicao, String urlDaImagem, float valorMonetario) {
        this.valorMonetario = valorMonetario;
        this.urlDaImagem = urlDaImagem;
        this.posicao = posicao;
    }


    public Image getImagem() {
        return null;
    }


    public int getPosicao() {
        return posicao;
    }
}
