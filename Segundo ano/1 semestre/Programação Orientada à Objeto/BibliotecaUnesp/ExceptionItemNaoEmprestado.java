
package com.mycompany.bibliotecaunesp;

/**Classe que representa uma exceção.
 * Usada quando um usuário deseja devolver um item que não foi emprestado.
 * @author Lara
 */
public class ExceptionItemNaoEmprestado extends Exception{
    private String mensagem;
    
    /**Método construtor, que atribui um valor à variável referente à mensagem que será mostrada na tela caso entre nessa exceção.
     * @param mensagem mensagem mostrada
     */
    public ExceptionItemNaoEmprestado(String mensagem)
    {
        this.mensagem = mensagem;
    }
    
    /**Método para retorno da mensagem.
     * @return a mensagem
     */
    public String getMensagem()
    {
        return mensagem;
    }
}
