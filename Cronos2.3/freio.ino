void brakes() {

  int frontal map(analogRead(), , , ) //fazer o tratamento da leitura para fazer a impressão
  int traseiro map(analogRead(), , , ) //Pode ser qualquer variavel

  if (Botâo && botaão2) {
    if (Pressão > analogRead()) {
      pressãoMaxima = analogRead()
    }
  }
  if (!digitalRead(botão2)) {
    flag = 1;  //pronto para ser solto
    if (!flagTemp) {
      flagTemp = 1;  //impede varias marcacoes de tempo
      tempo = millis();
    }
  }
  if (digitalRead(botão2) && flag) {
    flagTemp = flag = 0;
    total ++;
  }
  if (total == 1 && millis() - tempo > 1000) {
    imprime = 1;    
    total = 0;
  }

  if (total == 2 && millis() - tempo > 1000) {
    imprime = 2;
    total = 0;
  }
  if (total == 3 && millis() - tempo > 1000) {
    imprime = 3;
    total = 0;
  }
  
  switch (imprime) {
    case 1:
      freios.printDigit((frontal / (frontal + traseiro)) * 100)
      break;
    case 2:
      freios.printDigit(frontal/pressãoMaxima * 100);
      break;
    case 3:
      freios.printDigit(traseiro/pressãoMaxima * 100);
      break;
    default:
      freios.printDigit((frontal / (frontal + traseiro)) * 100)
      break;
  }

}
