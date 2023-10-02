; Parte 1 - Variáveis DEFINIDAS na memória
section .data
    mensagem1 db "digite alguma coisa: ", 0
    mensagem2 db "VocÃª digitou: ", 0

; Parte 2 - Variáveis NÃO DEFINIDAS na memória
section .bss
    entrada resb 255 ;resb - reserva um espaÃ§o de buffer

section .text
global _start
_start:

    ;printar a mensagem
    mov EAX, 4
    mov EBX, 1
    mov ECX, mensagem1
    mov EDX, 21 ;comprimento da string. pPoderia colocar mensagem1_len -> se eu mudar a frase, nÃ£o preciso mudar aqui manualamente
    int 0x80 ;syscall -> analisa o estado do processador, e executa a funÃ§Ã£o

    ;Ler a entrada do teclado e gravar no buffer
    mov EAX, 3
    mov EBX, 0 ;0 -> nÃ£o faÃ§a nada
    mov ECX, entrada ;recebe a entrada do teclado e grava na variÃ¡vel 
    mov EDX, 255
    int 0x80

    ;Escrever a mensagem de saÃ­da
    mov EAX, 4
    mov EBX, 1
    mov ECX, mensagem2
    mov EDX, 14
    int 0x80

    mov EAX, 4
    mov EBX, 1
    mov ECX, entrada
    mov EDX, 255
    int 0x80

    mov     eax, 1
    int     0x08