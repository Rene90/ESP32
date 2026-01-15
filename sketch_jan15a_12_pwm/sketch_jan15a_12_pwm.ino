//controlar la intensidad del led de la tarjeta

//Variables y constantes
#define led 2 //Direccion del led
#define fre 1000
#define res 16
#define Max (pow(2,res)-1)//pwm valor maximo ancho pulso

void setup() {
  // put your setup code here, to run once:
  //UART
  Serial.begin(115200);
  delay(200);
  //GPIO
  pinMode(led,OUTPUT);//opcional en este ejemplo
  //PWM
  ledcAttach(led,fre,res);//salida por led, frecuencia a 1000 hertz, resolucion 16 bits
  Serial.println();
  Serial.println("Control de un led por PWM");
  Serial.println();

}

void loop() {
  String s="";
  int intensidad =0;
  if (Serial.available()){
    s= Serial.readStringUntil('\n');
    intensidad = s.toInt();
    if (intensidad <0) intensidad =0;
    
    if(intensidad>100) intensidad =100;
   
    Serial.println("PC intensidad "+ s); 
    ledcWrite(led,map(intensidad,0,100,0,Max));
    delay(10);
  }



  //for(int i=0;i<Max; i+=100){
  // ledcWrite(led,i);
   // delay(10);
  //}
  //for(int i=0;i<Max; i+=100){
//ledcWrite(led,Max-i);
  //  delay(10);
 // }

}
