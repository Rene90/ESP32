#include <BluetoothSerial.h>


BluetoothSerial bt;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  // BT
  bt.begin("RENE");
  Serial.println();
  Serial.println("Comunicacion bt basica");
  Serial.println("No olvides emparejar tu bt primero");
  Serial.println();


}

void loop() {
  String s= "";
  if(Serial.available()){//Hay datos en el buffer serie
    s= Serial.readStringUntil('\n'); //Leer los datos hasta que se encuentre la nueva linea
    Serial.println("PC "+ s); //Publica ebn PC
    bt.println(s); //Publica en bluetooth
  }
  if(bt.available()){//hay datos en el bufer Bluetooth??
   s=bt.readStringUntil('\n');//Lee los datos hasta nueva linea
   Serial.println("BT "+ s); // Publiva en PC lo recibieo por BT
  bt.println(s); //Eco en BT
  }
}
