%{
int linhas=1, erros=0;
%}

/* Definição de padrões (macros) */
DIGITO      [0-9]                    
ID          [A-Za-z][A-Za-z0-9áéíóúÁÉÍÓÚàèìòùÀÈÌÒÙâêîôûÂÊÎÔÛãõÃÕ]*     
ESPACO      [ \t\r]                
OPERADORES  [-*/+%] 
RELACIONAIS [><=]                                                            
SEPARADORES [\[\](){},;#!&|'_:.]                                    
%%

 /*Regras de análise léxica */

{ESPACO}  /* Ignora espaços em branco */

{DIGITO}+{ID} {
    /* Reconhece erro ao declarar identificador, como "123abc" */
    printf("Identificador inválido: %s - ", yytext);
    erros++;
    printf("Linha: %d\n", linhas);
}

{ID}{DIGITO}*{ID}* {
    /* Reconhece identificador válido */
    printf("Identificador: %s\n", yytext);
}

{DIGITO}+ {
    /* Reconhece números inteiros */
    printf("Inteiro: %s\n", yytext);
}

{DIGITO}+"."{DIGITO}+ {
    /* Reconhece números reais */
    printf("Real: %s\n", yytext);
}

{OPERADORES} {
    /* Reconhece operadores matemáticos, como "+" ou "*" */
    printf("Operador matemático: %s\n", yytext);
}

{SEPARADORES} {
    /* Reconhece separadores, como "()" ou "{}" */
    printf("Separador: %s\n", yytext);
}

{RELACIONAIS} {
    /* Reconhece operadores relacionais, como ">" ou "=" */
    printf("Operador relacional: %s\n", yytext);
}


{DIGITO}+","{DIGITO}+ {
    /* Reconhece erro ao declarar um número float com ",", como "9,7"*/
    printf("Número inválido: %s - ", yytext);
    erros++;
    printf("Linha: %d\n", linhas);

}

\" {
    /* Reconhece aspa dupla */
    printf("Separador: %s\n", yytext);
}

\\ {
    /* Reconhece contra barra*/
    printf("Separador: %s\n", yytext);
}

"//"[^\n]* {
    /* Reconhece comentários de uma linha, como "// comentário" */
    printf("Comentários\n");
}

\é|\É|\à|\À|\á|\Á {
 /* Reconhece identificador válido */
    printf("Identificador: %s\n", yytext);
}

\n {
    /* Incrementa a contagem de linhas */
    linhas++;
}

. {
    /* Qualquer coisa que não seja uma regra válida é um token inválido */
    printf("Símbolo não idenficado: %s - ", yytext);
    erros++;
    printf("Linha: %d\n", linhas);
}

%%

/* Função principal e de wrap-up */
int yywrap();

main() {
    yylex();
    printf("Total de erros encontrados: %d\n", erros);
    if (erros == 0)
        puts("\nCódigo analisado com sucesso!\n");
}

int yywrap() {
    return 1;
}

