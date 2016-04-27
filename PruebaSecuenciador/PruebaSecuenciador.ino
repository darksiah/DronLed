#include <Secuencia.h>

//int pines[4] = {6,9,10,11};
int pines[4] = {13,9,10,11};

bool ledStateFB[4] = {true,false,true,false};
bool ledStateLR[4] = {false,true,false,true};
bool ledStateAllOn[4] = {true,true,true,true};
bool ledStateAllOff[4] = {false,false,false,false};

int intencidadFull[4] = {255,255,255,255};

Estado e(ledStateAllOn,intencidadFull,10000);
Estado e1(ledStateAllOff,intencidadFull,1000);
Estado e2(ledStateAllOn,intencidadFull,200);
Estado e3(ledStateAllOff,intencidadFull,200);
Estado e4(ledStateAllOn,intencidadFull,5000);

Secuencia s1(pines);



void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  s1.begin();
  s1.agregaEstado(e);
  s1.agregaEstado(e1);
  s1.agregaEstado(e2);
  s1.agregaEstado(e3);
  s1.agregaEstado(e4);
  //s1.listPines();
  s1.listEstados();
  Serial.println("Comenzando programa");
  s1.on();
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
