
typedef struct no
{
    int info;
    int altura;
    struct no *dir;
    struct no *esq;
} no;

//Função para calcular a altura da árvore
int altura(no *raiz);
//Função que retorna o maior entre dois elementos
int maior(int x, int y);
//Função que calcula o menor elemento da árvore
no *menor(no *raiz);
//Função que cria um novo nó
no *criar_raiz(int elem);
//Função que faz a rotação para a direita
no *rotacaoDireita(no *raiz);
//Função que faz a rotação para a esquerda
no *rotacaoEsquerda(no *raiz);
//Função que calcula o fator de balanceamento
int fator_balanceamento(no *raiz);
//Função para inserir um novo elemento
no *inserir(no *raiz, int elem);
//Função para remover um elemento
no *remover(no *raiz, int elem);
//Função para percorrer a árvore 
void inOrder(no *raiz);