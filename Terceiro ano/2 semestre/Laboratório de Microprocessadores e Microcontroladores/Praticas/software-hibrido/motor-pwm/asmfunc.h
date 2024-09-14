extern "C"                // Início de um bloco que indica que a ligação (linkage) das funções deve seguir o padrão C
{                        // Abre o bloco de código para definições externas

    void asmfunc(void);    // Declara a função asmfunc com retorno do tipo void e sem parâmetros. 
                          // Isso informa ao compilador que essa função está definida em outro lugar, 
                          // provavelmente em Assembly, e pode ser chamada a partir do código C/C++.

}                        // Fecha o bloco de código.
