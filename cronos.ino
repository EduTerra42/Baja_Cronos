void cronos() {
  
  digitalWrite(rgbR, HIGH);
  seg = ((millis() - Tempo) / 1000);  //Tempo de compilacao desde a ultima marcacao e atribuida a seg

  if (seg > 59) {
    min++;
    Tempo = millis();  //Remarca o tempo para menor impresisao
    seg = 0;
    crono.printDigit(0, 1);  //Imprimir um zero na segunda posição
  }//Passagem de um minuto

  if (min > 59) {
    hora++;
    min = 0;
    crono.printDigit(0, 1);  //Imprimir zeros nas posições em branco
  }//Passagem de uma hora

  if (millis() - SegA > 1000) {
    SegA = millis();
    digitalWrite(rgbB, !digitalRead(rgbB));
  }//Controle da piscada do led

  crono.printDigit(seg);
  crono.printDigit(min, 2);
  //Impressao no modo precisao (m:ss) ou para tempos maiores (h:mm)
  
}

/*
  Controla todo o calculo do tempo e do led
  e a impressão dos valores nos displays pelos
  objetos da biblioteca
  calcula quando a diferença entre o fim do ultimo
  minuto e o atual momento e maior do que 59 segundos,
  quando isso ocorre, aumenta em um os minutos
  (faz o mesmo com horas)
*/
