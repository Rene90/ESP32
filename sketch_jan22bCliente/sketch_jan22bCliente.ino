//ESP32 - WIFI:TCP Server
//Comunicación entre cliente y servidor
#include <WiFi.h>
#include "C:\ESP32_Curso\23_wifi_biblio\23_wifi_biblio\wifi_biblio.h"//biblioteca hecha en clase para hacer conexión



//Variables y constantes
#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"
int cta=0;
const char* serverIP="192.168.50.90";

void setup() {
  // UART
  Serial.begin(115200);
  delay(200);
  //WiFi
  f_wifi_sta_init(ssid,pass);
  //iniciamos el servidor
  
  Serial.println();
  Serial.println("Cliente TCP");
  Serial.print();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;//Crea instancia cliente
  Serial.println("Conectando con el servidor");
  if(client.connected(serverIP, 714)){//servidor conectado
    Serial.println("Servidor conectado");
    Serial.println("Enviando datos...");
    cta++; //Incrementa cuenta
    client.println("Cuenta: "+String(cta));
    unsigned long timeout = millis();//Tiempo de espera
    while (client.available()==0){//Mientasno existan datos del servidor
      if(millis()-timeout> 5000){//Espera solo por 5 segundos
        Serial.println("Error Tiempo de espera superado");
        client.stop();
        return
      }

    }
    if(client.available()){//si hay datos lee la respuesta del servidor
      String msg= client.readStringUntil('\r');
      Serial.println("Servidor " + msg);
    }
    client.stop(); //Finaliza conexion
    Serial.println("Conexion cerrada");

  }
  else{
    Serial.println("conexion fallida");
    

  }
  delay(10000);

}
