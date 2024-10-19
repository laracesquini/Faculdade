#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

// Função que desenha o cone
void drawCone() {
    glPushMatrix();   // Salva a matriz de transformação atual

    glRotatef(-90, 1, 0, 0);
    glColor3f(0.5, 0.0, 0.5);  // Define a cor do cone (roxo)
   
    glutSolidCone(0.5, 2.0, 20, 20);

    glLineWidth(1);
    glColor3f(0, 0, 0);
    glutWireCone(0.5, 2.0, 20, 20);
    glPopMatrix();   // Restaura a matriz de transformação anterior
}