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

