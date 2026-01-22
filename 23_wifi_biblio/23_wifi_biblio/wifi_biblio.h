void f_wifi_sta_init(char *_ssid= ".:PC Puma FI:.", char *_pass = NULL);
void f_wifi_ap_init(char *_ssid, char *_pass);

//Función que inicializa WiFi en modo estación
void f_wifi_sta_init(char *_ssid, char *_pass){
  WiFi.mode(WIFI_STA);  //Modo estación
  delay(250);
  Serial.println();
  Serial.println("Conectado ESP32 a " + String(_ssid));
  WiFi.begin(_ssid, _pass); //Inicia e intenta conectarse a red
  int wifi_cta = 0; //Contador de intentos de conexión
  while(WiFi.status() != WL_CONNECTED && wifi_cta<15){//Mientras no se conecte
    Serial.print('.');
    delay(500);
    wifi_cta++; //Incrementa contador de intentos
  }
  Serial.println();
  if(wifi_cta>=15){
    Serial.println("Error → No se pudo conectar!!!");
    Serial.println("Reset en 3s");
    delay(3000);
    ESP.restart();  //Reinicia ESP32 (Reset)
  }
  Serial.println("WiFi conectado a " + String(_ssid));
  Serial.print("IP local → ");
  Serial.println(WiFi.localIP());
}

//Función que inicializa WiFi en modo Punto de Acceso
void f_wifi_ap_init(char *_ssid, char *_pass){
  WiFi.mode(WIFI_AP); //Modo Punto de Acceso
  delay(250);
  Serial.println();
  Serial.println("ESP32 como AP con el SSID → " + String(_ssid));
  WiFi.softAP(_ssid, _pass);  //Crea punto de acceso con nombre y contraseña
  IPAddress AP_IP = WiFi.softAPIP();  //Lee la dirección IP del AP
  Serial.print("Dirección IP → ");
  Serial.println(AP_IP);
  Serial.println();  
}
















