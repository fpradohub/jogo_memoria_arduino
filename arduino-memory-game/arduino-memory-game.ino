// Jogo da Memória (Genius / Simon) para Arduino

// Pinos dos LEDs e Botões correspondentes
int leds[] = {2, 3, 4, 5};
int botoes[] = {10, 11, 12, 13};
int buzzer = 8;

// Frequências das notas de cada botão/LED (Dó, Ré, Mi, Fá)
int tons[] = {440, 523, 659, 784};

// Variáveis de controle do jogo
int sequencia[20];
int nivel = 0;

void setup() {
  // Inicialização de entradas e saídas
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT_PULLUP); // Resistor interno de pull-up ativo
  }
  
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(A0)); // Seed de aleatoriedade lendo porta analógica solta
  start();
}

void loop() {
  gerarSequencia();
  mostrarSequencia();

  // Verifica se o jogador acertou a sequência deste nível
  if (verificarJogada()) {
    delay(600);
    nivel++;
  } else {
    somErro();
    nivel = 0;
    delay(1200);
  }
}

// Gera a próxima nota aleatória da sequência
void gerarSequencia() {
  sequencia[nivel] = random(0, 4);
}

// Pisca os LEDs e toca os tons na sequência gerada
void mostrarSequencia() {
  for (int i = 0; i <= nivel; i++) {
    tocarLED(sequencia[i], 350);
    delay(200);
  }
}

// Ativa o LED e o som correspondente por um tempo determinado
void tocarLED(int indice, int tempo) {
  digitalWrite(leds[indice], HIGH);
  tone(buzzer, tons[indice]);
  delay(tempo);
  noTone(buzzer);
  digitalWrite(leds[indice], LOW);
}

// Aguarda e lê qual botão foi pressionado pelo jogador
int lerBotao() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(botoes[i]) == LOW) { // Botão pressionado vai para nível LOW
        tocarLED(i, 200);
        return i;
      }
    }
  }
}

// Compara as jogadas do usuário com a sequência armazenada
bool verificarJogada() {
  for (int i = 0; i <= nivel; i++) {
    int botao = lerBotao();
    if (botao != sequencia[i]) {
      return false;
    }
  }
  return true;
}

// Som e animação de erro (quando erra a rodada)
void somErro() {
  tone(buzzer, 200);
  delay(600);
  noTone(buzzer);
  start();
}

// Sequência inicial de inicialização/reset do jogo
void start() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
    tone(buzzer, tons[i]);
    delay(200);
    noTone(buzzer);
    digitalWrite(leds[i], LOW);
  }
  delay(1000);
}
