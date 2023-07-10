package com.mycompany.bibliotecaunesp;

/**Classe abstrata Item, que representa os itens cadastrados no sistema.
 * Implementa a interface Emprestável, usando os métodos de empréstimo e devolução.
 * @author Lara
 */
public abstract class Item implements Emprestavel {
    protected String tipo;
    protected String titulo;
    protected String autor;
    protected int anoPublicacao;
    protected int quantDisponivel;
    protected int quantEmprestada;
    
    /**Método responsável por alterar a quantidade disponível e a quantidade emprestada de um item quando o mesmo é emprestado.
     * @throws ExceptionItemIndisponivel caso a quantidade disponível seja 0
     */
    @Override
    public void emprestimo() throws ExceptionItemIndisponivel
    {
        if(quantDisponivel == 0)
        {
            throw new ExceptionItemIndisponivel("Esse item não está disponível no momento.");
        }
        quantDisponivel--;
        quantEmprestada++;
    }
    
    /**Método responsável por alterar a quantidade disponível e a quantidade emprestada de um item quando o mesmo é devolvido.
     */
    @Override
    public void devolucao()
    {
        quantDisponivel++;
        quantEmprestada--;
    }
}