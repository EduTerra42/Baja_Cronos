void reinicia() {
  
  digitalWrite(rgbB, HIGH);
  digitalWrite(rgbR, HIGH);
  digitalWrite(rgbG, LOW);
  delay(500);
  digitalWrite(rgbG, HIGH);


  Tempo = millis();  //Remarcacao do tempo para reiniciar

  crono.printDigit(0, 1);  //Ocupar os espacos brancos com zero

  SegA = millis();


  min = 0;
  hora = 0;
  
}

/*
  liga o led verde por um tempo para
  mostrar que reiniciou e fez uma nova
  marca para todos os tempos
*/
