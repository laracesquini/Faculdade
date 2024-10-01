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

void vermelho_semC()
{
  digitalWrite(semCverm, HIGH);
  digitalWrite(semCverd, LOW);
}

void verde_semC()
{
  digitalWrite(semCverm, LOW);
  digitalWrite(semCverd, HIGH);
}

void vermelho_semD()
{
  digitalWrite(semDverm, HIGH);
  digitalWrite(semDverd, LOW);
}

void verde_semD()
{
  digitalWrite(semDverm, LOW);
  digitalWrite(semDverd, HIGH);
}

void acende_amarelo_A_B()
{
  digitalWrite(semAverm, LOW);
  digitalWrite(semAamar, HIGH);
  digitalWrite(semAverd, LOW);

  digitalWrite(semBverm, LOW);
  digitalWrite(semBamar, HIGH);
  digitalWrite(semBverd, LOW);

  digitalWrite(semCverm, LOW);
  digitalWrite(semCverd, LOW);

  digitalWrite(semDverm, LOW);
  digitalWrite(semDverd, LOW);
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

void desliga_C_D()
{
  digitalWrite(semCverm, LOW);
  digitalWrite(semCverd, LOW);

  digitalWrite(semDverm, LOW);
  digitalWrite(semDverd, LOW);
}

int n = 0; // Variável para controlar o loop
int tempo(int N) {
  int B1 = HIGH, B2 = HIGH, B3 = HIGH;
    for(int i = 1; i <= N; i++) { 
      B1 = digitalRead((Bot_S1)); 
      B2 = digitalRead((Bot_S2)); 
      B3 = digitalRead((Bot_S3)); 
      if(B1 == LOW || B2 == LOW || B3 == LOW) {  // Verifica se o botão 2 foi pressionado
            n++;         // Incrementa a variável de controle
            break;       // Sai do loop
        } 
        else delay(1); // Aguarda 1 milissegundo
    }

    if(B1 == LOW)
    {
      return 1;
    }
    else if(B2 == LOW)
    {
      return 2;
    }
    else if(B3 == LOW)
    {
      return 3;
    }
    else
    {
      return 0;
    }
}

int tempo2(int N) {
  int B1 = HIGH, B3 = HIGH;
    for(int i = 1; i <= N; i++) { 
      B1 = digitalRead((Bot_S1)); 
      B3 = digitalRead((Bot_S3)); 
      if(B1 == LOW || B3 == LOW) {  // Verifica se o botão 2 foi pressionado
            n++;         // Incrementa a variável de controle
            break;       // Sai do loop
        } 
        else delay(1); // Aguarda 1 milissegundo
    }

    if(B1 == LOW)
    {
      return 1;
    }
    else if(B3 == LOW)
    {
      return 3;
    }
    else
    {
      return 0;
    }
}

int tempo3(int N) {
  int B1 = HIGH, B2 = HIGH;
    for(int i = 1; i <= N; i++) { 
      B1 = digitalRead((Bot_S1)); 
      B2 = digitalRead((Bot_S2)); 
      if(B1 == LOW || B2 == LOW) {  // Verifica se o botão 2 foi pressionado
            n++;         // Incrementa a variável de controle
            break;       // Sai do loop
        } 
        else delay(1); // Aguarda 1 milissegundo
    }

    if(B1 == LOW)
    {
      return 1;
    }
    else if(B2 == LOW)
    {
      return 2;
    }
    else
    {
      return 0;
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

int botao = 0; //nenhum botão pressionado
void loop() {
  if(botao == 0)
  {
    while(true)
    {
      vermelho_semA();
      verde_semB();
      verde_semC();
      vermelho_semD();
      botao = tempo(8000);
      if(n != 0) 
      {
        n = 0;
        break;
      }
    
      vermelho_semA();
      amarelo_semB();
      verde_semC();
      vermelho_semD();
      botao = tempo(2000);
      if(n != 0) 
      {
        n = 0;
        break;
      }

      verde_semA();
      vermelho_semB();
      vermelho_semC();
      verde_semD();
      botao = tempo(8000);
      if(n != 0) 
      {
        n = 0;
        break;
      }

      amarelo_semA();
      vermelho_semB();
      vermelho_semC();
      verde_semD();
      botao = tempo(2000);
      if(n != 0) 
      {
        n = 0;
        break;
      }
    }
  }

  if(botao == 1)
  {
    while(true)
    {
      acende_amarelo_A_B();
      botao = tempo(1000);
      if(n != 0) 
      {
        n = 0;
        botao = 0;
        break;
      }
      desliga();
      botao = tempo(1000);
      if(n != 0) 
      {
        n = 0;
        botao = 0;
        break;
      }
    }
  }

  if(botao == 2)
  {
    botao = tempo2(4000);
    if(botao == 0) //nenhum botão pressionado durante os 4 segundos
    {
      vermelho_semA();
      verde_semB();
      verde_semC();
      vermelho_semD();
      botao = tempo(5000);
      if(n != 0)
      {
        n = 0;
      }
    }
    else
    {
      n = 0;
    } 
  }

  if(botao == 3)
  {
    botao = tempo3(4000);
    if(botao == 0)
    {
      vermelho_semB();
      verde_semA();
      vermelho_semC();
      verde_semD();
      botao = tempo(5000);
      if(n != 0)
      {
        n = 0;
      }
    }
    else
    {
      n = 0;
    }  
  }  
}
