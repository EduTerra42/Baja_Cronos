void brakes() {
  frontal = map(analogRead(portFront), 0, 1023, 0, 3000);
  traseiro = map(analogRead(portTras), 0, 1023, 0, 3000);
//  rel = (frontal/(frontal+traseitro))*100;
//  crono.write(rel)
  
/*
  frontal = map(analogRead(A0),0 ,1023, 0, 5000);  //fazer o tratamento da leitura para fazer a impressão
  traseiro = map(analogRead(A1),0 ,1023 ,0 ,5000 );  //precisa ser float

  if (botao && botao2) {
    if (pressaoMaxima < frontal + traseiro) {  //so permite a mudança caso o novo valore seja maior que o antigo
      pressaoMaxima = frontal + traseiro;
    }
  }
  if (!digitalRead(botao2)) {
    flagBot2 = 1;  //pronto para ser solto
    if (!flagBot2Temp) {
      flagBot2Temp = 1;  //impede varias marcacoes de tempo
      TempBot2 = millis();
    }
  }
  if (digitalRead(botao2) && flagBot2) {
    flagBot2Temp = flagBot2 = 0;
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
  /*
  if(TempBot2 - millis()>1000){
    switch (total){
      case 1:
        imprime = 1;
        crono.write(3, 0x77);//(B01110111)
        crono.write(2, 0x79);//(B01111001)
        crono.write(1, 0x38);//(B00111000)
        delay(500);
        break;
      case 2:
        imprime = 2;
        crono.write(3, 0x71);//(B01110001)
        crono.write(2, 0x38);//(B01110111)
        crono.write(1, 0x3F);//(B00111111)
        delay(500);
        break;
      case 3:
        imprime = 3;
        crono.write(3, 0x31);//(B00110001)
        crono.write(2, 0x38);//(B01110111)
        crono.write(1, 0x38);//(B01110111)
        delay(500);
        break;      
      default:
        imprime = 1;
        crono.write(3, 0x77);//(B01110111)
        crono.write(2, 0x79);//(B01111001)
        crono.write(1, 0x38);//(B00111000)
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
      freio.printDigit(relacao);
      break;
    case 2:
      freio.printDigit(frontal/pressaoMaxima * 100);
      break;
    case 3:
      freio.printDigit(traseiro/pressaoMaxima * 100);
      break;
    default:
      freio.printDigit((frontal / (frontal + traseiro)) * 100);
      break;
  }
*/
}
