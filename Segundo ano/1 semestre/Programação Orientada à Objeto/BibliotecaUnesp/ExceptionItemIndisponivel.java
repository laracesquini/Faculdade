
package com.mycompany.bibliotecaunesp;

/**Classe que representa uma exceção.
 * Usada quando um usuário deseja emprestar um item, mas ele não está disponível.
 * @author Lara
 */
public class ExceptionItemIndisponivel extends Exception {
    private String mensagem;
    
    /**Método construtor, que atribui um valor à variável referente à mensagem que será mostrada na tela caso entre nessa exceção.
     * @param mensagem mensagem mostrada
     */
    public ExceptionItemIndisponivel(String mensagem)
    {
        this.mensagem = mensagem;
    }

    /**Método para retorno da mensagem.
     * @return a mensagem
     */
    public String getMensagem() {
        return mensagem;
    }
}
