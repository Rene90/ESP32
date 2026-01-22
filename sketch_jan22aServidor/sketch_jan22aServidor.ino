//ESP32 - WIFI:TCP Server
//Comunicación entre cliente y servidor
#include <esp_wifi.h>
#include "C:\ESP32_Curso\23_wifi_biblio\23_wifi_biblio\wifi_biblio.h"//biblioteca hecha en clase para hacer conexión

WiFiServer server(80);//Instancia server, canal 714 
//Variables y constantes
#define ssid "CD_UNAM"
#define pass "MegaChidoLiro"


void setup() {
  // UART
  Serial.begin(115200);
  delay(200);
  //WiFi
  f_wifi_sta_init(ssid,pass);
  server.begin();//Inicia servidor
  Serial.println();
  Serial.println("Servidor TCP");
  Serial.print("IP ");
  Serial.println(WiFi.localIP());//Copiar en el cliente
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client =server.available();
  if(client){
    Serial.println("Cliente conectado!");
    while(client.connected()){//Mientras el cliente este conectado
      if(client.available()){//hay datos en espera por parte del cliente
        String linea = client.readStringUntil('\r');
        Serial.println("Cliente"+ linea);
        client.println("Servidor Mensaje recibido!");//contesta al cliente
        break;

      }
    }
    client.stop();//cierra la conexion con el cliente
    Serial.println("Cliente desconectado");
    Serial.println();
  }
}
