//esp32 Wifi

#include <WiFi.h>//Biblioteca para el uso de wifi

//Variables y constantes

String enc[6] = { //Relacion con tipo de encriptado
"Abierta",
"WEP",
"WPA2",
"WPA_WPA2",
"WPA_ENTERPRISE"
};


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Sting msg = "";
  Serial.println("Inicia la busqueda")
  int n =WiFi



  else{
    Serial.pritnln("Se encontraron " + String(n) + " redes");
    for (int i=0; i<n; i++){
      Serial.println(
          String(i+1)+". "+
          WiFi.SSID(i)+ "\t"+
          WiFi.RSSI(i)+ "dBm \t"+
          enc[Wifi.encryptionType(i)]
      );
    }
  }
  delay(10000);

}
