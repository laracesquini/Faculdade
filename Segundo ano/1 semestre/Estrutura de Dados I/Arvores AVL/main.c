#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//Dupla: Lara Cesquini Stopa e Laiza Lima Peria
int main()
{
    no *raiz = NULL;

    raiz = inserir(raiz, 800);
    raiz = inserir(raiz, 500);
    raiz = inserir(raiz, 400);
    raiz = inserir(raiz, 900);
    raiz = inserir(raiz, 850);
    raiz = inserir(raiz, 950);

    inOrder(raiz);
    printf("\n");

    raiz = remover(raiz, 400);
    raiz = remover(raiz, 500);

    inOrder(raiz);
}