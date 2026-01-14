
int boton=0;
#define t_rebote 150 //filtro tiempo de filtrado
unsigned int t_bak=0;
bool boton_sta = false;
int cta=0;


bool f_Filtro(){
  if(millis() - t_bak >= t_rebote){ //Ya transcurrio el tiempo de rebotes
    t_bak =millis();//Almaceno el tiempo y regresamos true
    return (true);
  }
  else{
    return (false);
  }

}
void IRAM_ATTR f_Cuenta(){
  if(f_Filtro)
    boton_sta=true;//Bandera de boton presionado


}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  pinMode(boton,INPUT);
  attachInterrupt(boton,f_Cuenta,LOW);
  Serial.println();
  Serial.println("Cuenta las veces ue se presiona un boon por itnerrupcion");
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(boton_sta){
    cta++;
    Serial.println("Presionando "+ String(cta));
    boton_sta=false;
  }
}
