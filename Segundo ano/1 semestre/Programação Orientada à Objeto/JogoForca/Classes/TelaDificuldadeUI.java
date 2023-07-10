package InterfaceGrafica;

import com.mycompany.jogoforca.Jogo;
import com.mycompany.jogoforca.NivelIndisponivelException;
import com.mycompany.jogoforca.Palavras;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**Essa classe representa uma tela que será chamada quando o usuário for escolher a dificuldade da palavra que quer jogar.
 *
 * @author Ana Beatriz Gomes Takehara, Heloísa Silveira Bula e Lara Cesquini Stopa
 */
public class TelaDificuldadeUI extends javax.swing.JFrame 
{
    private static Jogo jogoAtual;
    private Palavras palavraAtual;
    
    /**Construtor da classe TelaDificuldadeUI
     * 
     */
    public TelaDificuldadeUI(Jogo jogoAtual)
    {
        this.jogoAtual = jogoAtual;
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jButton4 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(204, 204, 255));
        jPanel1.setPreferredSize(new java.awt.Dimension(841, 528));

        jButton1.setBackground(new java.awt.Color(153, 153, 255));
        jButton1.setFont(new java.awt.Font("Britannic Bold", 0, 24)); // NOI18N
        jButton1.setForeground(new java.awt.Color(0, 0, 0));
        jButton1.setText("Fácil");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setBackground(new java.awt.Color(153, 153, 255));
        jButton2.setFont(new java.awt.Font("Britannic Bold", 0, 24)); // NOI18N
        jButton2.setForeground(new java.awt.Color(0, 0, 0));
        jButton2.setText("Médio");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setBackground(new java.awt.Color(153, 153, 255));
        jButton3.setFont(new java.awt.Font("Britannic Bold", 0, 24)); // NOI18N
        jButton3.setForeground(new java.awt.Color(0, 0, 0));
        jButton3.setText("Difícil");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Britannic Bold", 0, 36)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 0, 0));
        jLabel1.setText("Escolha o nível de dificuldade:");

        jButton4.setBackground(new java.awt.Color(204, 204, 255));
        jButton4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagens/sair.png"))); // NOI18N
        jButton4.setBorder(null);
        jButton4.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap(194, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 492, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(155, 155, 155))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 214, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 214, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 214, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(308, 308, 308))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap())))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jButton4, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(56, 56, 56)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(54, 54, 54)
                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 54, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(45, 45, 45)
                .addComponent(jButton2, javax.swing.GroupLayout.PREFERRED_SIZE, 54, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(44, 44, 44)
                .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 54, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(90, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**Essa action ocorrerá caso o usuário selecione o botão de dificuldade fácil. Nele, o índice da palavra que será jogada é escrito na linha do usuário logado.
     * 
     * @param evt Evento gerado caso o usuário clique no botão fácil.
     */
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed

        
        try
        {
            palavraAtual = jogoAtual.palavraJogo("fácil");
            jogoAtual.getPartida().setPalavra(palavraAtual);
           
            File arquivo = new File("C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\JogoForca\\usuarios.txt");
            String conteudoBuscado = jogoAtual.getUsuario().getNome() + "#" + jogoAtual.getUsuario().getNomeUser() + "#" + jogoAtual.getUsuario().getEmail() + "#" + jogoAtual.getUsuario().getSenha() + "#";
            for(int i = 0; i< jogoAtual.getUsuario().getIndicesPalavras().size(); i++)
            {
                conteudoBuscado += jogoAtual.getUsuario().getIndicesPalavras().get(i) + " ";
            }
               
            conteudoBuscado += "#" + jogoAtual.getUsuario().getPontoDica().getQuantidade() + "#" + jogoAtual.getUsuario().getPontoChance().getQuantidade();
            
            for(int i = 0; i< jogoAtual.getPalavras().size(); i++)
            {
                if((jogoAtual.getPalavras().get(i).getPalavra()).equals(jogoAtual.getPartida().getPalavra().getPalavra()))
                {
                    jogoAtual.getUsuario().getIndicesPalavras().add(i);
                }
            }
            
            String novoConteudo = jogoAtual.getUsuario().getNome() + "#" + jogoAtual.getUsuario().getNomeUser() + "#" + jogoAtual.getUsuario().getEmail() + "#" + jogoAtual.getUsuario().getSenha() + "#";
            for(int i = 0; i< jogoAtual.getUsuario().getIndicesPalavras().size(); i++)
                novoConteudo += jogoAtual.getUsuario().getIndicesPalavras().get(i) + " ";
            novoConteudo += "#" + jogoAtual.getUsuario().getPontoDica().getQuantidade() + "#" + jogoAtual.getUsuario().getPontoChance().getQuantidade();
            
            try
            {
                BufferedReader br = new BufferedReader(new FileReader(arquivo));
                StringBuilder sb = new StringBuilder();
                String linha;
                boolean linhaEncontrada = false;
                
                while((linha = br.readLine()) != null)
                {
                    if(linha.equals(conteudoBuscado))
                    {
                        sb.append(novoConteudo);
                        linhaEncontrada = true;
                    }
                    else
                    {
                       sb.append(linha);
                    }
                    sb.append(System.lineSeparator());
                }
                br.close();
                
                if(linhaEncontrada)
                {
                    BufferedWriter bw = new BufferedWriter(new FileWriter(arquivo));
                    bw.write(sb.toString());
                    bw.close();
                }
            }
            catch(IOException ex)
            {
                Logger.getLogger(TelaDificuldadeUI.class.getName()).log(Level.SEVERE, null, ex);
            }


            new TelaPrincipalUI(jogoAtual).setVisible(true);
            dispose();
        }
        catch(NivelIndisponivelException  e)
        {
            JOptionPane.showMessageDialog(this,e.getMessage(),"Parabéns", JOptionPane.INFORMATION_MESSAGE);
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    /**Essa action ocorrerá caso o usuário selecione o botão de dificuldade médio. Nele, o índice da palavra que será jogada é escrito na linha do usuário logado.
     * 
     * @param evt Evento gerado caso o usuário clique no botão médio.
     */
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed

        
        try
        {
            palavraAtual = jogoAtual.palavraJogo("médio");
            jogoAtual.getPartida().setPalavra(palavraAtual);
            
            File arquivo = new File("C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\JogoForca\\usuarios.txt");
            String conteudoBuscado = jogoAtual.getUsuario().getNome() + "#" + jogoAtual.getUsuario().getNomeUser() + "#" + jogoAtual.getUsuario().getEmail() + "#" + jogoAtual.getUsuario().getSenha() + "#";
            for(int i = 0; i< jogoAtual.getUsuario().getIndicesPalavras().size(); i++)
                conteudoBuscado += jogoAtual.getUsuario().getIndicesPalavras().get(i) + " ";
            conteudoBuscado += "#" + jogoAtual.getUsuario().getPontoDica().getQuantidade() + "#" + jogoAtual.getUsuario().getPontoChance().getQuantidade();
            
            for(int i = 0; i< jogoAtual.getPalavras().size(); i++)
            {
                if((jogoAtual.getPalavras().get(i).getPalavra()).equals(jogoAtual.getPartida().getPalavra().getPalavra()))
                {
                    jogoAtual.getUsuario().getIndicesPalavras().add(i);
                }
            }
            
            String novoConteudo = jogoAtual.getUsuario().getNome() + "#" + jogoAtual.getUsuario().getNomeUser() + "#" + jogoAtual.getUsuario().getEmail() + "#" + jogoAtual.getUsuario().getSenha() + "#";
            for(int i = 0; i< jogoAtual.getUsuario().getIndicesPalavras().size(); i++)
                novoConteudo += jogoAtual.getUsuario().getIndicesPalavras().get(i) + " ";
            novoConteudo += "#" + jogoAtual.getUsuario().getPontoDica().getQuantidade() + "#" + jogoAtual.getUsuario().getPontoChance().getQuantidade();
            
            try
            {
                BufferedReader br = new BufferedReader(new FileReader(arquivo));
                StringBuilder sb = new StringBuilder();
                String linha;
                boolean linhaEncontrada = false;
                
                while((linha = br.readLine()) != null)
                {
                    if(linha.equals(conteudoBuscado))
                    {
                        sb.append(novoConteudo);
                        linhaEncontrada = true;
                    }
                    else
                    {
                       sb.append(linha);
                    }
                    sb.append(System.lineSeparator());
                }
                br.close();
                
                if(linhaEncontrada)
                {
                    BufferedWriter bw = new BufferedWriter(new FileWriter(arquivo));
                    bw.write(sb.toString());
                    bw.close();
                }
            }
            catch(IOException ex)
            {
                Logger.getLogger(TelaDificuldadeUI.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            new TelaPrincipalUI(jogoAtual).setVisible(true);
            dispose();
        }
        catch(NivelIndisponivelException  e)
        {
            JOptionPane.showMessageDialog(this,e.getMessage(),"Parabéns", JOptionPane.INFORMATION_MESSAGE);
        }
    }//GEN-LAST:event_jButton2ActionPerformed

    /**Essa action ocorrerá caso o usuário selecione o botão de dificuldade difícil. Nele, o índice da palavra que será jogada é escrito na linha do usuário logado.
     * 
     * @param evt Evento gerado caso o usuário clique no botão difícil.
     */
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed

        try
        {
            palavraAtual = jogoAtual.palavraJogo("difícil");
            jogoAtual.getPartida().setPalavra(palavraAtual);
            
            File arquivo = new File("C:\\Users\\Lara\\OneDrive\\Área de Trabalho\\Unesp\\3º Semestre\\POO\\JogoForca\\usuarios.txt");
            String conteudoBuscado = jogoAtual.getUsuario().getNome() + "#" + jogoAtual.getUsuario().getNomeUser() + "#" + jogoAtual.getUsuario().getEmail() + "#" + jogoAtual.getUsuario().getSenha() + "#";
            for(int i = 0; i< jogoAtual.getUsuario().getIndicesPalavras().size(); i++)
                conteudoBuscado += jogoAtual.getUsuario().getIndicesPalavras().get(i) + " ";
            conteudoBuscado += "#" + jogoAtual.getUsuario().getPontoDica().getQuantidade() + "#" + jogoAtual.getUsuario().getPontoChance().getQuantidade();
            
            for(int i = 0; i< jogoAtual.getPalavras().size(); i++)
            {
                if((jogoAtual.getPalavras().get(i).getPalavra()).equals(jogoAtual.getPartida().getPalavra().getPalavra()))
                {
                    jogoAtual.getUsuario().getIndicesPalavras().add(i);
                }
            }
            
            String novoConteudo = jogoAtual.getUsuario().getNome() + "#" + jogoAtual.getUsuario().getNomeUser() + "#" + jogoAtual.getUsuario().getEmail() + "#" + jogoAtual.getUsuario().getSenha() + "#";
            for(int i = 0; i< jogoAtual.getUsuario().getIndicesPalavras().size(); i++)
                novoConteudo += jogoAtual.getUsuario().getIndicesPalavras().get(i) + " ";
            novoConteudo += "#" + jogoAtual.getUsuario().getPontoDica().getQuantidade() + "#" + jogoAtual.getUsuario().getPontoChance().getQuantidade();
            
            try
            {
                BufferedReader br = new BufferedReader(new FileReader(arquivo));
                StringBuilder sb = new StringBuilder();
                String linha;
                boolean linhaEncontrada = false;
                
                while((linha = br.readLine()) != null)
                {
                    if(linha.equals(conteudoBuscado))
                    {
                        sb.append(novoConteudo);
                        linhaEncontrada = true;
                    }
                    else
                    {
                       sb.append(linha);
                    }
                    sb.append(System.lineSeparator());
                }
                br.close();
                
                if(linhaEncontrada)
                {
                    BufferedWriter bw = new BufferedWriter(new FileWriter(arquivo));
                    bw.write(sb.toString());
                    bw.close();
                }
            }
            catch(IOException ex)
            {
                Logger.getLogger(TelaDificuldadeUI.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            new TelaPrincipalUI(jogoAtual).setVisible(true);
            dispose();
        }
        catch(NivelIndisponivelException  e)
        {
            JOptionPane.showMessageDialog(this,e.getMessage(),"Parabéns", JOptionPane.INFORMATION_MESSAGE);
        }
    }//GEN-LAST:event_jButton3ActionPerformed

    /**Esse método será utilizado quando o botão com o ícone de sair for selecionado. Uma JOptionPane faz a confirmação se o usuário realmente deseja sair, e caso a resposta for afirmativa, o usuário será redirecionado para a tela inicial.
     * 
     * @param evt Evento gerado caso o usuário clique no botão com ícone de sair.
     */
    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed

        int op = JOptionPane.showConfirmDialog(this, "Deseja mesmo sair?", "Sair", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
        if(op == 0)
        {
            new TelaInicialUI().setVisible(true);
            dispose();
        }
    }//GEN-LAST:event_jButton4ActionPerformed

    
    /**Esse método será responsável por chamar a tela.
     * 
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TelaDificuldadeUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TelaDificuldadeUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TelaDificuldadeUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TelaDificuldadeUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaDificuldadeUI(jogoAtual).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
