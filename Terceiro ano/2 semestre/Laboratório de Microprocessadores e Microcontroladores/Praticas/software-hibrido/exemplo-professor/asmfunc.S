#include <avr/io.h>       ; Inclui o arquivo de cabeçalho com definições para registradores AVR

.global asmfunc           ; Declara a função asmfunc como global, tornando-a acessível por outros módulos

asmfunc:                  ; Define o ponto de entrada da função asmfunc

repete:                   ; Rótulo que marca o início de um loop infinito

    sbi (PORTD-0x20), 7   ; Define (set) o bit 7 no registrador PORTD, ligando o pino 7 (HIGH)

    cbi (PORTD-0x20), 7   ; Limpa (clear) o bit 7 no registrador PORTD, desligando o pino 7 (LOW)

    rjmp repete           ; Salta de volta para o rótulo 'repete', criando um loop infinito
