/*Arduino Starter Kit - Project 3*/

const int sensorPin = A0;
const int baselineTemp = 20;

void setup() {
  Serial.begin(9600);

  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", voltage (V): ");
  Serial.print(voltage);

  /*TMP36 sensor returns 750mV at 25°C, 10mV for each 1°C => 0°C == 500mV */
  float temperature = (voltage - 0.5) * 100;
  Serial.print(", degrees (C): ");
  Serial.println(temperature);

  if (temperature < (baselineTemp + 2)) {
    // less than 2 degrees
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if ((temperature >= (baselineTemp + 2)) && (temperature < (baselineTemp + 4))) {
    // higher than 2 degrees and less than 4
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if ((temperature >= (baselineTemp + 4)) && (temperature < (baselineTemp + 6))) {
    // higher than 4 degrees and less than 6
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else {
    // higher than 6 degrees
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  delay(2000); // giving some time to the ADC
}
