#include <Secuencia.h>

int pines[4] = {6,9,10,11};

bool ledStateFB[4] = {true,false,true,false};
bool ledStateLR[4] = {false,true,false,true};
bool ledStateAllOn[4] = {true,true,true,true};
bool ledStateAllOff[4] = {false,false,false,false};

int intencidadFull[4] = {255,255,255,255};

Estado e(ledStateFB,intencidadFull);
Estado e1(ledStateAllOff,intencidadFull);

Secuencia s1(pines);



void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  s1.begin();
  s1.agregaEstado(e);
  s1.agregaEstado(e1);
  //s1.listPines();
  //s1.listEstados();
  Serial.println("Comenzando programa");
  /*s1.update();
  delay(500);
  s1.update();
  delay(500);
  s1.update();
  delay(500);
  s1.update();
  */
}

void loop() {
  s1.update();
}
