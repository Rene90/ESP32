#define dac1 25 //Salida anaogica DAC1
#define adc1 33 // Entrada analogica CH5

void setup() {
  // put your setup code here, to run once:
  Serial.begin

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =0; i<360; i++){
    //dacWrite(dac1,i);
    f_harmo(i);//Llama a la funcion f_harmo
    int tmp =analogRead(adc1);
    f_trigo(i);//Llama a la funcion f_trigo
    Serial.println(String(tmp)+","+String(analogRead(adc1)));//Publica dato leido
    delay(8);
  }
}
//Funcion trigonometrica
void f_trigo(int deg){
  dacWrite(dac1,)

}
