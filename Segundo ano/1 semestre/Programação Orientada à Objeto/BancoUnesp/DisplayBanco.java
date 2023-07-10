
package com.mycompany.bancounesp;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**Classe que realizará as interações com o usuário, pedindo informações a ele, para que ele possa realizar operações dentro da sua conta no banco
 * @author Lara
 */
public class DisplayBanco {
    private Banco meuBanco;
    
    /**Método construtor que cria o banco, as agências e as contas a partir de um banco de dados
     * @param banco caminho para o arquivo com as informações do banco
     * @param agencias caminho para o arquivo com as informações das agências
     * @param contas caminho para o arquivo com as informações das contas
     */
    public DisplayBanco(String banco, String agencias, String contas)
    {
        meuBanco = new Banco();
        File arquivo1 = new File(banco);
        File arquivo2 = new File(agencias);
        File arquivo3 = new File(contas);
        Scanner scanner = null;
     
        try
        {
            scanner = new Scanner(arquivo1);
        }
        catch(FileNotFoundException ex)
        {
            Logger.getLogger(BancoUnesp.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        while(scanner.hasNextLine())
        {
            String linha = scanner.nextLine();
            
            String[] campos = linha.split("#");
            
            meuBanco.setNome(campos[0]);
            meuBanco.setNumero(Integer.valueOf(campos[1]));
            meuBanco.setCnpj(campos[2]);
            meuBanco.setEndereco(campos[3]);
        }
        
        try
        {
            scanner = new Scanner(arquivo2);
        }
        catch(FileNotFoundException ex1)
        {
            Logger.getLogger(BancoUnesp.class.getName()).log(Level.SEVERE, null, ex1);
        }
        
        while(scanner.hasNextLine())
        {
            String linha = scanner.nextLine();
            
            String[] campos = linha.split("#");
            
            meuBanco.cadastrarAgencia(campos[0], Integer.parseInt(campos[1]), campos[2]);
        }
        
        try
        {
            scanner = new Scanner(arquivo3);
        }
        catch(FileNotFoundException ex)
        {
            Logger.getLogger(BancoUnesp.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        while(scanner.hasNextLine())
        {
            String linha = scanner.nextLine();
            
            String[] campos = linha.split("#");
            
            meuBanco.cadastrarConta(campos[0], campos[1], campos[2], campos[3], Double.parseDouble(campos[4]), Integer.parseInt(campos[5]), Integer.parseInt(campos[6]), campos[7]);
        }
     }
    
    /**Método responsável por logar a conta no banco. 
     * Ele pede ao usuário as informações necessárias, como número da agência, número da conta e senha.
     * Se as informações estiverem corretas, ele encaminha o usuário para a tela de operação, caso contrário, ele mostra um aviso na tela e pede as informações novamente
     */
    public void login()
    {
        int numAgencia;
        int numConta;
        String senha;
        boolean verifica;
        Scanner scanner = new Scanner(System.in);
        Scanner password = new Scanner(System.in);
        
        System.out.println("Olá, seja bem-vindo ao " + meuBanco.getNome() + "!");
        System.out.println("Adicione suas informações para fazer login na sua conta.");
        do{
            System.out.println("Número da agência: ");
            numAgencia = scanner.nextInt();
            System.out.println("Número da conta: ");
            numConta = scanner.nextInt();
            System.out.println("Senha: ");
            senha = password.nextLine();
            verifica = meuBanco.logarCliente(numAgencia, numConta, senha);
            if(!verifica)
            {
                System.out.println("Erro ao logar conta.");
                System.out.println("Favor inserir as informações novamente");
            }
            else
            {
                System.out.println("Conta logada!");
                telaUsuario();
            }
        }while(!verifica);
    }
    
    /**Método que mostra as operações disponíveis e pede para o usuário escolher uma opção.
     * Chama outros métodos de acordo com a opção escolhida
     */
    private void telaUsuario()
    {
        int op;
        Scanner scanner = new Scanner(System.in);
        
        do{
            do{
                System.out.println("Escolha uma opção: ");
                System.out.println("[1]Consultar saldo.");
                System.out.println("[2]Depósito.");
                System.out.println("[3]Saque.");
                System.out.println("[4]Transferência.");
                System.out.println("[5]Pix.");
                System.out.println("[6]Ver extrato.");
                System.out.println("[7]Sair.");
                op = scanner.nextInt();
                if(op < 1 || op > 7)
                    System.out.println("Opção inválida!");
             }while(op < 1 || op > 7);
            
            switch (op) {
                case 1:
                    operacaoSaldo();
                    break;
                case 2:
                    operacaoDeposito();
                    break;
                case 3:
                    operacaoSaque();
                    break;
                case 4:
                    operacaoTransferencia();
                    break;
                case 5:
                    operacaoPix();
                    break;
                case 6:
                    operacaoExtrato();
                    break;
                default:
                    operacaoSair();
                    break;
            }
        }while(op!=7);
    }
    
    /**Método que permite que o usuário visualize o seu saldo atual.
     * Mostra seu saldo atual na tela
     */
    private void operacaoSaldo()
    {
        double saldo;
        saldo = meuBanco.saldo();
        System.out.println("Seu saldo é: " + saldo);
    }
    
    /**Método que permite que o usuário deposite um valor em sua conta.
     * Pede informações como o valor e a data em seguida realiza o depósito
     */
    private void operacaoDeposito()
    {
        int dia, mes, ano;
        double valor;
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Digite o valor que gostaria de depositar: ");
        valor = scanner.nextDouble();
        System.out.println("Adicione a data de hoje: ");
        System.out.println("Dia: ");
        dia = scanner.nextInt();
        System.out.println("Mês: ");
        mes = scanner.nextInt();
        System.out.println("Ano: ");
        ano = scanner.nextInt();
        meuBanco.realizarDeposito(valor, dia, mes, ano);
        System.out.println("Depósito realizado!");
    }
    
    /**Método que permite que o usuário saque um valor de sua conta.
     * Pede informações como o valor e a data em seguida realiza o saque
     */
    private void operacaoSaque()
    {
        boolean verifica;
        double valor;
        int dia, mes, ano;
        Scanner scanner = new Scanner(System.in);
        
        do{
            System.out.println("Digite o valor que gostaria de sacar: ");
            valor = scanner.nextDouble();
            System.out.println("Adicione a data de hoje: ");
            System.out.println("Dia: ");
            dia = scanner.nextInt();
            System.out.println("Mês: ");
            mes = scanner.nextInt();
            System.out.println("Ano: ");
            ano = scanner.nextInt();
            verifica = meuBanco.realizarSaque(valor, dia, mes, ano);
            if(!verifica)
                System.out.println("Não foi possível sacar esse valor. Tente novamente.");
            else
                System.out.println("Saque realizado!");
        }while(!verifica);
    }
    
    /**Método que permite que o usuário realize uma transferência para outra conta.
     * Pede informações como o número da conta e da agência para a qual a transferência será realizada, assim como a data da transferência e em seguida realiza a transferência
     */
    private void operacaoTransferencia()
    {
        boolean verifica;
        int numAgencia;
        int numConta;
        int dia, mes, ano;
        double valor;
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Digite as informações da conta para a qual será feita a transferência: ");
        do{
            System.out.println("Número da agência: ");
            numAgencia = scanner.nextInt();
            System.out.println("Número da conta: ");
            numConta = scanner.nextInt();
            System.out.println("Valor: ");
            valor = scanner.nextDouble();
            System.out.println("Adicione a data de hoje: ");
            System.out.println("Dia: ");
            dia = scanner.nextInt();
            System.out.println("Mês: ");
            mes = scanner.nextInt();
            System.out.println("Ano: ");
            ano = scanner.nextInt();
            verifica = meuBanco.transferencia(numAgencia, numConta, valor, dia, mes, ano);
            if(!verifica)
                System.out.println("Não foi possível realizar a transferência. Tente novamente");
            else
                System.out.println("Transferência realizada!");
        }while(!verifica);
    }
    
    /**Método que permite que o usuário realize um pix para outra conta.
     * Pede informações como o número da agência e o CPF da pessoa para a qual o pix será realizado, assim como a data e em seguida realiza a transferência por pix
     */
    private void operacaoPix()
    {
        boolean verifica;
        int numAgencia;
        int dia, mes, ano;
        double valor;
        String cpf;
        Scanner scanner = new Scanner(System.in);
        Scanner scanner2 = new Scanner(System.in);
        
        System.out.println("Digite as informações da conta para a qual será feita a transferência: ");
        do{
            System.out.println("Número da agência: ");
            numAgencia = scanner.nextInt();
            System.out.println("Chave(CPF): ");
            cpf = scanner2.nextLine();
            System.out.println("Valor: ");
            valor = scanner.nextDouble();
            System.out.println("Adicione a data de hoje: ");
            System.out.println("Dia: ");
            dia = scanner.nextInt();
            System.out.println("Mês: ");
            mes = scanner.nextInt();
            System.out.println("Ano: ");
            ano = scanner.nextInt();
            verifica = meuBanco.pix(cpf, valor, numAgencia, dia, mes, ano);
            if(!verifica)
                System.out.println("Não foi possível realizar a transferência por pix. Tente novamente");
            else
                System.out.println("Transferência por pix realizada!");
        }while(!verifica);
        
    }
    
    /**Método que permite que o usuário visualize seu extrato.
     * Pede informações como o mês em que o usuário gostaria de visualizar o extrato e o ano.
     */
    private void operacaoExtrato()
    {
        int mes, ano;
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Digite o mês que você gostaria de ver o extrato: ");
        mes = scanner.nextInt();
        System.out.println("Ano: ");
        ano = scanner.nextInt();
        meuBanco.extrato(mes, ano);
    }
    
    /**Método para deslogar a conta do usuário
     */
    private void operacaoSair()
    {
        meuBanco.deslogarConta();
        login();
    }
 }
