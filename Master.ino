const int FloatSensor = 2;

void setup() {
  Serial.begin(9600);
  pinMode(FloatSensor, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(FloatSensor);

  Serial.write(buttonState);
  delay(50);

}
