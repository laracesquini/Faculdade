section .data 
    numero dd '5'
    mensagem1 db "Insira um número: ", 0
    mensagem2 db "O menor valor é: ", 0
    mensagem3 db "Os dois valores são iguais", 0

segment .bss
    menor_numero resb 1
    entrada resb 1

section .text
global _start
_start:

    mov eax, 4
    mov ebx, 1
    mov ecx, mensagem1
    mov edx, 19
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, entrada
    mov edx, 1
    int 0x80

    mov eax, [numero]
    mov ebx, [entrada]
    cmp eax, ebx

    je numeros_iguais
    jb numero1_e_menor
    jg numero2_e_menor

numero2_e_menor:
    mov [menor_numero], ebx
    jmp print

numero1_e_menor:
    mov [menor_numero], eax
    jmp print

numeros_iguais:
    mov eax, 4
    mov ebx, 1
    mov ecx, mensagem3
    mov edx, 27
    int 0x80
    jmp end

print:
    mov eax, 4
    mov ebx, 1
    mov ecx, mensagem2
    mov edx,18
    int 0x80
    jmp print2

print2:
    mov eax, 4
    mov ebx, 1
    mov ecx, menor_numero
    mov edx, 1
    int 0x80
    jmp end

end:
    mov eax, 1
    xor ebx, ebx
    int 0x80

