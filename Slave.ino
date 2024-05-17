#include "LiquidCrystal_I2C.h"
#include "Wire.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
int relay = 8;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Disconnected");
}

void loop() {
  while (Serial.available() > 0) {
    lcd.setCursor(0, 0);
    lcd.print("Connected      "); 
    int identifier = Serial.read();
    Serial.println(identifier);

    if (identifier == 0) {
      digitalWrite(relay, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Water: Full    ");
    } else {
      digitalWrite(relay, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Water: Not Full");  
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Disconnected      ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(100); 
}
