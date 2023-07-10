package com.mycompany.bibliotecaunesp;

import java.time.LocalDate;

/**Classe que contém as informações de cada empréstimo feito por um usuário.
 * @author Lara
 */
public class Emprestimo {
    private Item item;
    private LocalDate dataEmprestimo;
    private LocalDate dataDevolucaoPrevista;
    private LocalDate dataDevolucaoReal;

    /**Método para o retorno do item emprestado.
     * @return o item emprestado
     */
    public Item getItem() {
        return item;
    }

    /**Método para atribuição de um valor à variável referente ao item emprestado.
     * @param item item emprestado
     */
    public void setItem(Item item) {
        this.item = item;
    }

    /**Método para o retorno da data de empréstimo do item.
     * @return a data de empréstimo do item
     */
    public LocalDate getDataEmprestimo() {
        return dataEmprestimo;
    }

    /**Método para atribuição de um valor à variável referente à data de empréstimo do item.
     * @param dataEmprestimo data de empréstimo do item
     */
    public void setDataEmprestimo(LocalDate dataEmprestimo) {
        this.dataEmprestimo = dataEmprestimo;
    }

    /**Método para o retorno da data de devolução prevista do item.
     * @return a data de devolução prevista do item
     */
    public LocalDate getDataDevolucaoPrevista() {
        return dataDevolucaoPrevista;
    }

    /**Método para atribuição de um valor à variável referente à data de devolução prevista do item.
     * @param dataDevolucaoPrevista data de devolução prevista do item
     */
    public void setDataDevolucaoPrevista(LocalDate dataDevolucaoPrevista) {
        this.dataDevolucaoPrevista = dataDevolucaoPrevista;
    }

    /**Método para o retorno da data de devolução real do item.
     * @return a data de devolução real do item
     */
    public LocalDate getDataDevolucaoReal() {
        return dataDevolucaoReal;
    }

    /**Método para atribuição de um valor à variável referente à data de devolução real do item.
     * @param dataDevolucaoReal data de devolução real do item
     */
    public void setDataDevolucaoReal(LocalDate dataDevolucaoReal) {
        this.dataDevolucaoReal = dataDevolucaoReal;
    }
}