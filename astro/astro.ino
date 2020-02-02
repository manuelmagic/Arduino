/*Arduino Starter Kit - Project 2*/

int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH);  // accendo LED verde
    digitalWrite(4, LOW);   // spengo LED rossi
    digitalWrite(5, LOW);   // ...
  }
  else {
    digitalWrite(3, LOW);   // spengo LED verde
    digitalWrite(4, LOW);   // accendo uno dei due LED rossi
    digitalWrite(5, HIGH);  // ...
    delay(250);
    digitalWrite(4, HIGH);  // inverto lo stato dei LED rossi
    digitalWrite(5, LOW);   // ...
    delay(250);
  }
}
