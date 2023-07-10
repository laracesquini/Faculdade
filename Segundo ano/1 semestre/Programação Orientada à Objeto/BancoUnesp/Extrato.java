
package com.mycompany.bancounesp;

/**Classe com as informações sobre cada transação que o cliente faz, seu extrato bancário
 * @author Lara
 */
public class Extrato {
    private double valor;
    private int dia;
    private int mes;
    private int ano;
    private String tipo;

    /**Método para retorno do valor da transação
     * @return o valor
     */
    public double getValor() {
        return valor;
    }

    /**Método para atribuição de um valor à variável referente ao valor da transação
     * @param valor valor
     */
    public void setValor(double valor) {
        this.valor = valor;
    }

    /**Método para retorno do dia em que a transção foi feita
     * @return o dia
     */
    public int getDia() {
        return dia;
    }

    /**Método para atribuição de um valor à variável referente ao dia em que a transação foi feita
     * @param dia dia
     */
    public void setDia(int dia) {
        this.dia = dia;
    }

    /**Método para retorno do mês em que a transação foi feita
     * @return o mes
     */
    public int getMes() {
        return mes;
    }

    /**Método para atribuição de um valor à variável referente ao mês em que a transação foi feita
     * @param mes mes
     */
    public void setMes(int mes) {
        this.mes = mes;
    }

    /**Método para retorno do ano em que a transação foi feita
     * @return o ano
     */
    public int getAno() {
        return ano;
    }

    /**Método para atribuição de um valor à variável referente ao ano em que a transação foi feita
     * @param ano ano
     */
    public void setAno(int ano) {
        this.ano = ano;
    }

    /**Método para retorno do tipo de transação
     * @return o tipo
     */
    public String getTipo() {
        return tipo;
    }

    /**Método para atribuição de um valor à variável referente ao tipo de transação
     * @param tipo tipo
     */
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
}
