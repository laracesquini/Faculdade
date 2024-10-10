#include <GL/glut.h>
#include "esferas.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // Biblioteca para carregar a imagem
#include <stdio.h>

GLuint texture;  // Variável global para armazenar a textura

// Implementação da função loadTexture
void loadTexture(const char *filename, GLuint *textureID) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
    
    if (data) {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;
        else {
            printf("Formato de imagem não suportado: %d canais\n", nrChannels);
            stbi_image_free(data);
            return;
        }
        
        glGenTextures(1, textureID);
        glBindTexture(GL_TEXTURE_2D, *textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        
        // Configura os parâmetros da textura
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        printf("Textura carregada com sucesso: %s (%d x %d)\n", filename, width, height);
    } else {
        printf("Falha ao carregar a textura: %s\n", filename);
    }
    stbi_image_free(data);  // Libera a memória alocada para a imagem
}

// Função para inicializar a textura da maçã
void initAppleTexture() {
    loadTexture("madeira.jpg", &texture);  // Carrega a textura a partir do arquivo
}

// Função para desenhar a maçã
void drawApple() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    GLUquadric *quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    glScalef(0.8, 0.9, 0.8);  // Achata para parecer mais com uma maçã
    gluSphere(quad, 0.6, 50, 50);  // Desenha a esfera texturizada
    gluDeleteQuadric(quad);

    glPopMatrix();
}
