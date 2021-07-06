//**   Display e seus objetos   **//
#include "DigitLedDisplay.h"  //Biblioteca usada
//11 6 13 => MOSI, Control., SCK
#define MOSI 11
#define control 6
#define SCK 13
DigitLedDisplay crono = DigitLedDisplay(MOSI, control, SCK);  //Objeto usado para controlar o cronometro 
DigitLedDisplay freio = DigitLedDisplay(MOSI, control, SCK);  //Objeto usado para controlar a porcentagem dos freios

//**    Variaveis e controle de tempo   **//
unsigned long Tempo;  //Variavel de marcacao de tempo
unsigned long SegA = 0;  //Variavel de segundos

static int min, seg, hora = 0;  //controle de impressao


//**    Botoes e suas funcoes    **//
#define botao 5  //Porta do botao do cronometro
bool flagBot = 0;  //testa se o botao ja foi pressionado
bool flagBotTemp = 0;  //determina se o tempo ja foi marcado
unsigned long TempBot = 0;  //determina ha quanto tempo foi apertado
bool botDesligado = 0;  //variavel de controle para saber se o modo esta desligado

#define botao2 6  //porta do botao de freios
float frontal, traseiro, relacao;  //variaveis de impressao e controle dos freios
float pressaoMaxima;  //variavel de controle dos freios
bool flagBot2 = 0;  //testa se o botao ja foi pressionado
bool flagBot2Temp = 0;  //determina se o tempo ja foi marcado
unsigned long TempBot2 = 0;  //determina ha quanto tempo foi apertado
int total = 0;  //contagem de cliques
int imprime = 0;  // determina qual valor que vai ser impresso

//**    Rgb entradas    **//
#define rgbR 2
#define rgbG 3
#define rgbB 4


void setup() {

  crono.setBright(10);
  crono.setDigitLimit(3);  //Configuracao do objeto

  freio.setBright(10);
  freio.setDigitLimit(5);  //Configuracao do objeto

  pinMode(botao, INPUT_PULLUP);  //Configuracao do botao com resistor interno

  pinMode(rgbR, OUTPUT);  //Configuracao do led Vermelho
  digitalWrite(rgbR, HIGH);  //inicia a porta ligada
  pinMode(rgbG, OUTPUT);  //Configuracao do led Verde
  digitalWrite(rgbG, HIGH);  //inicia a porta ligada
  pinMode(rgbB, OUTPUT);  //Configuracao do led Azul
  digitalWrite(rgbB, HIGH);  //inicia a porta ligada

  crono.printDigit(0, 1);  //Ocupar os espacos brancos com zero

  Tempo = millis();  //Primeira marca do tempo
}

void loop() {
  buttonRead();
  if (botDesligado) {
    cronos();
  } else {
    desliga();
  }
}
