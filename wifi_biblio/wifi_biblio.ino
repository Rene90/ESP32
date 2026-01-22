//ESP32 como estacion sta o como punto de acceso ap
#include <WiFi.h>
#include "wifi_biblior.h" //carga mi bilbioteca
//Variables y constanttes, poner una red que exista
#define ssid ".:PC PUMA FI:."
#define pass NULL



void setup() {
  // UART
  Serial.begin(115200);
  delay(200);
  //wifi
  f_wifi_init(ssid,pass); //funcion en biblioteca importada en linea 3
}

void loop() {
  
}
