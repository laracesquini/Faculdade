; Parte 1 - Variáveis DEFINIDAS na memória
section .data
    mensagem1 db "Digite alguma coisa: ", 0
    mensagem2 db "Você digitou: ", 0

; Parte 2 - Variáveis NÃO DEFINIDAS na memória
section .bss
    entrada resb 255 ; Espaço (buffer) reservado na memória para o texto digitado 

; Parte 3 - Código do Programa
section .text
global _start ; Seção "Main"
_start:
    
    ; Escrever (print) a mensagem no prompt
    mov EAX, 4
    mov EBX, 1
    mov ECX, mensagem1
    mov EDX, 21
    int 0x80
    
    ; Ler a entrada do teclado e gravar no buffer/memória
    mov EAX, 3
    mov EBX, 0
    mov ECX, entrada
    mov EDX, 255
    int 0x80
    
    ; Escrever a mensagem de saída
    mov EAX, 4
    mov EBX, 1
    mov ECX, mensagem2
    mov EDX, 14
    int 0x80
    
    ; Escrever a string digitada
    mov EAX, 4
    mov EBX, 1
    mov ECX, entrada
    mov EDX, 255
    int 0x80

    ; Encerra o programa
    mov     eax, 1 ; Atribuição do valor 1 ao registrador EAX
    int     0x80 ; Syscall - EXIT