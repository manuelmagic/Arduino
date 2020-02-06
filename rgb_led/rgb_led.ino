/*Arduino Starter Kit - Project 4*/

const int greenLEDpin = 9;
const int blueLEDpin = 10;
const int redLEDpin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

char buffer[10];

void setup() {
  Serial.begin(9600);

  pinMode(redLEDpin, OUTPUT);
  pinMode(greenLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}

void loop() {
   redSensorValue = analogRead(redSensorPin);
   delay(5); // giving some time to the ADC
   greenSensorValue = analogRead(greenSensorPin);
   delay(5);
   blueSensorValue = analogRead(blueSensorValue);
   delay(5);

   /* improved indentation of the output using the function 
    * sprintf to format the values with fixed width */
   
   Serial.print("Raw sensor values \t red: ");
   sprintf(buffer, "%4d", redSensorValue);
   Serial.print(buffer);
   Serial.print("\t green: ");
   sprintf(buffer, "%4d", greenSensorValue);
   Serial.print(buffer);
   Serial.print("\t blue: ");
   sprintf(buffer, "%4d", blueSensorValue);
   Serial.println(buffer);

   /* from 1023 values to 255 values */
   redValue = redSensorValue / 4;
   greenValue = greenSensorValue / 4;
   blueValue = blueSensorValue / 4;

   Serial.print("Mapped sensor values \t red: ");
   sprintf(buffer, "%4d", redValue);
   Serial.print(buffer);
   Serial.print("\t green: ");
   sprintf(buffer, "%4d", greenValue);
   Serial.print(buffer);
   Serial.print("\t blue: ");
   sprintf(buffer, "%4d", blueValue);
   Serial.println(buffer);
   Serial.println();

   analogWrite(redLEDpin, redValue);
   analogWrite(greenLEDpin, greenValue);
   analogWrite(blueLEDpin, blueValue);

   delay(2000); // in order to read the output more comfortably on the serial monitor
}
