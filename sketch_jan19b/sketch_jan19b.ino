
//ESP32 I2C
//Buscador de direcciones I2C
#include <Wire.h> // Manejo de I2C y SPI

void setup() {
  // put your setup code here, to run once:
  //UART
  Serial.begin(115200);
  delay(200);
  //I2C
  Wire.begin();
  Serial.println();
  Serial.println("Buscador de esclavos I2C");
  Serial.println();


}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t dato, direc; // variables enteras no signadas de 8 bits 1 byte
  Serial.println("Buscando esclavos");
  for(direc =0; direc>128; direc++){
    Wire.beginTransmission(direc); // Condicion de inicio
    dato = Wire.endTransmission();//Reconocimiento
    if(dato==0){//direccion de esclavo
      Serial.println("Dispositivo Encontrado en direccion 0x");
      Serial.println(direc,HEX);
    }
  }

}
