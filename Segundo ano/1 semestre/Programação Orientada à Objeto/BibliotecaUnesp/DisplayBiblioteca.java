
package com.mycompany.bibliotecaunesp;

import java.io.File;
import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**Classe que realizará as interações com o usuário, pedindo informações a ele, para que ele possa realizar operações dentro da sua conta da biblioteca.
 * @author Lara
 */
public class DisplayBiblioteca {
    private Biblioteca biblioteca;
    private Administrador administrador = new Administrador();
    Scanner scanner = new Scanner(System.in);
    Scanner scanner2 = new Scanner(System.in);
    
    /**Método construtor que cria a biblioteca, sua lista de itens e usuários, e um administrador, a partir de um banco de dados.
     * @param dados dados dos itens 
     * @param adm dados do administrador
     * @param users dados dos usuários
     */
    public DisplayBiblioteca(String dados, String adm, String users)
    {
        biblioteca = new Biblioteca();
        File arquivo = new File(dados);
        File arquivo2 = new File(adm);
        File arquivo3 = new File(users);
        Scanner leitura = null;
        
        try{
            leitura = new Scanner(arquivo);
        }
        catch(FileNotFoundException ex)
        {
            Logger.getLogger(BibliotecaUNESP.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        while(leitura.hasNextLine())
        {
            String linha = leitura.nextLine();
            
            String campos[] = linha.split("#");
            
            if("Livro".equals(campos[0]))
            {
                biblioteca.cadastrarLivros(campos[0], campos[1], campos[2], Integer.valueOf(campos[3]), Integer.valueOf(campos[4]), 0, campos[5], campos[6]);
            }
            else if("Revista".equals(campos[0]))
            {
                biblioteca.cadastrarRevistas(campos[0], campos[1], campos[2], Integer.valueOf(campos[3]), Integer.valueOf(campos[4]), 0, Integer.valueOf(campos[5]), Integer.valueOf(campos[6]));
            }
            else
                biblioteca.cadastrarCD(campos[0], campos[1], campos[2], Integer.valueOf(campos[3]), Integer.valueOf(campos[4]), 0, Integer.valueOf(campos[5]), campos[6]);
        }
        
        try{
            leitura = new Scanner(arquivo2);
        }
        catch(FileNotFoundException ex)
        {
            Logger.getLogger(BibliotecaUNESP.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        while(leitura.hasNextLine())
        {
            String linha = leitura.nextLine();
            
            String campos[] = linha.split("#");
            
            administrador.setNome(campos[0]);
            administrador.setSenha(campos[1]);
            administrador.setNumeroIdentificacao(campos[2]);
        }
        
        try{
            leitura = new Scanner(arquivo3);
        }
        catch(FileNotFoundException ex)
        {
           Logger.getLogger(BibliotecaUNESP.class.getName()).log(Level.SEVERE, null, ex); 
        }
        
        while(leitura.hasNextLine())
        {
            String linha = leitura.nextLine();
            
            String campos[] = linha.split("#");
            
            if("Aluno".equals(campos[0]))
            {
                biblioteca.cadastrarAluno(campos[0], campos[1], campos[2], campos[3], Integer.valueOf(campos[4]), campos[5]);
            }
            else if("Professor".equals(campos[0]))
            {
                biblioteca.cadastrarProfessor(campos[0], campos[1], campos[2], campos[3], campos[4], campos[5]);
            }
            else
            {
                biblioteca.cadastrarAssessorTecnico(campos[0], campos[1], campos[2], campos[3], campos[4]);
            }
        }
    }
    
    /**Método responsável por logar a conta do usuário.
     * Ele primeiramente pergunta se o usuário é um administrador ou não, caso seja, ele o encaminha para uma tela com as operações possíveis para um administrador. Caso o usuário não seja um administrador, ele é encaminhado para uma tela com outras operações possívei.
     * Em seguida ele pede as informações necessárias para logar a conta.
     */
    public void login()
    {
        int op;
        boolean verifica;
        String senha, nome;

        do{
            System.out.println("Bem vindo!");
            System.out.println("Escolha uma opção: ");
            System.out.println("[1]Administrador");
            System.out.println("[2]Usuário");
            op = scanner2.nextInt();
            if(op < 1 || op > 2)
            {
                System.out.println("Opção inválida. Tente novamente: ");
            }
        }while(op < 1 || op > 2);
        
        if(op == 1)
        {
            do{
                System.out.println("Bem vindo " + administrador.getNome());
                System.out.println("Digite sua senha: ");
                senha = scanner.nextLine();
                if(senha.equals(administrador.getSenha()))
                {
                    System.out.println("Conta logada!");
                    telaAdm();
                }
                else
                {
                    System.out.println("Senha inválida. Tente novamente");
                }
            }while(!senha.equals(administrador.getSenha()));
        }
        else
        {                
            System.out.println("Bem vindo!");
            do
            {            
                System.out.println("Digite seu nome: ");
                nome = scanner.nextLine();
                System.out.println("Digite sua senha: ");
                senha = scanner.nextLine();
                verifica = biblioteca.logar(nome, senha);
                if(verifica)
                {
                    System.out.println("Conta logada com sucesso! Digite qualquer tecla para continuar.");
                    scanner.nextLine();
                    telaUsuario();
                }
                else
                {
                    System.out.println("Conta não encontrada. Tente novamente!");
                    scanner.nextLine();
                }
            }while(!verifica);
        }
    }
    
    /**Método que corresponde a tela mostrada ao administrador do sistema.
     * Permite que ele realize operações como cadastrar um item ou usuário.
     * Chama outros métodos de acordo com a opção escolhida.
     */
    private void telaAdm()
    {
        int op;
        
        do{
            do{
            System.out.println("Sistema da biblioteca.");
            System.out.println("Escolha uma opção: ");
            System.out.println("[1]Cadastro de usuario");
            System.out.println("[2]Cadastro de item");
            System.out.println("[3]Sair");
            op = scanner2.nextInt();
            if(op < 1 || op > 3)
            {
                System.out.println("Opção inválida. Tente novamente: ");
            }
            }while(op < 1 || op > 3);

            switch(op)
            {
                case(1):
                    cadastrarUsuario(); break;
                case(2):
                    cadastrarItem(); break;
                default:
                    login(); break;
            }
        }while(op != 3);
    }
    
    /**Método que corresponde a tela mostrada ao usuário do sistema.
     * Permite que ele realize operações como emprestar, devolver ou buscarum item, e visualizar sua lista de empréstimos.
     * Chama outros métodos de acordo com a opção escolhida.
     */
    private void telaUsuario()
    {
        int op;
        do
        {
            do{
            System.out.println("Sistema da biblioteca.");
            System.out.println("Escolha uma opção: ");
            System.out.println("[1]Empréstimo de item");
            System.out.println("[2]Devolução de item"); //calculo da multa
            System.out.println("[3]Busca por item");
            System.out.println("[4]Listagem de itens emprestados por usuário");
            System.out.println("[5]Sair");
            op = scanner2.nextInt();
            if(op < 1 || op > 5)
            {
                System.out.println("Opção inválida. Tente novamente: ");
            }
            }while(op < 1 || op > 5);
        
            switch(op)
            {
                case(1):
                    emprestarItem(); break;
                case(2):
                    devolverItem(); break;
                case(3):
                    buscarItens(); break;
                case(4):
                    listarItens(); break;
                default:
                    deslogar(); break;
            }
        } while(op != 5);
    }
    
    /**Método responsável pelo cadastro manual de um usuário.
     * Pede informações necessárias ao administrador e realiza o cadastro.
     */
    private void cadastrarUsuario()
    {
        int op, periodo;
        String nome, matricula, curso, departamento, titulacao, secao, senha;
        boolean verifica = false;

        do{
            System.out.println("Escolha uma opção: ");
            System.out.println("[1]Aluno");
            System.out.println("[2]Professor");
            System.out.println("[3]Assessor Técnico");
            op = scanner2.nextInt();
            if(op < 1 || op > 3)
            {
                System.out.println("Opção inválida. Tente novamente!");
            }
        }while(op < 1 || op > 3);
        
        do{
            try{
                if(op == 1)
                {
                    System.out.println("Digite seu nome: ");
                    nome = scanner.nextLine();
                    System.out.println("Digite sua matrícula: ");
                    matricula = scanner.nextLine();
                    System.out.println("Digite seu curso: ");
                    curso = scanner.nextLine();
                    System.out.println("Digite seu período: ");
                    periodo = scanner2.nextInt();
                    System.out.println("Digite uma senha para a sua conta: ");
                    senha = scanner.nextLine();
                    biblioteca.cadastrarAluno("Aluno", nome, matricula, curso, periodo, senha);
                }
                else if(op == 2)
                {
                    System.out.println("Digite seu nome: ");
                    nome = scanner.nextLine();
                    System.out.println("Digite sua matrícula: ");
                    matricula = scanner.nextLine();
                    System.out.println("Digite seu departamento: ");
                    departamento = scanner.nextLine();
                    System.out.println("Digite sua titulação: ");
                    titulacao = scanner.nextLine();
                    System.out.println("Digite uma senha para a sua conta: ");
                    senha = scanner.nextLine();
                    biblioteca.cadastrarProfessor("Professor", nome, matricula, departamento, titulacao, senha);
                }
                else
                {
                    System.out.println("Digite seu nome: ");
                    nome = scanner.nextLine();
                    System.out.println("Digite sua matrícula: ");
                    matricula = scanner.nextLine();
                    System.out.println("Digite sua seção: ");
                    secao = scanner.nextLine();
                    System.out.println("Digite uma senha para a sua conta: ");
                    senha = scanner.nextLine();
                    biblioteca.cadastrarAssessorTecnico("Acessor Técnico", nome, matricula, secao, senha);
                }
                verifica = true;
            } catch(InputMismatchException ex)
            {
                System.err.println("Informações inválidas. Tente novamente!");
                scanner2.nextLine();
            }
        }while(!verifica);
    }
    
    /**Método responsável pelo cadastro manual de um item.
     * Pede informações necessárias ao administrador e realiza o cadastro.
     */
    private void cadastrarItem()
    {
        int op, ano, quantD, volume, numero;
        String titulo, autor, editora, ISBM, gravadora;
        boolean verifica = false;
        
        do{
            System.out.println("Escolha uma opção: ");
            System.out.println("[1]Livro");
            System.out.println("[2]Revista");
            System.out.println("[3]CD");
            op = scanner2.nextInt();
            if(op < 1 || op > 3)
            {
                System.out.println("Opção Inválida! Tente novamente: ");
            }
        }while(op < 1 || op > 3);
        
        do{
            try{
                if(op == 1)
                {
                    System.out.println("Digite o título do livro: ");
                    titulo = scanner.nextLine();
                    System.out.println("Digite o autor do livro: ");
                    autor = scanner.nextLine();
                    System.out.println("Digite o ano de publicação: ");
                    ano = scanner2.nextInt();
                    System.out.println("Digite a quantidade disponível: ");
                    quantD = scanner2.nextInt();
                    System.out.println("Digite a editora do livro: ");
                    editora = scanner.nextLine();
                    System.out.println("Digite o ISBM: ");
                    ISBM = scanner.nextLine();
                    biblioteca.cadastrarLivros("Livro", titulo, autor, ano, quantD, 0, editora, ISBM);
                }
                else if(op == 2)
                {
                    System.out.println("Digite o título da revista: ");
                    titulo = scanner.nextLine();
                    System.out.println("Digite o autor da revista: ");
                    autor = scanner.nextLine();
                    System.out.println("Digite o ano de publicação: ");
                    ano = scanner2.nextInt();
                    System.out.println("Digite a quantidade disponível: ");
                    quantD = scanner2.nextInt();
                    System.out.println("Digite o volume da revista: ");
                    volume = scanner2.nextInt();
                    System.out.println("Digite o número da revista: ");
                    numero = scanner2.nextInt();
                    biblioteca.cadastrarRevistas("Revista", titulo, autor, ano, quantD, 0, volume, numero);
                }
                else
                {
                    System.out.println("Digite o título do CD: ");
                    titulo = scanner.nextLine();
                    System.out.println("Digite o autor do CD: ");
                    autor = scanner.nextLine();
                    System.out.println("Digite o ano de publicação: ");
                    ano = scanner2.nextInt();
                    System.out.println("Digite a quantidade disponível: ");
                    quantD = scanner2.nextInt();
                    System.out.println("Digite o volume do CD: ");
                    volume = scanner2.nextInt();
                    System.out.println("Digit a gravadora: ");
                    gravadora = scanner.nextLine();
                    biblioteca.cadastrarCD("CD", titulo, autor, ano, quantD, 0, volume, gravadora);
                }
                
                verifica = true;
            }
            catch(InputMismatchException ex)
            {
                System.err.println("Informações inválidas. Tente novamente!");
                scanner2.nextLine();
            }
        }while(!verifica);
    }
    
    /**Método que permite que o usuário empreste um item.
     * Pede informações sobre o item desejado e adiciona o mesmo na lista de empréstimos do usuário.
     */
    private void emprestarItem()
    {
        String titulo, autor;
        int dia, mes, ano;
        LocalDate data;
   
        System.out.println("Digite o título do item que deseja emprestar: ");
        titulo = scanner.nextLine();
        System.out.println("Digite o autor do item que deseja emprestar: ");
        autor = scanner.nextLine();
        System.out.println("Digite a data do emprestimo: ");
        System.out.println("Dia: ");
        dia = scanner2.nextInt();
        System.out.println("Mês: ");
        mes = scanner2.nextInt();
        System.out.println("Ano: ");
        ano = scanner2.nextInt();
        data = LocalDate.of(ano, mes, dia);
        
        try
        {
            biblioteca.emprestarItem(titulo, autor, data);        
            DateTimeFormatter formato = DateTimeFormatter.ofPattern("dd/MM/yy");
            String dataFormatada;
            LocalDate dataF;
            dataF = biblioteca.getDataDevolucao(titulo, autor);
            dataFormatada = dataF.format(formato);
            System.out.println("Item emprestado! Sua data de devolução é: " + dataFormatada);
            scanner.nextLine();
        }
        catch(ExceptionItemNaoCadastrado ex)
        {
            System.out.println(ex.getMensagem());
            scanner.nextLine();
        }
        catch(ExceptionItemIndisponivel ex)
        {
            System.out.println(ex.getMensagem());
            scanner.nextLine();
        }

    }
    
    /**Método que permite que um usuário devolva um item.
     * Pede informações sobre o item a ser devolvido, retirando o mesmo da lista de empréstimos do usuário e informando a multa, caso o item seja devolvido com atraso.
     */
    private void devolverItem()
    {
        String titulo, autor;
        int dia, mes, ano;
        LocalDate data;
        double multa;
        
        System.out.println("Digite o nome do item a ser devolvido: ");
        titulo = scanner.nextLine();
        System.out.println("Digite o autor do item a ser devolvido: ");
        autor = scanner.nextLine();
        System.out.println("Digite a data de hoje: ");
        System.out.println("Dia: ");
        dia = scanner2.nextInt();
        System.out.println("Mês: ");
        mes = scanner2.nextInt();
        System.out.println("Ano: ");
        ano = scanner2.nextInt();
        data = LocalDate.of(ano, mes, dia);
        
        try{
            multa = biblioteca.devolverItem(titulo, autor, data);
            if(multa > 0)
            {
                System.out.println("Item devolvido com atraso!");
                System.out.println("Sua multa é: " + multa);
                scanner.nextLine();
            }
            else
            {
                System.out.println("Item devolvido!");
                scanner.nextLine();
            }
        }
        catch(ExceptionItemNaoEmprestado ex)
        {
            System.out.println(ex.getMensagem());
            scanner.nextLine();
        }
    }
    
    /**Método que permite que o usuário busque um item na lista de itens disponíveis na biblioteca.
     */
    private void buscarItens()
    {
        String titulo, autor;
        Item item;
        
        System.out.println("Digite o titulo do item buscado: ");
        titulo = scanner.nextLine();
        System.out.println("Digite o autor do item buscado: ");
        autor = scanner.nextLine();
        item = biblioteca.buscarItem(titulo, autor);
        if(item != null)
        {
            System.out.println("O(A) " + item.tipo + " que você procura foi encontrado!");
            System.out.println("Título: " + item.titulo);
            System.out.println("Autor: " + item.autor);
            System.out.println("Ano da publicação: " + item.anoPublicacao);
            if(item instanceof Livro)
            {
                System.out.println("Editora: " + ((Livro) item).getEditora());
                System.out.println("ISBN: " + ((Livro)item).getISBN());
            }
            else if(item instanceof Revista)
            {
                System.out.println("Volume: " + ((Revista)item).getVolume());
                System.out.println("Número: " + ((Revista)item).getNumero());
            }
            else
            {
                System.out.println("Volume: " + ((CD)item).getVolume());
                System.out.println("Gravadora: " + ((CD)item).getGravadora());
            }
            System.out.println("Quantidade disponível: " + item.quantDisponivel);
            System.out.println("Quantidade emprestada: " + item.quantEmprestada);
            scanner.nextLine();
        }
        else
        {
            System.out.println("Desculpe, ainda não temos esse item!");
            scanner.nextLine();
        }
    }
    
    /**Método que lista os itens emprestados de um usuário.
     */
    private void listarItens()
    {
        biblioteca.listarItens();
        scanner.nextLine();
    }
    
    /**Método para deslogar a conta do usuário.
     */
    private void deslogar()
    {
        biblioteca.deslogar();
        login();
    }
}
