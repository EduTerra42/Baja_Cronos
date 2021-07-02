void brakes() {

  float frontal map(analogRead(), , , )  //fazer o tratamento da leitura para fazer a impressão
  float traseiro map(analogRead(), , , )  //precisa ser float

  if (Botâo && botaão2) {
    if (PressãoMaxima < analogRead()+analogRead()/*frontal + traseiro*/) {  //so permite a mudança caso o novo valore seja maior que o antigo
      pressãoMaxima = analogRead()+analogRead()/*frontal + traseiro*/;
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
  }else if (total == 2 && millis() - tempo > 1000) {
    imprime = 2;
    total = 0;
  }else if (total == 3 && millis() - tempo > 1000) {
    imprime = 3;
    total = 0;
  }
  /*
  outro caso posivel para o escopo dos imprime
  if(tempo - millis()>1000){
    switch (total){
      case 1:
        imprime´= 1;
        break;
      case 2:
        imprime´= 2;
        break;
      case 3:
        imprime´= 3;
        break;      
      default:
        imprime´= 1;
        break;
    }
    total = 0;
  }
  */
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
