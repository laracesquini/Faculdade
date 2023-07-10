
package com.mycompany.bancounesp;

import java.util.*;

/**Classe com as informações das agências que fazem parte do banco e sua relação com as contas do banco
 * @author Lara
 */
public class Agencia {
    private int codigo;
    private String nome;
    private String endereco;
    private ArrayList<Conta> contas = new ArrayList<>();

    /**Método para retorno do código ou número de identificação da agência
     * @return o codigo
     */
    public int getCodigo() {
        return codigo;
    }
    
    /**Método para atribuição de um valor à variável referente ao código da agência
     * @param codigo número da agência
     */
    public void setCodigo(int codigo)
    {
        this.codigo = codigo;
    }
    
    /**Método para atribuição de um valor à variável referente ao nome da agência
     * @param nome nome da agência
     */
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    /**Método para atribuição de um valor à variável referente ao endereço da agência
     * @param endereco endereço da agência
     */
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
    /**Método que recebe um objeto do tipo conta e adiciona ele a lista de contas
     * @param conta conta a ser adicionada
     */
    public void cadastrarConta(Conta conta)
    {
        contas.add(conta);
    }
    
    /**Método que busca determinada conta na lista de contas de acordo com o número da conta
     * @param numConta número da conta
     * @param senha senha
     * @return a conta, caso ela seja encontrada, ou null, caso a conta não seja encontrada ou a senha estiver incorreta
     */
    public Conta buscarConta(int numConta, String senha)
    {
        for(Conta item : contas)
        {
            if(item.getNumero() == numConta)
            {
                if(item.validarSenha(senha))
                    return item;
                else
                {
                    System.out.println("Senha inválida!");
                    return null;
                }
            }
        }
        System.out.println("Conta não encontrada!");
        return null;
    }
    
    /**Método que busca determinada conta na lista de contas de acordo com o número da conta sem que seja necessária a senha
     * @param numConta número da conta
     * @return a conta, caso ela seja encontrada, ou null, caso a conta não seja encontrada 
     */
    public Conta buscarConta(int numConta)
    {
        for(Conta item : contas)
        {
            if(item.getNumero() == numConta)
                return item;
        }
        return null;
    }
    
    /**Método que busca determinada conta na lista de contas de acordo com o CPF da pessoa que é dona da conta
     * @param cpf CPF da pessoa dona da conta
     * @return a conta, caso ela seja encontrada, ou null, caso a conta não seja encontrada 
     */
    public Conta buscarConta(String cpf)
    {
        for(Conta item : contas)
        {
            if(item.getCpf().equals(cpf))
                return item;
        }
        return null;
    }
}
