# RPC
## Estrutura 
```
modulo nomeModulo
  op operacao_1(int params) return int;
  op operacao_2();
body
  declaração e inicialização de variáveis //[DIFERENÇA COM RENDEZVOUS, LÁ NÃO TEM ISSO]
  proc operacao_1(int params) return nome {
    faz_alguma_coisa();
  }
  proc operacao_2() {
    faz_algo();
  }
  process controler {
    while(true) {
      faz_algo();
    }
  }
end nomeModulo
```
* Mecanismo de comunicação, a sincronização entre o processo que chamou e o servidor é implícita
* O processo controlador não chama os procedimentos exportados, só faz um controle local com as variáveis declarada
* O modulo contém processos e procedimentos
* Quando uma chamada é feita, um novo processo servidor é criado para atende-la

## Formas de promover sincronização em módulos
1. Assumir que todos os processos do mesmo módulo executam em exclusão mútua, ou seja, no máximo um por vez está ativado. Para programar sincronização, podemos usar semáforos
2. Assumir que processos executam de forma concorrente e programar explicitamente a exclusão mutua e sincronização. Dessa forma, pode ser usado semáforos, monitores locais, rendezvous, etc.
