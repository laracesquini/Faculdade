package com.mycompany.bibliotecaunesp;

import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

/**Classe com as informações dos alunos que são usuários do sistema.
 * Herda da classe genérica Usuário.
 * @author Lara
 */
public class Aluno extends Usuario{
    private String curso;
    private int periodo;
    
    /**Método construtor, que instancia uma lista de empréstimos cada vez que um aluno é cadastrado.
     */
    public Aluno()
    {
        itens = new ArrayList<>();
    }
    
    /**Método para atribuição de um valor à variável referente ao curso do aluno.
     * @param curso curso do aluno
     */
    public void setCurso(String curso) {
        this.curso = curso;
    }
    
    /**Método para atribuição de um valor à variável referente ao período do aluno.
     * @param periodo período do aluno
     */
    public void setPeriodo(int periodo) {
        this.periodo = periodo;
    }
    
    /**Método que calcula a multa do aluno, caso ele devolva algum item com atraso.
     * @param emprestimo objeto do tipo empréstimo, que contém as datas que serão comparadas.
     * @return a multa, caso tenha uma, ou 0, caso não tenha.
     */
    @Override
    public double calcularMulta(Emprestimo emprestimo)
    {
       long dias;
       dias = ChronoUnit.DAYS.between(emprestimo.getDataDevolucaoPrevista(), emprestimo.getDataDevolucaoReal());
       
       return (double)dias*5;
    }
}