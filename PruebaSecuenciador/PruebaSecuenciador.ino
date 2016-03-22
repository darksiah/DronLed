#include <Secuencia.h>

int pines[4] = {7,8,9,19};

bool ledState[4] = {false,true,false,false};
unsigned long intervaloCambio = 99;
int intencidad[4] = {10,20,30,40};
Estado e(ledState,intencidad,intervaloCambio);



void setup() {
  // put your setup code here, to run once:
  //sec.begin();
 
  Serial.begin(9600);
  Serial.println("Comenzando programa");
  e.estList();
  
}

void loop() {
  //sec.on();
}
