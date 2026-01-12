#define led 2 //led esta en GPI02
#define del 250  //del es la cantidad de ms para delay

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
}
