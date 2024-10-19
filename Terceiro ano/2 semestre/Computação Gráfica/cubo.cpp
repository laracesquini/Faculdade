#include <GL/glut.h>
#include "cubo.h"

void DesenhaCubo() {
    glLineWidth(1);
    glutSolidCube(1);

    glLineWidth(1);
    glColor3f(0, 0, 0);
    glutWireCube(1);
}

void DesenhaCenario(bool desenha) {
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, -1.0f);
    glColor3f(1, 0, 1);
    DesenhaCubo();
    glPopMatrix();
}
