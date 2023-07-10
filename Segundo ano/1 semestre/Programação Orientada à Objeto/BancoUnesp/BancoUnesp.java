
package com.mycompany.bancounesp;

/**Classe que contém a main, função principal.
 * Nessa classe, somente é feita a instanciação de um objeto do tipo DisplayBanco, passando o caminho para os arquivos com as informações necessárias.
 * Em seguida, o método login é chamado, para que o usúario posso realizar seu login e realizar as operações.
 * @author Lara
 */
public class BancoUnesp {

    public static void main(String[] args){
        String caminhoBanco = "C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\BancoUnesp\\src\\main\\java\\com\\mycompany\\bancounesp\\bancoA.txt";
        String caminhoAgencia = "C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\BancoUnesp\\src\\main\\java\\com\\mycompany\\bancounesp\\agenciasA.txt";
        String caminhoContas =  "C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\BancoUnesp\\src\\main\\java\\com\\mycompany\\bancounesp\\contasA.txt";
        DisplayBanco bank = new DisplayBanco(caminhoBanco, caminhoAgencia, caminhoContas);
        
        bank.login();
    }
}
