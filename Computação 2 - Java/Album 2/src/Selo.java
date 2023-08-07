import java.awt.*;

public class Selo implements Colecionavel {
    private float valorNominal;
    private String pais;
    private final Image imagem;
    private final int posicao;

    public Selo(int posicao, String urlDaImagem) {
        this.imagem = obterImagem(urlDaImagem);
        this.posicao = posicao;
    }

    private Image obterImagem(String url) {
        // ToDo baixaria da Internet...
        return null;
    }

    public float getValorNominal() {
        return valorNominal;
    }

    public String getPais() {
        return pais;
    }

    public Image getImagem() {
        return imagem;
    }

    public int getPosicao() {
        return posicao;
    }

}
