//ESP2 wifi
//Servicio por internet
//Solicitar la hora a un servidor NTP
#include <WiFi.h>
//#include <wifi_biblio.h>
#include <time.h>//manejo de tiempo epoch
#include "C:\ESP32_Curso\23_wifi_biblio\23_wifi_biblio\wifi_biblio.h"
//Variables y constantes
//#define ssid xxx
//#define pass xxx

#define gtm -6
#define gtm_seg gtm*3600
#define h_ver 0
#define h_ver_seg h_ver*3600
char ntp[]= "pool.ntp.org";


void setup() {
  //UART
  Serial.begin(115200);
  delay(200);
  //WiFi
  f_wifi_sta_init();
  //NTP
  configTime(gtm_seg,h_ver_seg,ntp);

}

void loop() {
  int cta=0;
  while(cta<5){
    //Lee dato Epoch
    time_t now;//Variable de tipo tiempo
    time(&now);//Guarda dato de tiempo Epoch en variable now
    Serial.print("El tiempo Epoch actual es: ");
    Serial.println(now);
    cta++;
    delay(1000);
    }
    cta=0;
    while(cta<5){
      struct tm timeinfo;//tm da formato a tiempo anio mes dia hora minuto segundo
      if(getLocalTime(&timeinfo)){
        Serial.println(&timeinfo,"%d/%m/%Y %H:%M:%S");

      }
      cta++;
      delay(1000);
    }

}
