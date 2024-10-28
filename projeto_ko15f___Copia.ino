int releExaustor = 13;
int releGas = 12;
int torn = 11;
int centelha = 9;
#define ldr A0
int vldr = 0;

void setup() {
  pinMode(releExaustor, OUTPUT);
  pinMode(releGas, OUTPUT);
  pinMode(torn, INPUT_PULLUP);
  pinMode(centelha, OUTPUT);
  pinMode(ldr, INPUT);

  digitalWrite(releExaustor, HIGH);
  digitalWrite(releGas, HIGH);
}

void loop() {
  if (digitalRead(torn) == HIGH && vldr == 0) {
    digitalWrite(releExaustor, LOW);
    delay(2000);

    if (digitalRead(torn) == HIGH && vldr == 0) {
      digitalWrite(releExaustor, LOW);
      digitalWrite(centelha, LOW);
      delay(1500);
      digitalWrite(releGas, LOW);
      delay(1700);

      if (digitalRead(torn) == HIGH && vldr > 4) {
        digitalWrite(releExaustor, LOW);
        digitalWrite(releGas, LOW);
        digitalWrite(centelha, HIGH);

      } else {
        digitalWrite(releExaustor, HIGH);
        digitalWrite(releGas, HIGH);
      }
    } else {
      digitalWrite(releExaustor, HIGH);
      digitalWrite(releGas, HIGH);
    }
  } else {
    digitalWrite(releExaustor, HIGH);
    digitalWrite(releGas, HIGH);
  }
}
