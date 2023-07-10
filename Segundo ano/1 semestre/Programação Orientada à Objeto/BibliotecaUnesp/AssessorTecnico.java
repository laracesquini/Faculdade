package com.mycompany.bibliotecaunesp;

import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

/**Classe com as informações dos assessores técnicos que são usuários do sistema.
 * Herda da classe genérica Usuário.
 * @author Lara
 */
public class AssessorTecnico extends Usuario{
    private String secao;
    
    /**Método construtor, que instancia uma lista de empréstimos cada vez que um assessor técnico é cadastrado.
     */
    public AssessorTecnico()
    {
        itens = new ArrayList<>();
    }
    
    /**Método para atribuição de um valor à variável referente à seção do assessor técnico.
     * @param secao seção do assessor técnico
     */
    public void setSecao(String secao) {
        this.secao = secao;
    }
    
    /**Método que calcula a multa do assessor técnico, caso ele devolva algum item com atraso.
     * @param emprestimo objeto do tipo empréstimo, que contém as datas que serão comparadas.
     * @return a multa, caso tenha uma, ou 0, caso não tenha.
     */
    @Override
    public double calcularMulta(Emprestimo emprestimo)
    {
        long dias;
        
        dias = ChronoUnit.DAYS.between(emprestimo.getDataDevolucaoPrevista(), emprestimo.getDataDevolucaoReal());
       
        return (double)(dias*5)*1.15;
    }
}