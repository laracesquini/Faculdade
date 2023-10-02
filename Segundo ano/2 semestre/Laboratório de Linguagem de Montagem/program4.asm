section .data
    numero1 dd '2'
    numero2 dd '3'
    mensagem1 db "O maior número é: ", 0
    mensagem2 db "Os dois números são iguais!", 0

segment .bss
    maior_numero resb 1

section .text
global _start
_start:

    mov eax, [numero1]
    mov ebx, [numero2]
    cmp eax, ebx ;comparar

    je numeros_iguais
    jg numero1_e_maior
    jb numero2_e_maior

numero2_e_maior:
    mov [maior_numero], ebx
    jmp print

numero1_e_maior:
    mov [maior_numero], eax
    jmp print

numeros_iguais:
    mov eax, 4
    mov ebx, 1
    mov ecx, mensagem2
    mov edx, 29
    int 0x80
    jmp end

print:
    mov eax, 4
    mov ebx, 1
    mov ecx, mensagem1
    mov edx, 20
    int 0x80
    jmp print2

print2:
    mov eax, 4
    mov ebx, 1
    mov ecx, maior_numero
    mov edx, 1
    int 0x80
    jmp end

end:
    mov eax, 1
    xor ebx, ebx
    int 0x80
