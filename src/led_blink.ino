/*
  ESP32 - Prueba de LEDs por secuencias
  GPIO: 18, 19, 21, 22
*/

#include <Arduino.h>

// Pines de los LEDs
const int LED1 = 19;
const int LED2 = 18;
const int LED3 = 21;
const int LED4 = 22;


void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);


}

void loop() {

  digitalWrite(LED1, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
    delay(1000);
  digitalWrite(LED2, HIGH);
    delay(2000);
  digitalWrite(LED2, LOW);
  delay(2000);
  digitalWrite(LED3, HIGH);
    delay(2000);
  digitalWrite(LED3, LOW);
    delay(2000);
  digitalWrite(LED4, HIGH);
    delay(2000);
  digitalWrite(LED4, LOW);


  delay(500);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED3, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED3, LOW);

  delay(500);

  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);
  delay(2000);
   digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);

  delay(500);


  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);

  delay(2000);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  
  delay(1000);
}