// Definições dos pinos dos LEDs do semáforo A (verde, amarelo, vermelho)
#define semAverm 2    // LED vermelho do semáforo A no pino 2
#define semAamar 5    // LED amarelo do semáforo A no pino 5
#define semAverd 18   // LED verde do semáforo A no pino 18

// Definições dos pinos dos LEDs do semáforo B (verde, amarelo, vermelho)
#define semBverm 19    // LED vermelho do semáforo B no pino 19
#define semBamar 21   // LED amarelo do semáforo B no pino 21
#define semBverd 22   // LED verde do semáforo B no pino 22

// Definições dos pinos dos LEDs do semáforo C (vermelho, verde)
#define semCverm 23    // LED vermelho do semáforo C no pino 23  
#define semCverd 32   // LED verde do semáforo C no pino 32

// Definições dos pinos dos LEDs do semáforo D (vermelho, verde)
#define semDverm 33    // LED vermelho do semáforo D no pino 33  
#define semDverd 25   // LED verde do semáforo D no pino 25

// Definições dos pinos dos botões
#define Bot_S1 26       // Botão S1 no pino 26
#define Bot_S2 27       // Botão S2 no pino 27
#define Bot_S3 14       // Botão S3 no pino 14

void vermelho_semA()
{
  digitalWrite(semAverm, HIGH);
  digitalWrite(semAamar, LOW);
  digitalWrite(semAverd, LOW);
}

void amarelo_semA()
{
  digitalWrite(semAverm, LOW);
  digitalWrite(semAamar, HIGH);
  digitalWrite(semAverd, LOW);
}

void verde_semA()
{
  digitalWrite(semAverm, LOW);
  digitalWrite(semAamar, LOW);
  digitalWrite(semAverd, HIGH);
}

void vermelho_semB()
{
  digitalWrite(semBverm, HIGH);
  digitalWrite(semBamar, LOW);
  digitalWrite(semBverd, LOW);
}

void amarelo_semB()
{
  digitalWrite(semBverm, LOW);
  digitalWrite(semBamar, HIGH);
  digitalWrite(semBverd, LOW);
}

void verde_semB()
{
  digitalWrite(semBverm, LOW);
  digitalWrite(semBamar, LOW);
  digitalWrite(semBverd, HIGH);
}

void acende_amarelo_A_B()
{
  digitalWrite(semAverm, LOW);
  digitalWrite(semAamar, HIGH);
  digitalWrite(semAverd, LOW);

  digitalWrite(semBverm, LOW);
  digitalWrite(semBamar, HIGH);
  digitalWrite(semBverd, LOW);
}

void desliga()
{
  digitalWrite(semAverm, LOW);
  digitalWrite(semAamar, LOW);
  digitalWrite(semAverd, LOW);

  digitalWrite(semBverm, LOW);
  digitalWrite(semBamar, LOW);
  digitalWrite(semBverd, LOW);
}

int n = 0; // Variável para controlar o loop
void tempo(int N) {
    for(int i = 1; i <= N; i++) {  // Executa um loop 'for' para contar o tempo
      if(digitalRead(Bot_S1) == LOW ) {  // Verifica se o botão 2 foi pressionado
            n++;         // Incrementa a variável de controle
            break;       // Sai do loop
        } 
        else delay(1); // Aguarda 1 milissegundo
    }
}

void setup() {
  pinMode(semAverm, OUTPUT);
  pinMode(semAamar, OUTPUT);
  pinMode(semAverd, OUTPUT);

  pinMode(semBverm, OUTPUT);
  pinMode(semBamar, OUTPUT);
  pinMode(semBverd, OUTPUT);

  pinMode(semCverm, OUTPUT);
  pinMode(semCverd, OUTPUT);

  pinMode(semDverm, OUTPUT);
  pinMode(semDverd, OUTPUT);

  pinMode(Bot_S1, INPUT);
  pinMode(Bot_S2, INPUT);
  pinMode(Bot_S3, INPUT);
}

void loop() {
    while(true)
    {
      vermelho_semA();
      verde_semB();
      tempo(8000);
      if(n != 0) 
      {
        n = 0;
        break;
      }
    
      vermelho_semA();
      amarelo_semB();
      tempo(2000);
      if(n != 0) 
      {
        n = 0;
        break;
      }

      verde_semA();
      vermelho_semB();
      tempo(8000);
      if(n != 0) 
      {
        n = 0;
        break;
      }

      amarelo_semA();
      vermelho_semB();
      tempo(2000);
      if(n != 0) 
      {
        n = 0;
        break;
      }
    }
    
    while(true)
    {
      acende_amarelo_A_B();
      tempo(1000);
      if(n != 0) 
      {
        n = 0;
        break;
      }
      desliga();
      tempo(1000);
      if(n != 0) 
      {
        n = 0;
        break;
      }
    }
}
