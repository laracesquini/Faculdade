//Grupo: Amanda Prampero, Ana Beatriz Gomes Takehara, Heloísa Silveira Bula, Laiza Lima Peria, Lara Cesquini Stopa  
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Estrutura para representar o grafo bipartido
typedef struct {
    int numVertices;
    int matrizAdj[MAX_VERTICES][MAX_VERTICES];
} GrafoBipartido;

// Função para inicializar o grafo bipartido
void inicializarGrafo(GrafoBipartido* grafo, int numVertices) {
    grafo->numVertices = numVertices;

    // Inicializa a matriz de adjacência com zeros
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            grafo->matrizAdj[i][j] = 0;
        }
    }
}

// Função para adicionar uma aresta entre dois vértices do grafo bipartido
void adicionarAresta(GrafoBipartido* grafo, int vertice1, int vertice2) {
    grafo->matrizAdj[vertice1][vertice2] = 1;
    grafo->matrizAdj[vertice2][vertice1] = 1;
}

// Função para verificar se o grafo é bipartido
bool ehBipartido(GrafoBipartido* grafo) {
    int cor[MAX_VERTICES];
    for (int i = 0; i < grafo->numVertices; i++) {
        cor[i] = -1;
    }

    // Define a cor do primeiro vértice como 1
    cor[0] = 1;

    // Utiliza uma busca em largura para atribuir cores aos vértices
    for (int vertice = 0; vertice < grafo->numVertices; vertice++) {
        for (int vizinho = 0; vizinho < grafo->numVertices; vizinho++) {
            if (grafo->matrizAdj[vertice][vizinho] == 1 && cor[vizinho] == -1) {
                cor[vizinho] = 1 - cor[vertice];
            } else if (grafo->matrizAdj[vertice][vizinho] == 1 && cor[vizinho] == cor[vertice]) {
                return false; // Encontrou uma aresta entre vértices da mesma cor
            }
        }
    }
    return true; // O grafo é bipartido
}

int main() {
    int numVertices = 6;
    GrafoBipartido grafo;

    inicializarGrafo(&grafo, numVertices);

    adicionarAresta(&grafo, 0, 1);
    adicionarAresta(&grafo, 0, 2);
    adicionarAresta(&grafo, 1, 3);
    adicionarAresta(&grafo, 2, 4);
    adicionarAresta(&grafo, 3, 5);
    adicionarAresta(&grafo, 4, 5);
    
    if (ehBipartido(&grafo)) {
        printf("O grafo é bipartido.\n");
    } else {
        printf("O grafo não é bipartido.\n");
    }
}
