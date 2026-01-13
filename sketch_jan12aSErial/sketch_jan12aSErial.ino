#define led 2 //led esta en GPI02
int del 250;  //del es la cantidad de ms para delay
bool led_sta =0; //Estado del led
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(200);
  pinMode(led,OUTPUT);
  Serial.println();
  Serial.println("Blink serial");
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    String s = Serial.readStringUntil('\n');
    del = s.toInt();
    if (del<10) del =10;
    if (del>250) del= 250;
    }
  digitalWrite(led,led_sta);
  led_sta = !led_sta;
  delay(del);

}
