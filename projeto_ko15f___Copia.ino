int releExaustor = 13;
int releGas = 12;
int torn = 11;
int ledchama = 10;
int centelha = 9;
bool sequenciaIniciada = false;

void setup() {
  pinMode(releExaustor, OUTPUT);
  pinMode(releGas, OUTPUT);
  pinMode(torn, INPUT_PULLUP);
  pinMode(ledchama, OUTPUT);
  pinMode(centelha, OUTPUT);

  apagarTudo();
}

void loop() {
  if (digitalRead(torn) == LOW && !sequenciaIniciada) {
    sequenciaIniciada = true;

    // Passo 1: Liga exaustor
    digitalWrite(releExaustor, HIGH);
    delay(2000);

    // Confirma que o botão ainda está pressionado
    if (digitalRead(torn) == LOW) {
      // Passo 2: Liga centelha
      digitalWrite(centelha, HIGH);
      delay(1500);

      // Passo 3: Libera gás
      digitalWrite(releGas, HIGH);
      delay(1700);

      // Confirma novamente se o botão ainda está pressionado
      if (digitalRead(torn) == LOW) {
        // Passo 4: Desliga centelha e acende led da chama
        digitalWrite(ledchama, HIGH);
        delay(1700);
        digitalWrite(centelha, LOW);
        
      } else {
        apagarTudo();
      }
    } else {
      apagarTudo();
    }

  } else if (digitalRead(torn) == HIGH) {
    // Botão foi solto – reinicia flag e desliga tudo
    sequenciaIniciada = false;
    apagarTudo();
  }
}

void apagarTudo() {
  digitalWrite(releExaustor, LOW);
  digitalWrite(releGas, LOW);
  digitalWrite(centelha, LOW);
  digitalWrite(ledchama, LOW);
}
