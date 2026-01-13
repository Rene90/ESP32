//ES32 UART
//eco de caracter tecleado
void setup() {
  // UART
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("Eco serial");
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  //Espera por caracteres
  if(Serial.available()){
    //Serial.write(Serial.read());//Imprime lo que recibe (ECO)
    String s = Serial.readStringUntil('\n');
    Serial.println("REcibido " + s);
  }

}
