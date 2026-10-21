/*
  ESP32 - Prueba de LEDs por secuencias + Pantalla OLED (Solución Guru Meditation)
  GPIO LEDs: 19, 18, 16, 17
  GPIO OLED asignados en tu JSON: SDA = 21, SCL = 22
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definición de pines para la pantalla OLED según tu esquema
#define OLED_SDA 21
#define OLED_SCL 22

// Configuración de la Pantalla OLED
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pines de los LEDs
const int LED1 = 19;
const int LED2 = 18;
const int LED3 = 16;
const int LED4 = 17;

// --- FUNCIONES PARA INSTANCIAR LAS FLECHAS ---

void flechaAdelante() {
  display.clearDisplay();
  display.setTextSize(3);        
  display.setTextColor(SSD1306_WHITE);
  

  display.setCursor(54, 10);
    display.println("^");
  display.setTextSize(4);
  display.setCursor(54, 32);
  display.println("|");
  display.println("|");
  
  display.display();    
}

void flechaAtras() {
  display.clearDisplay();
  display.setTextSize(3);          
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(54, 15);
  display.println("|");
  display.println("|");
  
  display.setTextSize(4);
  display.setCursor(54, 32);
  display.println("v");
  
  display.display(); 
}             


void flechaIzquierda() {
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 20);          
  display.println("<---");
  display.display();                  
}

void flechaDerecha() {
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 20);
  display.println("--->");
  display.display();
}

void limpiarPantalla() {
  display.clearDisplay();
  display.display();
}


void setup() {
  Serial.begin(115200);
  delay(500); 

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Wire.begin(OLED_SDA, OLED_SCL);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("--- ERROR: No se encontró la pantalla OLED ---"));
    Serial.println(F("Revisa que la simulación de Wokwi cargue correctamente."));
    while(1) {
      delay(10); 
    }
  }
  
  limpiarPantalla();
  Serial.println(F("--- OLED Inicializada Correctamente ---"));
}

void loop() {

  flechaDerecha();
  digitalWrite(LED1, HIGH);
  digitalWrite(LED3, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED3, LOW);
  delay(500);

  flechaIzquierda();
  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);
  delay(2000);
  digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);
  delay(1000);

  flechaAdelante();
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(1000);

  flechaAtras();
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  delay(2000);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(1000);

  limpiarPantalla();
}
