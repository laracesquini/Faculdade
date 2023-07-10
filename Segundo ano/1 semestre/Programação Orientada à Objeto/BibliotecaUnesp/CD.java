package com.mycompany.bibliotecaunesp;

/**Classe com informações dos CDs cadastrados no sistema.
 * Herda da classe genérica Item.
 * @author Lara
 */
public class CD extends Item{
    private int volume;
    private String gravadora;

    /**Método para o retorno do volume do CD.
     * @return o volume do CD
     */
    public int getVolume() {
        return volume;
    }

    /**Método para atribuição de um valor à variável referente ao volume do CD.
     * @param volume volume do CD
     */
    public void setVolume(int volume) {
        this.volume = volume;
    }

    /**Método para o retorno da gravadora do CD.
     * @return a gravadora do CD
     */
    public String getGravadora() {
        return gravadora;
    }

    /**Método para atribuição de um valor à variável referente à gravadora do CD.
     * @param gravadora gravadora do CD.
     */
    public void setGravadora(String gravadora) {
        this.gravadora = gravadora;
    }
}