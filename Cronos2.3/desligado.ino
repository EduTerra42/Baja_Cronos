void desliga() {

  crono.clear();
  freio.clear();
  digitalWrite(rgbG, HIGH);
  digitalWrite(rgbB, HIGH);
  digitalWrite(rgbR, LOW);

}

/*
  apaga todos os digitos e liga
  o led vermelho
*/
