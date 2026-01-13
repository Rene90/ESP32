//variables y constantes

int leds[4]={15,2,4,16};
//Arreglo de 6 x 4 de secuencia de leds
int sec[6][4] = {
  {0,0,0,1},
  {0,0,1,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0}

};


void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<4; i++)
    pinMode(leds[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 for (int ren=0; ren<6; ren++){
  for (int col=0; col<4; col++)
    digitalWrite(leds[col],sec[ren][col]);
  delay(200);
 }
}
