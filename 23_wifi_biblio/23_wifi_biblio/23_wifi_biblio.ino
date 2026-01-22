//ESP32 - WiFi
//ESP32 como estación(STA) o como punto de acceso(AP)
#include <WiFi.h>
#include "wifi_biblio.h"  //Carga MI biblioteca

//Variables y Constantes
#define ssid  "Uli_WiFi"
#define pass  "12345678"

void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  //WiFi
  f_wifi_sta_init();//Función en biblioteca wifi_biblio.h
  //f_wifi_ap_init(ssid, pass);//Función en biblioteca wifi_biblio.h
}

void loop() {
  // put your main code here, to run repeatedly:

}
