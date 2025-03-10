#include <Servo.h>

// Definire pini
const int trigPin = 9;
const int echoPin = 10;
const int redLed = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int servoPin = 6;

// Instanțiere servomotor
Servo barrierServo;

// Variabile pentru distanță
long duration;
int distance;

void setup() {
  // Configurare pini
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  // Inițializare servomotor
  barrierServo.attach(servoPin);
  barrierServo.write(0); // Bariera începe coborâtă

  Serial.begin(9600);
}

void loop() {
  // Măsurare distanță
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Conversie în cm

  Serial.println(distance);

  if (distance > 0 && distance <= 20) {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH); // Aprinde LED galben pentru ridicare

    // Ridicare barieră lentă
    moveBarrierSlowly(0, 90, 10); // Mișcare lentă în 10ms pași între 0° și 90°

    digitalWrite(yellowLed, LOW); // Stinge LED galben după ridicare
    digitalWrite(greenLed, HIGH); // Aprinde LED verde
    delay(5000); // Bariera rămâne ridicată 5 secunde

    digitalWrite(greenLed, LOW); // Stinge LED verde
    digitalWrite(yellowLed, HIGH); // Aprinde LED galben pentru coborâre

    // Coborâre barieră lentă
    moveBarrierSlowly(90, 0, 10); // Mișcare lentă în 10ms pași între 90° și 0°

    digitalWrite(yellowLed, LOW); // Stinge LED galben după coborâre
    digitalWrite(redLed, HIGH); // Aprinde LED roșu
  } else {
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);

    // Coborâre lentă a barierei, dacă nu este deja la 0°
    if (barrierServo.read() != 0) {
      digitalWrite(yellowLed, HIGH); // Aprinde LED galben pentru coborâre
      moveBarrierSlowly(barrierServo.read(), 0, 10); // Mișcare lentă între poziția curentă și 0°
      digitalWrite(yellowLed, LOW); // Stinge LED galben după coborâre
    }
  }

  delay(100); // Mică întârziere pentru stabilitate
}

void moveBarrierSlowly(int startAngle, int endAngle, int delayMs) {
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      barrierServo.write(angle);
      delay(delayMs);
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      barrierServo.write(angle);
      delay(delayMs);
    }
  }
}
