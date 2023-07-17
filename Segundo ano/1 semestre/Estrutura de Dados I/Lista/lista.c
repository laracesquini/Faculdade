#include <stdlib.h> //Para usar malloc, free, exit ...
#include <stdio.h>  //Para usar printf ,... 
#include <string.h> //Para trabalhar com strings
#include "lista.h"  //Carrega o arquivo .h criado

#define MAX 100    //estimativa do tamanho máximo da lista
#define TRUE 1     //define tipo boleano – não existe em C
#define FALSE 0
#define boolean int

//Implementação: lista seq.

//Operações
//-------------------------------------------
boolean Vazia(lista *L)
{
   //Retorna true (1): se vazia, false (0): caso contrário
   return (L->nelem == 0);
}

boolean Cheia(lista *L)
{
   //Retorna true (1): se cheia, false (0): caso contrário
   return (L->nelem == MAX);
}

void Definir(lista *L)
{
   /*Cria uma lista vazia. Este procedimento deve ser chamado
   para cada nova lista antes de qualquer outra operação.*/
   L->nelem = 0;
   L->A[0].chave = 0;
}

void Apagar(lista *L){
   //Apaga "logicamente" uma lista
   L->nelem = 0;
}

boolean Inserir_posic(tipo_elem x, int p, lista *L)
{
   /*Insere x, que é um novo elemento na posição p da lista
   Se L = a_1, a_2,... a_n então temos a_1, a_2, ... 
   a_{p-1}, x, a_{p+1}, ... an.
   Devolve true se sucesso, false c.c. (isto é: L não tem nenhuma 
   posição p ou lista cheia). Obs: Operação para LISTA NÃO-ORDENADA */
   
   int q;

   if (Cheia(L) || p > L->nelem+1 || p < 1)
   {
      //Lista cheia ou posição não existe
      return FALSE;
   } 
   else 
   {
      for(q = L->nelem; q>=p; q--) //Copia vizinho p/ direita
	     L->A[q+1] = L->A[q];
      
	  L->A[p] = x;
      L->nelem++;
      
	  return TRUE; //Inserção feita com sucesso
   }
}

int Buscar(tipo_chave x, lista *L)
{   
   /*Retorna true, se x ocorre na posição p. Se x ocorre mais de
   uma vez, retorna a posição da primeira ocorrência. Se x não
   ocorre, retorna false. Para listas NÃO-ORDENADAS*/

   if (!Vazia(L))
   {
      int i = 1;
      while (i <= L->nelem)
      {
         if (L->A[i].chave == x)
         {
            
            return i;
         } 
         else
         i++;
      }
   }
   return -1; //Retorna false se não encontrou
   
}

void Remover_posic(int p, lista *L)
{
   /*Só é ativada após a busca ter retornado a posição p
   do elemento a ser removido - Nro de Mov = (nelem – p)*/
   
   int i;
   
   for (i = p+1; i <= L->nelem; i++)
      L->A[i-1] = L->A[i];
   
   L->nelem--;
}

void Impr_elem(tipo_elem t)
{
   printf("chave: %d\n", t.chave);
   printf("nome: %s\n", t.info.nome);
   printf("idade: %d\n", t.info.idade);
   printf("media final: %4.2f\n", t.info.media_final);
   //... (demais dados)
}

void Imprimir(lista *L)
{
   //Imprime os elementos na sua ordem de precedência
   
   int i;
   
   if (!Vazia(L))
   {
      for (i = 1; i <= L->nelem; i++)
         Impr_elem(L->A[i]);
   }
}


int Tamanho(lista *L)
{
   //Retorna o tamanho da lista. Se L é vazia retorna 0
   
   return L->nelem;
}


//Implementações para listas ordenadas
//-------------------------------------------
boolean Inserir_ord(tipo_elem x, lista *L)
{
   /*Insere novo elemento de forma a manter a lista ordenada
   (crescente). Devolve true (se sucesso), false (c.c.)*/
   int i;
   boolean a;

   if(Cheia(L))
   {
    return FALSE;
   }
   else
   {
    if(Vazia(L))
    a = Inserir_posic(x, 1, L);
    else
    {
        i = 1;
        while(strcmp(L->A[i].info.nome, x.info.nome) < 0 && i <= L->nelem)
        i++;
        
        a = Inserir_posic(x, i, L);
    }
    
    return a;
    }
}

int Busca_bin(tipo_chave x, lista *L)
{
   /*Retorna em p a posição de x na lista ORDENADA e true. 
   //Se x não ocorre, retorna false*/
   
   //Implementação de busca binária
   int inf = 1;
   int sup = L->nelem;
   int meio;
   
   while (!(sup < inf))
   {
      meio = (inf + sup)/2;
      if (L->A[meio].chave == x)
	  {
       //Sai da busca
          return meio;
      } 
	  else 
	  {
         if (L->A[meio].chave < x)
            inf = meio+1;
         else
            sup = meio-1;
      }
   }
   return -1;
}

boolean Remover_ch(tipo_chave x, lista *L)
{
   /*Remoção dada a chave. Retorna true, se removeu, ou
   false, c.c.*/
   
   int *p;
   boolean removeu = FALSE;
   int result;

   result = Busca_bin(x, L);
   
   if (result != -1) //Procura via busca binária
   {        
       Remover_posic(result, L);
       removeu = TRUE;
   }
   
   return removeu;
}
//-------------------------------------------


