# Rendezvous
## Estrutura
```
module nomeModule
  op nome_op_1(int params);
  op nome_op_2(int params);
body
  process servidor {
    while(true) {
      faz_alguma_coisa();
      in nome_op_1(param) and condicao -> //chama esse
        faz_algo();
      [] nome_op_2(param) anda condicao -> //ou esse
        faz_algo();
      ni
    }
  }
end nomeModulo
```
**SOMENTE O PROCESSO SERVIDOR DENTRO DO RENDEZVOUS**

Depois disso, pode ter outros processos clientes que vão chamar as operações exportadas.

Atende a chamada mais antiga
