#include <avr/io.h>

.global asmfunc

asmfunc:
    ; Recebe o número do botão em r24
    mov r20, r24          ; Copia o número do botão para r20

    ; Seleciona a ação com base no número do botão
    cpi r20, 1            ; Compara o número do botão com 1
    breq botao1           ; Se for 1, vai para a função botao1
    cpi r20, 2            ; Compara o número do botão com 2
    breq botao2           ; Se for 2, vai para a função botao2
    cpi r20, 3            ; Compara o número do botão com 3
    breq botao3           ; Se for 3, vai para a função botao3
    rjmp fim              ; Salta para o fim se nenhum botão corresponde

botao1:
	ldi r18, 255 ; Carrega o registrador r18 com 255
	ldi r19, 255 ; Carrega o registrador r19 com 255
	ldi r20, 255 ; Carrega o registrador r20 com 255
botao1_lop:
    sbi (PORTD-0x20), 7 ; Seta o bit 7 do PORTD 
	cbi (PORTD-0x20), 7 ; Limpa o bit 7 do PORTD 
	dec r18 ; Decrementa r18
	brne botao1_lop ; Se r18 não for zero, continua o loop
	dec r19 ; Decrementa r19
	brne botao1_lop ; Se r19 não for zero, continua o loop
	dec r20 ; Decrementa r20
	brne botao1_lop ; Se r20 não for zero, continua o loop
	ret

botao2:
	ldi r21, 20 ; Carrega o registrador r21 com 20
botao2_lop:
    sbi (PORTD-0x20), 7 ; Seta o bit 7 do PORTD 
	rcall delay_1 ; Vai para a função delay_1
	cbi (PORTD-0x20), 7 ; Limpa o bit 7 do PORTD )
	dec r21 ; Decrementa r21
	brne botao2_lop ; Se r21 não for zero, continua o loop
	ret

botao3:
	ldi r20, 255 ; Carrega o registrador r20 com 255
	ldi r21, 50 ; Carrega o registrador r21 com 50
botao3_lop:
    sbi (PORTD-0x20), 7 ; Seta o bit 7 do PORTD 
	rcall delay_3 ; Vai para a função delay_3
	cbi (PORTD-0x20), 7 ; Limpa o bit 7 do PORTD 
	rcall delay_3 ; Vai para a função delay_3
	dec r20 ; Decrementa r20
	brne botao3_lop ; Se r20 não for zero, continua o loop
	dec r21 ; Decrementa r21
	brne botao3_lop ; Se r21 não for zero, continua o loop
	ret

delay_1:
	ldi r18, 255 ; Carrega o registrador r18 com 255
	ldi r19, 255 ; Carrega o registrador r19 com 255
	ldi r20, 20 ; Carrega o registrador r20 com 20 
delay_loop:
	dec r18 ; Decrementa r18
	brne delay_loop ; Se r18 não for zero, continua o loop
	dec r19 ; Decrementa r19
	brne delay_loop ; Se r19 não for zero, continua o loop
	dec r20 ; Decrementa r20
	brne delay_loop ; Se r20 não for zero, continua o loop
	ret

delay_3:
	ldi r18, 10 ; Carrega o registrador r18 com 10
	ldi r19, 10 ; Carrega o registrador r19 com 10
delay_loop3:
	dec r18 ; Decrementa r18
	brne delay_loop3 ; Se r18 não for zero, continua o loop
	dec r19 ; Decrementa r19
	brne delay_loop3 ; Se r19 não for zero, continua o loop
	ret

fim:
    ret                   ; Retorna da função Assembly
