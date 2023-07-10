package com.mycompany.bibliotecaunesp;

import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

/**Classe com as informações dos professores que são usuários do sistema.
 * Herda da classe genérica Usuário.
 * @author Lara
 */
public class Professor extends Usuario{
    private String departamento;
    private String titulacao;
    
    /**Método construtor, que instancia uma lista de empréstimos cada vez que um professor é cadastrado.
     */
    public Professor()
    {
        itens = new ArrayList<>();
    }
    
    /**Método para atribuição de um valor à variável referente ao departamento do professor.
     * @param departamento departamento do professor
     */
    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }
    
    /**Método para atribuição de um valor à variável referente a titulação do professor.
     * @param titulacao titulação do professor
     */
    public void setTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }
    
    /**Método que calcula a multa do professor, caso ele devolva algum item com atraso.
     * @param emprestimo objeto do tipo empréstimo, que contém as datas que serão comparadas.
     * @return a multa, caso tenha uma, ou 0, caso não tenha.
     */
    @Override
    public double calcularMulta(Emprestimo emprestimo)
    {
        long dias;
        
        dias = ChronoUnit.DAYS.between(emprestimo.getDataDevolucaoPrevista(), emprestimo.getDataDevolucaoReal());
        
        return (double)(dias*5)*1.25;
    }
}