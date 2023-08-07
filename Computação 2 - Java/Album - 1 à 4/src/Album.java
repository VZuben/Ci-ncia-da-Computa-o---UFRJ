import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Album {

    public static final int PERCENTUAL_MINIMO_PARA_AUTO_COMPLETAR = 90;

    public static final Image IMAGEM_PADRAO_PARA_POSICAO_VAZIA = null;

    private final Repositorio repositorio;
    private final int quantItensPorPacotinho;

    private List<Colecionavel> colecionavelColadas;  // direct addressing
    private int quantColecionavelColadas;

    // poderíamos fazer novamente direct addressing para as repetidas,
    // mas vamos usar um HashMap aqui só para treinarmos
    private Map<Integer, Integer> contRepetidasByPosicao;

    public Album(Repositorio repositorio, int quantItensPorPacotinho) {
        this.repositorio = repositorio;
        this.quantItensPorPacotinho = quantItensPorPacotinho;

        int tamanhoFisicoDaLista = getTamanho() + 1;
        this.colecionavelColadas = new ArrayList<>(tamanhoFisicoDaLista);
        // inicializa as posições com nulls, para poder acessá-las diretamente
        for (int i = 0; i < tamanhoFisicoDaLista; i++) {
            this.colecionavelColadas.add(null);
        }
        this.quantColecionavelColadas = 0;

        this.contRepetidasByPosicao = new HashMap<>();
    }

    public void receberNovoPacotinho(Pacotinho pacotinho) {
        Colecionavel[] colecionavelDoPacotinho = (Colecionavel[]) pacotinho.getFigurinhas();
        if (colecionavelDoPacotinho.length != this.quantItensPorPacotinho) {
            return;  // melhor ainda: lançaria uma checked exception
        }

        for (Colecionavel fig : pacotinho.getFigurinhas()) {
            int posicao = fig.getPosicao();
            if (possuiItemColado(posicao)) {
                int contRepetidas = this.contRepetidasByPosicao.getOrDefault(posicao, 0);
                this.contRepetidasByPosicao.put(posicao, contRepetidas + 1);

            } else {
                // item inédito
                this.colecionavelColadas.set(posicao, (Colecionavel) fig);
                this.quantColecionavelColadas++;
            }
        }
    }

    public Colecionavel getItemColado(int posicao) {
        return (Colecionavel) this.colecionavelColadas.get(posicao);
    }

    public boolean possuiItemColado(int posicao) {
        if(posicao > 0 && posicao <= getTamanho() && this.colecionavelColadas.get(posicao) != null) return true;

        return false;
    }

    public boolean possuiItemRepetido(int posicao) {
        return (this.contRepetidasByPosicao.containsKey(posicao));
    }

    public int getTamanho() {
        return this.repositorio.getTotalFigurinhas();
    }

    public int getQuantItensColados() {
        return this.quantColecionavelColadas;
    }

    public int getQuantItensFaltantes() {
        return getTamanho() - getQuantItensColados();
    }

    public void autoCompletar() {
        if(this.quantColecionavelColadas != 0) {
            for (int i = 1; i < this.colecionavelColadas.size(); i++) {
                Colecionavel colecionavel = (Colecionavel) this.repositorio.getTodasAsFigurinhas().get(i-1);
                if (!(possuiItemColado(i)) && this.colecionavelColadas.get(i) == null && colecionavel != null) {
                    this.colecionavelColadas.set(i, colecionavel);
                    this.quantColecionavelColadas++;
                }
            }
        }
    }

    private Image getImagem(int posicao) {
        return possuiItemColado(posicao)
                ? this.getItemColado(posicao).getImagem()
                : IMAGEM_PADRAO_PARA_POSICAO_VAZIA;
    }

}