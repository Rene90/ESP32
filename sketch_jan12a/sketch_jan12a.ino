#define led 2 //led esta en GPI02
#define del 250  //del es la cantidad de ms para delay
bool led_sta =0; //Estado del led
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,led_sta);
  led_sta = !led_sta;
  delay(del);
  
  delay(del);
}
