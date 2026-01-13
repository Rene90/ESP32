//ESP32
//Pruebas de impresion en terminal

void setup() {
  //UART
  Serial.begin(1152000);//inicializa comunicacion UART
  Serial.println("");
  Serial.println("1 Hola edmundo");
  Serial.print("2 Hola edmundo \n");
  String msg = "Hola Edmundo";
  Serial.printf("3 %s",msg);
  Serial.println("4 "+msg);
  int num=5;
  Serial.print(String(num) + " " + msg);
}

void loop() {
  // put your main code here, to run repeatedly:

}
