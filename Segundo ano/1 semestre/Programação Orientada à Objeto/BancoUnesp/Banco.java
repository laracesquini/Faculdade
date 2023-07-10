
package com.mycompany.bancounesp;

import static java.lang.Boolean.FALSE;
import static java.lang.Boolean.TRUE;
import java.util.ArrayList;

/**Classe com as informações do banco e sua relação com as agências
 * @author Lara
 */
public class Banco {
    private int numero;
    private String nome;
    private String cnpj;
    private String endereco;
    private Conta contaLogada = new Conta();
    private ArrayList<Agencia> agencias = new ArrayList<>();
    
    /**Método para atribuição de um valor à variável referente ao número do banco
     * @param numero número do banco
     */
    public void setNumero(int numero) {
        this.numero = numero;
    }

    /**Método para retorno do nome do banco
     * @return o nome
     */
    public String getNome() {
        return nome;
    }

    /**Método para atribuição de um valor à variável referente ao nome do banco
     * @param nome nome do banco
     */
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    /**Método para atribuição de um valor à variável referente ao CNPJ do banco
     * @param cnpj CNPJ do banco
     */
    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }
    
    /**Método para atribuição de um valor à variável referente ao endereço do banco
     * @param endereco endereço do banco
     */
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
    /**Método que irá logar um cliente, ou seja, procurar sua conta e ter ela referenciada para poder fazer as operações 
     * @param numAgencia número da agência
     * @param numConta número da conta
     * @param senha senha da conta
     * @return TRUE se foi possível logar ou FALSE se não foi possível
     */
    public boolean logarCliente(int numAgencia, int numConta, String senha)
    {
        for(Agencia item : agencias)
        {
            if(item.getCodigo() == numAgencia)
            {
                contaLogada = item.buscarConta(numConta, senha);
                if(contaLogada != null)
                    return TRUE;
                else
                    return FALSE;
            }
        }
        return FALSE;
    }
    
    /**Método para realizar um saque na conta do cliente
     * @param valor valor a ser sacado
     * @param dia dia em que o saque foi realizado
     * @param mes mês em que o saque foi realizado
     * @param ano ano em que o saque foi realizado
     * @return TRUE caso seja possível realizar o saque ou FALSE caso não seja possível
     */
    public boolean realizarSaque(double valor, int dia, int mes, int ano)
    {
        if(contaLogada.sacar(valor))
        {
            contaLogada.cadastrarExtrato(valor, dia, mes, ano, "saque");
            return TRUE;
        }
        else
            return FALSE;
    }
    
    /**Método para realizar um depósito na conta do cliente
     * @param valor valor a ser depositado 
     * @param dia dia em que o depósito foi realizado
     * @param mes mês em que o depósito foi realizado
     * @param ano ano em que o depósito foi realizado
     */
    public void realizarDeposito(double valor, int dia, int mes, int ano)
    {
        contaLogada.depositar(valor);
        contaLogada.cadastrarExtrato(valor, dia, mes, ano, "depósito");
    }
    
    /**Método para pegar o saldo da conta do cliente
     * @return o saldo
     */
    public double saldo()
    {
        return contaLogada.getSaldo();
    }
    
    /**Método para cadastrar uma agência no banco
     * @param nome nome da agência
     * @param codigo número da agência
     * @param endereco endereço da agência
     */
    public void cadastrarAgencia(String nome, int codigo, String endereco)
    {
        Agencia item = new Agencia();
        item.setCodigo(codigo);
        item.setNome(nome);
        item.setEndereco(endereco);
        this.cadastrarAgencia(item);
    }
    
    /**Método que adiciona uma agência na lista de agências
     * @param agencia agência a ser adicionada
     */
    public void cadastrarAgencia(Agencia agencia)
    {
        agencias.add(agencia);
    }
    
    /**Método que cadastra uma conta no banco
     * @param nome nome da pessoa
     * @param dataNascimento data de nascimento da pessoa
     * @param endereco endereço da pessoa
     * @param cpf CPF da pessoa
     * @param saldo saldo da conta
     * @param numAgencia número da agência
     * @param numero número da conta
     * @param senha senha da conta
     */
    public void cadastrarConta(String nome, String dataNascimento, String endereco, String cpf, double saldo, int numAgencia, int numero, String senha )
    {
        for(Agencia item : agencias)
        {
            if(item.getCodigo() == numAgencia)
            {
                Conta contaExemplo = new Conta();
                contaExemplo.setNumero(numero);
                contaExemplo.setNome(nome);
                contaExemplo.setDataNascimento(dataNascimento);
                contaExemplo.setEndereco(endereco);
                contaExemplo.setCpf(cpf);
                contaExemplo.setSaldo(saldo);
                contaExemplo.setSenha(senha);
                item.cadastrarConta(contaExemplo);
            }
        }
    }
    
    /**Método que busca uma agência na lista de agências
     * @param codigo número da agência
     * @return a agência, caso ela seja encontrada, ou null, caso não seja encontrada
     */
    public Agencia buscarAgencia(int codigo)
    {
        for(Agencia item : agencias)
        {
            if(item.getCodigo() == codigo)
                return item;
        }
        return null;
    }
    
    /**Método para realizar uma transferência para outra conta
     * @param numAgencia número da agência da pessoa que receberá a transferência
     * @param numConta número da conta da pessoa que receberá a transferência
     * @param valor a ser tranferido
     * @param dia dia em que a transferência foi realizada
     * @param mes mês em que a transferência foi realizada
     * @param ano ano em que a transferência foi realizada
     * @return TRUE caso seja possível realizar a transferência ou FALSE caso não seja possível
     */
    public boolean transferencia(int numAgencia, int numConta, double valor, int dia, int mes, int ano)
    {

        for(Agencia item : agencias)
        {
            if(item.getCodigo() == numAgencia)
            {
                Conta conta;
                conta = item.buscarConta(numConta);
                if(conta != null)
                {
                    conta.depositar(valor);
                    conta.cadastrarExtrato(valor, dia, mes, ano, "transferência recebida");
                    contaLogada.sacar(valor);
                    contaLogada.cadastrarExtrato(valor, dia, mes, ano, "transferência");
                    return TRUE;
                }
            }
        }
        return FALSE;
    }
    
    /**Método para realizar um pix para outra conta
     * @param chaveCPF CPF da pessoa que receberá o pix
     * @param valor valor a ser passado
     * @param numAgencia número da agência da pessoa que receberá o pix
     * @param dia dia em que o pix foi realizado
     * @param mes mês em que o pix foi realizado
     * @param ano ano em que o pix foi realizado
     * @return TRUE caso seja possível realizar o pix ou FALSE caso não seja possível
     */
    public boolean pix(String chaveCPF, double valor, int numAgencia, int dia, int mes, int ano)
    {
        for(Agencia item : agencias)
        {
            if(item.getCodigo() == numAgencia)
            {
                Conta conta;
                conta = item.buscarConta(chaveCPF);
                if(conta != null)
                {
                    conta.depositar(valor);
                    conta.cadastrarExtrato(valor, dia, mes, ano, "pix recebido");
                    contaLogada.sacar(valor);
                    contaLogada.cadastrarExtrato(valor, dia, mes, ano, "pix");
                    return TRUE;
                }
            }
        }
        return FALSE;
    }
    
    /**Método para ver o extrato da conta logada
     * @param mes mes que o usuário deseja ver o extrato
     * @param ano ano que o usuário deseja ver o extrato
     */
    public void extrato(int mes, int ano)
    {
        contaLogada.verExtrato(mes, ano);
    }
    
    /**Método para deslodar a conta do cliente, ou seja, pede-se a referência a sua conta
     */
    public void deslogarConta()
    {
        contaLogada = null;
    }
}
