void brakes() {

  float frontal = map(analogRead(A0),0 ,1023, 0, 5000);  //fazer o tratamento da leitura para fazer a impressão
  float traseiro = map(analogRead(A1),0 ,1023 ,0 ,5000 );  //precisa ser float
  float relecao;
  if (Botao && botao2) {
    if (PressaoMaxima < frontal + traseiro {  //so permite a mudança caso o novo valore seja maior que o antigo
      pressoMaxima = frontal + traseiro;
    }
  }
  if (!digitalRead(botao2)) {
    flag = 1;  //pronto para ser solto
    if (!flagTemp) {
      flagTemp = 1;  //impede varias marcacoes de tempo
      tempo = millis();
    }
  }
  if (digitalRead(botao2) && flag) {
    flagTemp = flag = 0;
    total ++;
  }
  /*
  outro caso posivel para o escopo dos imprime
  if (total == 1 && millis() - tempo > 1000) {
    imprime = 1;    
    cronos.write(Rel);
    total = 0;
  }else if (total == 2 && millis() - tempo > 1000) {
    imprime = 2;
    cronos.write(Rel);
    total = 0;
  }else if (total == 3 && millis() - tempo > 1000) {
    imprime = 3;
    cronos.write(Rel);
    total = 0;
  }
  */
  
  if(tempo - millis()>1000){
    switch (total){
      case 1:
        imprime = 1;
        cronos.write(/*R*/);
        cronos.write(/*E*/);
        cronos.write(/*L*/);
        delay(500);
        break;
      case 2:
        imprime = 2;
        cronos.write(3, /*F*/);
        cronos.write(2, /*R*/);
        cronos.write(1, /*O*/);
        delay(500);
        break;
      case 3:
        imprime = 3;
        cronos.write(3, /*T*/);
        cronos.write(2, /*R*/);
        cronos.write(1, /*A*/);
        delay(500);
        break;      
      default:
        imprime = 1;
        cronos.write(3, /*R*/);
        cronos.write(2, /*E*/);
        cronos.write(1, /*L*/);
        delay(500);
        break;
    }
    total = 0;
  }

  switch (imprime) {
    case 1:
      if(frontal != 0 || traseiro != 0){
        relacao = (frontal / (frontal + traseiro)) * 100;
      }
      freios.printDigit(rel);
      break;
    case 2:
      freios.printDigit(frontal/pressaoMaxima * 100);
      break;
    case 3:
      freios.printDigit(traseiro/pressaoMaxima * 100);
      break;
    default:
      freios.printDigit((frontal / (frontal + traseiro)) * 100)
      break;
  }

}
