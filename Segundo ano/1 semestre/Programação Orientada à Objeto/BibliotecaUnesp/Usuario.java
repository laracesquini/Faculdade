package com.mycompany.bibliotecaunesp;

import java.util.ArrayList;

/**Classe abstrata Usuário, que representa os usuários cadastrados no sistema.
 * @author Lara
 */
public abstract class Usuario {
    protected String tipo;
    protected String nome;
    protected String matricula;
    protected String senha;
    protected ArrayList<Emprestimo>itens;
    
    /**Método abstrato, que será implementado nas classes que herdarem de Usuário.
     * É responsável pelo cálculo da multa de cada usuário.
     * @param emprestimo um objeto do tipo empréstimo
     * @return a multa a ser paga
     */
    abstract double calcularMulta(Emprestimo emprestimo);
}