

package com.mycompany.bibliotecaunesp;

/**Classe que contém a main, função principal.
 * Nessa classe, somente é feita a instanciação de um objeto do tipo DisplayBiblioteca, passando o caminho para os arquivos com as informações necessárias.
 * Em seguida, o método login é chamado, para que o usúario posso realizar seu login e realizar as operações.
 * @author Lara
 */
public class BibliotecaUNESP {

    public static void main(String[] args) {
        String caminhoBiblio = "C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\BibliotecaUNESP\\src\\main\\java\\com\\mycompany\\bibliotecaunesp\\dados.txt";
        String caminhoAdm = "C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\BibliotecaUNESP\\src\\main\\java\\com\\mycompany\\bibliotecaunesp\\adm.txt";
        String caminhoUsers = "C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\BibliotecaUNESP\\src\\main\\java\\com\\mycompany\\bibliotecaunesp\\users.txt";
        DisplayBiblioteca biblio = new DisplayBiblioteca(caminhoBiblio, caminhoAdm, caminhoUsers);
        
        biblio.login();
    }
}
