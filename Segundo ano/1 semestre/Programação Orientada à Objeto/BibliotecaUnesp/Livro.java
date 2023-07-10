package com.mycompany.bibliotecaunesp;

/**Classe com informações dos livros cadastrados no sistema.
 * Herda da classe genérica Item.
 * @author Lara
 */
public class Livro extends Item{
    private String editora;
    private String ISBN;

    /**Método para o retorno da editora do livro.
     * @return a editora do livro
     */
    public String getEditora() {
        return editora;
    }

    /**Método para atribuição de um valor à variável referente à editora do livro.
     * @param editora editora do livro
     */
    public void setEditora(String editora) {
        this.editora = editora;
    }

    /**Método para o retorno do ISBN do livro.
     * @return o ISBN do livro
     */
    public String getISBN() {
        return ISBN;
    }

    /**Método para atribuição de um valor à variável referente ao ISBN do livro.
     * @param ISBN ISBN do livro
     */
    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }
}