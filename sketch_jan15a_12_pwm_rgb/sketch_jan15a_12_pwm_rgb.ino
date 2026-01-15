//controlar la intensidad del led de la tarjeta

//Variables y constantes
//color rojo r
#define R_led 2 //Direccion del led
#define R_fre 1000
#define R_res 16
#define R_Max (pow(2,R_res)-1)
#define G_led 15 //Direccion del led
#define G_fre 1000
#define G_res 16
#define G_Max (pow(2,G_res)-1)//pwm valor maximo ancho pulso
#define B_led 4 //Direccion del led
#define B_fre 1000
#define B_res 16
#define B_Max (pow(2,B_res)-1)//pwm valor maximo ancho pulso
unsigned int R_ap =0;
unsigned int G_ap =0;
unsigned int B_ap =0; //ancho de pulso de cada color

void setup() {
  // put your setup code here, to run once:
  //UART
  Serial.begin(115200);
  delay(200);
  //GPIO
  pinMode(R_led,OUTPUT);//opcional en este ejemplo
  pinMode(G_led,OUTPUT);
  pinMode(B_led,OUTPUT);
  //PWM
  ledcAttach(R_led,R_fre,R_res);//salida por led, frecuencia a 1000 hertz, resolucion 16 bits
  ledcAttach(G_led,G_fre,G_res);
  ledcAttach(B_led,B_fre,B_res);
  Serial.println();
  Serial.println("Control de un led por PWM");
  Serial.println();

}

void loop() {
  String s="";
  String c="";
  int intensidad =0;
  if (Serial.available()){
    s= Serial.readStringUntil('\n');
    Serial.println("Intensidad recibida "+ s);
    int posPts = s.indexOf(':');
    int posFin= s.length();
    c = s.substring(0,posPts);//caracter del color
    c.toUpperCase();// caracter a mayuscula
    int val = s.substring(posPts+1,posFin).toInt();
    if (val <0) val =0;    
    if(val>100) val =100;
    if (c.equals("R")) R_ap = map(val,0,100,0,R_Max);//Cargar el valor de ancho del pulso
    else if(c.equals("G")) G_ap = map(val,0,100,0,G_Max);//Cargar el valor de ancho del pulso
    else if (c.equals("B")) B_ap = map(val,0,100,0,B_Max);//Cargar el valor de ancho del pulso
    s = "colores R: "+ String(R_ap)+ " G: "+ String(G_ap) + " B: "+ String(B_ap);
    Serial.println(s);
    
    delay(10);
  }
  ledcWrite(R_led,R_ap);//Modifica ancho de pulso
  ledcWrite(G_led,G_ap);//Modifica ancho de pulso
  ledcWrite(B_led,B_ap);//Modifica ancho de pulso


  //for(int i=0;i<Max; i+=100){
  // ledcWrite(led,i);
   // delay(10);
  //}
  //for(int i=0;i<Max; i+=100){
//ledcWrite(led,Max-i);
  //  delay(10);
 // }

}
