
package com.mycompany.bibliotecaunesp;

/**Classe com as informações do administrador do sistema
 * @author Lara
 */
public class Administrador {
    private String nome;
    private String senha;
    private String numeroIdentificacao;

    /**Método para o retorno do nome do administrador. 
     * @return o nome do administrador
     */
    public String getNome() {
        return nome;
    }

    /**Método para atribuição de um valor à variável referente ao nome do administrador.
     * @param nome nome do administrador 
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**Método para o retorno da senha do administrador. 
     * @return a senha do administrador
     */
    public String getSenha() {
        return senha;
    }

    /**Método para atribuição de um valor à variável referente à senha do administrador.
     * @param senha senha do administrador
     */
    public void setSenha(String senha) {
        this.senha = senha;
    }
    
    /**Método para atribuição de um valor à variável referente ao número de identificação do administrador.
     * @param numeroIdentificacao número de identificação do administrador
     */
    public void setNumeroIdentificacao(String numeroIdentificacao) {
        this.numeroIdentificacao = numeroIdentificacao;
    }
}
