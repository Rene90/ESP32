//ESP32 WIFI
//PRUEBA  de biblioteca
#include <WiFi.h>
//#include "C:\ESP32_Curso\23_wifi_biblio\23_wifi_biblio\wifi_biblio.h"
#include <wifi_biblio.h>
//#define nombre "Hola_WiFi"
char *nombre[]= "Hola_WiFi";
char *contra[]= "12345";
void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  f_wifi_ap_init(nombre,contra);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
