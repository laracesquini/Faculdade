# O que preciso saber

## Aula 30/07
* Exclusão Mútua
* Sincronismo
## Aula 05/08
* Algoritmo Tie Breaker
* Algoritmo Ticket
* Algoritmo da padaria
* Barreira de sincronismo:
  * Contadores
  * Flags e Coordenador
## Aula 06/08
* Barreira de sincronismo
  * Árvore
 * Barreiras simétricas
   * Borboleta
   * Disseminação
   * Problema de usar somente um conjunto de flags
## Aula 12/08
 * Como aplicar exclusão mútua usando os semáforos
## Aula 19/08
* O que são monitores
* Qual é sua estrutura
* Quais são suas propriedades
* Porque usar monitores ao invés de semáforos?
* Exclusão mútua em monitores
* Variáveis condicionais - operadores
* Políticas de sinalização
## Aula 20/08
* minrank(cv)
* wait(cv, rank)
* signal_all(cv)
* Algoritmo timer
* Algoritmo barbeiro
## Aula 26/08
* Porque ou outros algoritmos não funcionam com prioridades
* Primeira solução -> com request e release
* Porque essa solução não é boa
* Outra solução e seus benefícios
* Saber como funciona cada procedimento
## Aula 27/08
* Comunicação assíncrona
* Primitivas de comunicação
* Bufferização de caracteres
* Merge Sort
## Aula 03/09
* Comunicação síncrona
* O que é RPC
* Qual a estrutura do RPC
## Aula 16/09
* O que é rendezvous
* Pra que serve rendezvous
* Qual é sua estrutura e como funciona
# Coisas para NÃO ESQUECER
* Na declaração do monitor, não coloca parâmetros
* No monitor, não precisa de semaforos porque já garante exclusão mutua, mas no rpc pode ser que precise, se for modificar uma variável que vai ser acessada por vários processos
* Se for usar monitor, verificar se precisa ser variável condicional com prioridade ou não 

