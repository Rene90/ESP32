void f_wifi_init(char *_ssid, char *_pass){
  WiFi.mode(WIFI_STA);//modo estacion, la tarjeta se puede conectar a un punto de acceso como pc puma
  delay(250);
  Serial.println();
  Serial.println("Conectando ESP32 a " + String(_ssid));
  WiFi.begin(_ssid, _pass); //Inicia e intenta conectarse a red
  int wifi_cta =0; //Contador de intntos de conexion
  while(WiFi.status()!= WL_CONNECTED && wifi_cta<15){//mientras no se conecte
    Serial.print('.');
    delay(500);
    wifi_cta++;//Incrementa contador de intentos
  }
  Serial.println();
  if(wifi_cta>=15){
    Serial.println("Error No se pudo conectar");
    Serial.println("Reset en 3s");
    delay(3000);
    ESP.restart(); //Reinicia ESP32
  }
  Serial.println("WiFi conectado a " + String(_ssid));
  Serial.print("IP local ");
  Serial.println(WiFi.localIP());
}