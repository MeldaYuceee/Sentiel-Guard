#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define PIR_PIN 2
#define MIC_PIN A1  
#define LDR_PIN A0
#define RELAY_PIN 5
#define BUZZER_PIN 6
#define PIR_LED 7
#define MIC_LED 8
#define LDR_LED 9

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_LED, OUTPUT);
  pinMode(MIC_LED, OUTPUT);
  pinMode(LDR_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  bool motion = digitalRead(PIR_PIN);
  int micValue = analogRead(MIC_PIN);
  int light = analogRead(LDR_PIN);

  int micThreshold = 500; 
  bool sound = (micValue > micThreshold);

  String alertMessage = "";
  bool threatDetected = false;

  if (motion) {
    alertMessage += "Motion ";
    digitalWrite(PIR_LED, HIGH);
    threatDetected = true;
  } else {
    digitalWrite(PIR_LED, LOW);
  }

  if (sound) {
    alertMessage += "Sound ";
    digitalWrite(MIC_LED, HIGH);
    threatDetected = true;
  } else {
    digitalWrite(MIC_LED, LOW);
  }

  if (light > 500) {
    alertMessage += "Light ";
    digitalWrite(LDR_LED, HIGH);
    threatDetected = true;
  } else {
    digitalWrite(LDR_LED, LOW);
  }

  lcd.setCursor(0, 0);
  if (threatDetected) {
    lcd.print(alertMessage);
    int len = 16 - alertMessage.length();
    for (int i = 0; i < len; i++) lcd.print(" ");
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    lcd.print("No Threat       ");
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  lcd.setCursor(0, 1);
  lcd.print("Active           ");

  Serial.print("Mic: ");
  Serial.println(micValue);

  delay(100);
}
