section .data
    x db '5'
    y db '3'
    msg db "A soma de x e y é: "
    len equ $ - msg ;pega o comprimento da string

segment .bss
    sum resb 1

section .text
global _start
_start:

    mov eax, [x] ;eax pode ser minusculo ou maiusculo, tanto faz. Valor x vai para eax. []-> endereço. estou indo buscar a informação em algum lugar
    sub eax, '0' ;transforma a string '5' em int
    mov ebx, [y]
    sub ebx, '0'
    add eax, ebx ;adiciono o conteúdo de eax a ebx e guarda em eax
    add eax, '0' ;resultado é inteiro também

    mov [sum], eax ;coloca o resultado em sum. Coloca em sum porque vou precisar do eax para outra coisa 

    mov ecx, msg
    mov edx, len
    mov ebx, 1
    mov eax, 4
    int 0x80

    mov ecx, sum
    mov edx, 1
    mov ebx, 1
    mov eax, 4
    int 0x80

    mov eax, 1
    int 0x80