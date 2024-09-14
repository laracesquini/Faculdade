// Configuração do pino 13 como saída

void setup() {

pinMode(13, OUTPUT); // Define o pino 13 como saída

}



// Loop principal

void loop() {

digitalWrite(13, HIGH); // Liga o LED (define o pino 13 como HIGH)

delay(1000); // Aguarda 1 segundo

digitalWrite(13, LOW); // Desliga o LED (define o pino 13 como LOW)

delay(1000); // Aguarda 1 segundo

}