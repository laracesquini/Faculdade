
package com.mycompany.bibliotecaunesp;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**Classe com a relação da biblioteca com os usuários e itens.
 * @author Lara
 */
public class Biblioteca {
    private Usuario contaLogada;
    private ArrayList<Usuario>usuarios = new ArrayList<>();
    private ArrayList<Item>itens = new ArrayList<>();
    
    /**Método para adicionar um usuário na lista de usuários com base no tipo de usuário.
     * @param usuario usuário a ser adicionado
     */
    public void cadastrarUsuario(Usuario usuario)
    {
        if(usuario instanceof Aluno)
            usuarios.add((Aluno)usuario);
        else if(usuario instanceof Professor)
            usuarios.add((Professor)usuario);
        else
            usuarios.add((AssessorTecnico)usuario);
    }
    
    /**Método para adicionar um item na lista de itens com base no tipo de item.
     * @param item item a ser adicionado
     */
    public void cadastrarItens(Item item)
    {
        if(item instanceof Livro)
            itens.add((Livro)item);
        else if(item instanceof Revista)
            itens.add((Revista)item);
        else
            itens.add((CD)item);
    }
    
    /**Método para cadastrar um livro na biblioteca.
     * @param tipo tipo de item, que no caso é livro
     * @param titulo título do livro
     * @param autor autor do livro
     * @param anoPublicacao ano de publicação do livro
     * @param quantDisponivel quantidade disponível 
     * @param quantEmprestada quantidade emprestada
     * @param editora editora do livro
     * @param ISBN ISBN do livro
     */
    public void cadastrarLivros(String tipo, String titulo, String autor, int anoPublicacao, int quantDisponivel, int quantEmprestada, String editora, String ISBN)
    {
        Livro livro = new Livro();
        livro.tipo = tipo;
        livro.titulo = titulo;
        livro.autor = autor;
        livro.anoPublicacao = anoPublicacao;
        livro.quantDisponivel = quantDisponivel;
        livro.quantEmprestada = quantEmprestada;
        livro.setEditora(editora);
        livro.setISBN(ISBN);
        cadastrarItens(livro);
    }
    
    /**Método para cadastrar uma revista na biblioteca.
     * @param tipo tipo de item, que no caso é revista
     * @param titulo título da revista
     * @param autor autor da revista
     * @param anoPublicacao ano da publicação da revista
     * @param quantDisponivel quantidade disponível
     * @param quantEmprestada quantidade emprestada
     * @param volume volume da revista
     * @param numero número da revista
     */
    public void cadastrarRevistas(String tipo, String titulo, String autor, int anoPublicacao, int quantDisponivel, int quantEmprestada, int volume, int numero)
    {
        Revista revista = new Revista();
        revista.tipo = tipo;
        revista.titulo = titulo;
        revista.autor = autor;
        revista.anoPublicacao = anoPublicacao;
        revista.quantDisponivel = quantDisponivel;
        revista.quantEmprestada = quantEmprestada;
        revista.setNumero(numero);
        revista.setVolume(volume);
        cadastrarItens(revista);
    }
    
    /**Método para cadastrar um CD na biblioteca.
     * @param tipo tipo de item, que no caso é CD
     * @param titulo título do CD
     * @param autor autor do CD
     * @param anoPublicacao ano da publicação do CD
     * @param quantDisponivel quantidade disponível
     * @param quantEmprestada quantidade emprestada
     * @param volume volume do CD
     * @param gravadora gravadora do CD
     */
    public void cadastrarCD(String tipo, String titulo, String autor, int anoPublicacao, int quantDisponivel, int quantEmprestada, int volume, String gravadora)
    {
        CD cd = new CD();
        cd.tipo = tipo;
        cd.titulo = titulo;
        cd.autor = autor;
        cd.anoPublicacao = anoPublicacao;
        cd.quantDisponivel = quantDisponivel;
        cd.quantEmprestada = quantEmprestada;
        cd.setGravadora(gravadora);
        cd.setVolume(volume);
        cadastrarItens(cd);
    }
    
    /**Método para cadastrar um aluno na biblioteca.
     * @param tipo tipo de usuário, que no caso é aluno
     * @param nome nome do aluno
     * @param matricula matrícula do aluno
     * @param curso curso do aluno
     * @param periodo período do aluno
     * @param senha senha da conta do aluno na biblioteca
     */
    public void cadastrarAluno(String tipo, String nome, String matricula, String curso, int periodo, String senha)
    {
        Aluno aluno = new Aluno();
        aluno.tipo = tipo;
        aluno.nome = nome;
        aluno.matricula = matricula;
        aluno.senha = senha;
        aluno.setCurso(curso);
        aluno.setPeriodo(periodo);
        cadastrarUsuario(aluno);
    }
    
    /**Método para cadastrar um professor na biblioteca.
     * @param tipo tipo de usuário, que no caso é professor
     * @param nome nome do professor
     * @param matricula matrícula do professor
     * @param departamento departamento do professor
     * @param titulacao titulação do professor
     * @param senha senha da conta do professor na biblioteca
     */
    public void cadastrarProfessor(String tipo, String nome, String matricula, String departamento, String titulacao, String senha)
    {
        Professor professor = new Professor();
        professor.tipo = tipo;
        professor.nome = nome;
        professor.matricula = matricula;
        professor.senha = senha;
        professor.setDepartamento(departamento);
        professor.setTitulacao(titulacao);
        cadastrarUsuario(professor);
    }
    
    /**Método para cadastrar um assessor técnico na biblioteca.
     * @param tipo tipo de usuário, que no caso é assessor técnico
     * @param nome nome do assessor técnico
     * @param matricula matrícula do assessor técnico
     * @param secao seção do assessor técnico
     * @param senha senha da conta do assesor técnico na biblioteca
     */
    public void cadastrarAssessorTecnico(String tipo, String nome, String matricula, String secao, String senha)
    {
        AssessorTecnico assessor = new AssessorTecnico();
        assessor.tipo = tipo;
        assessor.nome = nome;
        assessor.matricula = matricula;
        assessor.senha = senha;
        assessor.setSecao(secao);
        cadastrarUsuario(assessor);
    }
    
    /**Método para buscar uma conta dentro da lista de contas da biblioteca.
     * @param nome nome do usuário da conta
     * @param senha senha do usuário da conta
     * @return o usuário da conta, caso ele seja encontrado, ou null, caso não seja encontrado
     */
    public Usuario buscarConta(String nome, String senha)
    {
        for(Usuario user : usuarios)
        {
            if(nome.equals(user.nome))
            {
                if(senha.equals(user.senha))
                    return user;
            }
        }
        
        return null;
    }
    
    /**Método para buscar um item dentro da lista de itens.
     * @param titulo título do item
     * @param autor autor do item
     * @return o item, caso ele seja encontrado, ou null, caso não seja encontrado
     */
    public Item buscarItem(String titulo, String autor)
    {
        for(Item item : itens)
        {
            if(titulo.equals(item.titulo) && autor.equals(item.autor))
                return item;
        }
        
        return null;
    }
    
    /**Método para logar um usuário, mantendo a referência de sua conta para realizar as operações.
     * @param nome nome do usuário
     * @param senha senha do usuário
     * @return true se for possível logar ou false, se não for possível
     */
    public boolean logar(String nome, String senha)
    {
        if(buscarConta(nome, senha) != null)
        {
            if(buscarConta(nome, senha) instanceof Aluno)
            {
                contaLogada = new Aluno();
                contaLogada = (Aluno)buscarConta(nome, senha);
            }
            else if(buscarConta(nome, senha) instanceof Professor)
            {
                contaLogada = new Professor();
                contaLogada = (Professor)buscarConta(nome, senha);
            }
            else
            {
                contaLogada = new AssessorTecnico();
                contaLogada = (AssessorTecnico)buscarConta(nome, senha);
            }
            
            return true;
        }
        return false;
    }
    
    /**Método para que um usuário possa emprestar um item da biblioteca.
     * @param titulo título do item a ser emprestado
     * @param autor autor do item a ser emprestado
     * @param data data do empréstimo
     * @throws ExceptionItemNaoCadastrado caso o item desejado ainda não estiver no cadastro
     * @throws ExceptionItemIndisponivel caso o item desejado não estiver disponível
     */
    public void emprestarItem(String titulo, String autor, LocalDate data) throws ExceptionItemNaoCadastrado, ExceptionItemIndisponivel
    {
        Emprestimo emprestimo = new Emprestimo();
        Item item;
        if(buscarItem(titulo, autor) == null)
        {
            throw new ExceptionItemNaoCadastrado("Desculpe, ainda não temos esse item no cadastro!");
        }
       
        if(buscarItem(titulo, autor) instanceof Livro)
        {
            item = new Livro();
            item = (Livro)buscarItem(titulo, autor);
        }
        else if(buscarItem(titulo, autor) instanceof Revista)
        {
            item = new Revista();
            item = (Revista)buscarItem(titulo, autor);
        }
        else
        {
            item = new CD();
            item = (CD)buscarItem(titulo, autor);
        }
        
        emprestimo.setItem(item);
        
        try{
            emprestimo.getItem().emprestimo();
        }
        catch(ExceptionItemIndisponivel ex)
        {
            throw ex;
        }
        
        emprestimo.setDataEmprestimo(data);
        data = data.plusDays(10);
        emprestimo.setDataDevolucaoPrevista(data);
        contaLogada.itens.add(emprestimo);
    }
    
    /**Método para que o usuário possa devolver um item emprestado.
     * @param titulo título do item a ser devolvido
     * @param autor autor do item a ser devolvido
     * @param data data da devolução
     * @return uma multa, caso o item seja devolvido com atraso 
     * @throws ExceptionItemNaoEmprestado caso o item a ser devolvido não foi emprestado por esse usuário
     */
    public double devolverItem(String titulo, String autor, LocalDate data) throws ExceptionItemNaoEmprestado
    {
        double multa;
        for(Emprestimo emprestimo : contaLogada.itens)
        {
            if((emprestimo.getItem().titulo).equals(titulo) && (emprestimo.getItem().autor).equals(autor))
            {
                emprestimo.setDataDevolucaoReal(data);
                emprestimo.getItem().devolucao();
                multa = contaLogada.calcularMulta(emprestimo);
                contaLogada.itens.remove(emprestimo);
                return multa;
            }
        }
        throw new ExceptionItemNaoEmprestado("Você não emprestou esse item!");
    }
    
    /**Método para acessar a data de devolução de um item emprestado.
     * @param titulo título do item
     * @param autor autor do item
     * @return a data de devolução
     */
    public LocalDate getDataDevolucao(String titulo, String autor)
    {
        for(Emprestimo emprestimo : contaLogada.itens)
        {
            if(emprestimo.getItem().titulo.equals(titulo))
                return emprestimo.getDataDevolucaoPrevista();
        }
        
        return null;
    }
   
    /**Método para listar todos os itens que estão emprestados de um usuário.
     * Percorre a lista de empréstimos do usuário, mostrando as informações de cada empréstimo na tela
     */
    public void listarItens()
    {
        int flag = 0;
        DateTimeFormatter formato = DateTimeFormatter.ofPattern("dd/MM/yy");
        String dataFormatada;
        LocalDate dataF;
        
        for(Emprestimo emprestimo : contaLogada.itens)
        {
            System.out.println("Título: " + emprestimo.getItem().titulo);
            System.out.println("Autor: " + emprestimo.getItem().autor);
            dataF = emprestimo.getDataEmprestimo();
            dataFormatada = dataF.format(formato);
            System.out.println("Data do empréstimo: " + dataFormatada);
            dataF = emprestimo.getDataDevolucaoPrevista();
            dataFormatada = dataF.format(formato);
            System.out.println("Data de devolução: " + dataFormatada);
            flag = 1;
        }
        
        if(flag == 0)
        {
            System.out.println("Você não tem nenhum empréstimo! ");
        }
    }
    
    /**Método para deslogar a conta do usuário, ou seja, perde-se a referência a sua conta.
     */
    public void deslogar()
    {
        contaLogada = null;
    }
}

