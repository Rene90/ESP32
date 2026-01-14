//ESP32 - PIO

//Entrada Basica con boton

//variables y constantes
//incrementa un contador cada vez que se presiona un boton
#define boton 0
int cta=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  pinMode(boton, INPUT);
  Serial.println(digitalRead(boton));
  Serial.println("Cuenta las veces que el boton es presionado");
  Serial.println();
}
void loop() {
  if(!digitalRead(boton)){
    cta++;
    Serial.println("El botono se ha presionado "+ String(cta) + " veces");//Imprimir cotador
    while(!digitalRead(boton)){
      delay(200);
    }
  }
}
