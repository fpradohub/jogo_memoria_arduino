# Jogo da Memória (Arduino Genius)

Uma versão simples do clássico jogo Genius (Simon) desenvolvida para a placa Arduino Uno. O jogo gera uma sequência de luzes e sons aleatórios que o jogador deve repetir pressionando botões correspondentes. A cada rodada vencida, o nível aumenta adicionando um novo passo na sequência.

---

## Componentes Utilizados
* 1x Arduino Uno (ou placa compatível)
* 4x LEDs (Cores variadas)
* 4x Botões (Push-buttons)
* 4x Resistores de 220 Ω (para os LEDs)
* 1x Buzzer passivo
* Protoboard e Jumpers de conexão

---

## Mapeamento de Pinos e Conexões

### LEDs
* **LED 1:** Pino 2 (Digital)
* **LED 2:** Pino 3 (Digital)
* **LED 3:** Pino 4 (Digital)
* **LED 4:** Pino 5 (Digital)
* *Nota: Todos os LEDs devem ter resistores limitadores de corrente conectados ao GND.*

### Botões
* **Botão 1 (Liga LED 1):** Pino 10 (Digital)
* **Botão 2 (Liga LED 2):** Pino 11 (Digital)
* **Botão 3 (Liga LED 3):** Pino 12 (Digital)
* **Botão 4 (Liga LED 4):** Pino 13 (Digital)
* *Nota: Os botões utilizam resistores internos de pull-up do Arduino (`INPUT_PULLUP`), portanto devem ser ligados diretamente entre o pino e o GND, sem resistores externos.*

### Buzzer e Outros
* **Buzzer:** Pino 8 (Digital)
* **Pino A0:** Deixado desconectado para servir de base de leitura flutuante para a inicialização do gerador aleatório (`randomSeed`).

---

## Como Carregar o Código

1. Certifique-se de ter o [Arduino IDE](https://www.arduino.cc/en/software) instalado.
2. Abra o arquivo `arduino-memory-game.ino`.
3. Conecte sua placa Arduino à porta USB do computador.
4. Selecione o modelo da placa (Arduino Uno) e a porta COM correspondente no menu Ferramentas.
5. Clique em **Carregar (Upload)** para compilar e enviar o código para a placa.
