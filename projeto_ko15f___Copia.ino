int releExaustor = 13;
int releGas = 12;
int torn = 11;
int ledchama = 10;
int centelha = 9;
#define ldr A0

bool sequenciaIniciada = false;
int vldr = 0;  // Variável para armazenar valor do LDR

void setup() {
  pinMode(releExaustor, OUTPUT);
  pinMode(releGas, OUTPUT);
  pinMode(torn, INPUT_PULLUP);
  pinMode(ledchama, OUTPUT);
  pinMode(centelha, OUTPUT);
  pinMode(ldr, INPUT);

  Serial.begin(9600);

  apagarTudo();
}

void loop() {
  vldr = analogRead(ldr);         // Lê valor do LDR
  Serial.println(vldr);           // Exibe no monitor serial

  if (digitalRead(torn) == LOW && !sequenciaIniciada) {
    sequenciaIniciada = true;

    digitalWrite(releExaustor, HIGH);
    delay(2000);

    if (digitalRead(torn) == LOW) {
      digitalWrite(centelha, HIGH);
      delay(1500);

      digitalWrite(releGas, HIGH);
      delay(1700);

      if (digitalRead(torn) == LOW && vldr > 100) {
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
    sequenciaIniciada = false;
    apagarTudo();
  }

  delay(100);  // Apenas para não sobrecarregar a leitura serial
}

void apagarTudo() {
  digitalWrite(releExaustor, LOW);
  digitalWrite(releGas, LOW);
  digitalWrite(centelha, LOW);
  digitalWrite(ledchama, LOW);
}
