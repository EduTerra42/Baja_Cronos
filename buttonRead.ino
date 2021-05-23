void buttonRead() {

  if (!digitalRead(botao)) {
    flagBot = 1;  //pronto para ser solto
    if (!flagBotTemp) {
      flagBotTemp = 1;  //impede varias marcacoes de tempo
      TempBot = millis();
    }
  }
  if (digitalRead(botao) && flagBot) {
    flagBotTemp = flagBot = 0;  //libera para ser pressionado outra vez
    if (millis() - TempBot < 3000 && millis() - TempBot > 1000) {
      reinicia();
    } else if (millis() - TempBot > 4000) {
      reinicia();
      botDesligado = !botDesligado;  //inverte se esta desligado ou ligado
    }
  }
  
}

/*
  basicamente interpreta o primeiro toque com o botao como uma marca
  a marca e usada para saber o tempo pressionado ate ser solto
  enquanto pressionado, reinicia o cronometro constantemente para
  sempre voltar a leitura na forma correta
*/
