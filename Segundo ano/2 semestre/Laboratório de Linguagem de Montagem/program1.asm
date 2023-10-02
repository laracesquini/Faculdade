section .data
    hello db 'Hello, World!',0xa    ; String a ser apresentada no terminal
    hello_len equ $ - hello       ; Comprimento da string

section .text
    global _start
_start:

    mov eax, 4 ; Registrador EAX recebe o valor 4
    mov ebx, 1 ; Registrador EBX recebe o valor 1

    mov ecx, hello ; Registrador ECX recebe a String
    mov edx, hello_len ; Registrador EDX recebe o comprimento da String
    int 0x80 ; Chamada da SysCall 4 (Responsável pela escrita) chama tudo o que foi escrito

    mov eax, 1 ; Registrador EAX recebe o valor 1, responsável pelo encerramento do programa
    xor ebx, ebx  ; Exit status (0)
    int 0x80; Chamada da Syscall 1, presdente no registrador EAX

    //duas chamadas de sistema. Um para aprender a mensagem e outra para encerrar