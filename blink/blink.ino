#include <Arduino.h>

// O LED RGB onboard do ESP32-S3 geralmente é o pino 48
#define RGB_BUILTIN 48

void setup() {
  // Nenhuma configuração especial é necessária para o neopixelWrite
}

void loop() {
  // neopixelWrite(pino, r, g, b) - valores de 0 a 255
  neopixelWrite(RGB_BUILTIN, 100, 0, 0); // Vermelho (brilho baixo)
  delay(500);
  neopixelWrite(RGB_BUILTIN, 0, 100, 0); // Verde (brilho baixo)
  delay(500);
  neopixelWrite(RGB_BUILTIN, 0, 0, 100); // Azul (brilho baixo)
  delay(500);
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);   // Desligado
  delay(500);
}