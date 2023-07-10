
package com.mycompany.bibliotecaunesp;

/**Interface que declara os métodos usados no empréstimo e devolução de itens.
 * @author Lara
 */
public interface Emprestavel {
    
    public void emprestimo() throws ExceptionItemIndisponivel;
    public void devolucao();
}
