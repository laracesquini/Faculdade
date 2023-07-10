package com.mycompany.bibliotecaunesp;

/**Classe com informações das revistas cadastradas no sistema.
 * Herda da classe genérica Item.
 * @author Lara
 */
public class Revista extends Item{
    private int volume;
    private int numero;

    /**Método para o retorno do volume da revista.
     * @return o volume da revista
     */
    public int getVolume() {
        return volume;
    }

    /**Método para atribuição de um valor à variável referente ao volume da revista.
     * @param volume volume da revista
     */
    public void setVolume(int volume) {
        this.volume = volume;
    }

    /**Método para o retorno do número da revista.
     * @return o número da revista
     */
    public int getNumero() {
        return numero;
    }

    /**Método para atribuição de um valor à variável referente ao número da revista.
     * @param numero número da revista
     */
    public void setNumero(int numero) {
        this.numero = numero;
    }
}