#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gateServo;

// Pin Definitions
const int trigPin = 5;
const int echoPin = 18;
const int irPin = 4;
const int servoPin = 13;

// Distance Thresholds (cm)
const int openDistance = 50;
const int closeDistance = 70;

// Servo Angles
const int closedAngle = 0;
const int openAngle = 90;

bool gateOpen = false;
unsigned long clearStartTime = 0;

// -------------------- HC-SR04 --------------------

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999;
  }

  return duration * 0.034 / 2;
}

// -------------------- Servo Animation --------------------

void openGate() {
  for (int pos = closedAngle; pos <= openAngle; pos++) {
    gateServo.write(pos);
    delay(15);
  }
}

void closeGate() {
  for (int pos = openAngle; pos >= closedAngle; pos--) {
    gateServo.write(pos);
    delay(15);
  }
}

// -------------------- Setup --------------------

void setup() {

  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);

  lcd.init();
  lcd.backlight();

  gateServo.attach(servoPin);
  gateServo.write(closedAngle);

  // Boot Screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello Cutie!");
  lcd.setCursor(0, 1);
  lcd.print("initializing");

  delay(2000);

  lcd.clear();
}

// -------------------- Main Loop --------------------

void loop() {

  long distance = getDistance();

  // Most Flying Fish IR sensors output LOW when object detected
  bool visitorDetected = (digitalRead(irPin) == LOW);

  // ---------------- CLOSED STATE ----------------

  if (!gateOpen) {

    lcd.setCursor(0, 0);
    lcd.print("Gate: CLOSED   ");

    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print(" cm   ");

    if (visitorDetected || distance <= openDistance) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Visitor Found");

      lcd.setCursor(0, 1);
      lcd.print("Opening Gate");

      openGate();

      gateOpen = true;
      clearStartTime = 0;

      delay(500);
      lcd.clear();
    }
  }

  // ---------------- OPEN STATE ----------------

  else {

    if (distance <= openDistance) {

      lcd.setCursor(0, 0);
      lcd.print("Gate: OPEN     ");

      lcd.setCursor(0, 1);
      lcd.print("Dist:");
      lcd.print(distance);
      lcd.print(" cm   ");

      clearStartTime = 0;
    }

    else {

      lcd.setCursor(0, 0);
      lcd.print("Path Clear     ");

      lcd.setCursor(0, 1);
      lcd.print("Dist:");
      lcd.print(distance);
      lcd.print(" cm   ");

      if (clearStartTime == 0) {
        clearStartTime = millis();
      }

      if (millis() - clearStartTime >= 3000) {

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Gate:CLOSING");

        lcd.setCursor(0, 1);
        lcd.print("Please Wait");

        closeGate();

        gateOpen = false;
        clearStartTime = 0;

        delay(500);
        lcd.clear();
      }
    }
  }

  delay(200);
}