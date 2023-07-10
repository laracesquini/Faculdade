
package com.mycompany.bancounesp;

import static java.lang.Boolean.FALSE;
import static java.lang.Boolean.TRUE;
import java.util.ArrayList;

/**Classe com informações das contas dos clientes do banco
 *@author Lara
 */
public class Conta {
    private int numero;
    private double saldo;
    private String nome;
    private String endereco;
    private String cpf;
    private String dataNascimento;
    private String senha;
    private ArrayList<Extrato> extratos = new ArrayList<>();
    
    /**Método para retorno do número da conta
     * @return o numero
     */
    public int getNumero() {
        return numero;
    }
    
    /**Método para atribuição de um valor à variável referente ao número da conta
     * @param numero número da conta 
     */
    public void setNumero(int numero)
    {
        this.numero = numero;
    }

    /**Método para retorno do saldo da conta
     * @return o saldo
     */
    public double getSaldo() {
        return saldo;
    }

    /**Método para atribuição de um valor à variável referente ao saldo da conta
     * @param saldo valor do saldo
     */
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    
    /**Método para atribuição de um valor à variável referente ao nome da pessoa dona da conta
     * @param nome nome da pessoa
     */
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    /**Método para atribuição de um valor à variável referente ao endereço da pessoa dona da conta
     * @param endereco endereco da pessoa
     */
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    /**Método para retorno do CPF da pessoa dona da conta
     * @return o cpf
     */
    public String getCpf() {
        return cpf;
    }

    /**Método para atribuição de um valor à variável referente ao CPF da pessoa dona da conta
     * @param cpf CPF da pessoa
     */
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    
    /**Método para atribuição de um valor à variável referente a data de nascimento da pessoa dona da conta
     * @param dataNascimento data de nascimento da pessoa
     */
    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }
    
    /**Método para atribuição de um valor à variável referente a senha da conta
     * @param senha senha da conta
     */
    public void setSenha(String senha) {
        this.senha = senha;
    }
    
    /**Método que irá depositar um valor na conta da pessoa, incrementando seu saldo
     * @param valor valor a ser depositado
     */
    public void depositar(double valor)
    {
        saldo += valor;
    }
    
    /**Método que irá sacar um valor da conta da pessoa, decrementando seu saldo
     * @param valor a ser sacado
     * @return TRUE caso o saque possa ser realizado ou FALSE caso o saldo seja insuficiente
     */
    public boolean sacar(double valor)
    {
        if(saldo < valor)
            return FALSE;
        else
        {
            saldo -= valor;
            return TRUE;
        }
    }
    
    /**Método que irá verificar se a senha adicionada pelo usuário está correta
     * @param senhaComparar senha que será comparada
     * @return TRUE case a senha esteja certa e FALSE caso esteja errada
     */
    public boolean validarSenha(String senhaComparar)
    {
        if(senhaComparar.equals(senha))
            return TRUE;
        else
            return FALSE;
    }
    
    /**Método que troca a senha do usuário por uma nova senha
     * @param senhaAtual senha atual
     * @param senhaNova senha nova
     */
    public void setSenha(String senhaAtual, String senhaNova)
    {
        if(senhaAtual.equals(senha))
            senha = senhaNova;
        else
            System.out.println("Senha inválida!");
    }
    
    /**Método para cadastrar uma transação na conta
     * @param valor valor transferido ou recebido
     * @param dia dia em que a transação foi feita
     * @param mes mes em que a transação foi feita
     * @param ano ano em que a transação foi feita
     * @param tipo tipo da transação
     */
    public void cadastrarExtrato(double valor, int dia, int mes, int ano, String tipo)
    {
        Extrato extrato = new Extrato();
        extrato.setValor(valor);
        extrato.setDia(dia);
        extrato.setMes(mes);
        extrato.setAno(ano);
        extrato.setTipo(tipo);
        this.cadastrarExtrato(extrato);
    }

    /**Método para ver o extrato do banco, mostrar todas as suas informações para o cliente
     * @param mes mes em que o cliente gostaria de ver o extrato
     * @param ano ano em que o cliente gostaria de ver o extrato
     */
    public void verExtrato(int mes, int ano)
    {
        int stt = 0;
        System.out.println("Aqui está seu extrato do mês " + mes);
        for(Extrato item : extratos)
        {
            if(item.getMes() == mes && item.getAno() == ano)
            {
                System.out.println("Data: " + item.getDia() + "/" + item.getMes() + "/" + item.getAno());
                System.out.println("Tipo: " + item.getTipo());
                System.out.println("Valor: " + item.getValor());
                stt = 1;
            }
        }
        if(stt == 0)
            System.out.println("Nenhuma operação foi realizada nesse mês!");
    }
    
    /**Método para adicionar o extrato na lista de extratos
     * @param extrato extrato a ser adicionado 
     */
    public void cadastrarExtrato(Extrato extrato)
    {
        extratos.add(extrato);
    }
}
