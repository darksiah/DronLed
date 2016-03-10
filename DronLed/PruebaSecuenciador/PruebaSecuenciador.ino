#include <Secuencia.h>

int pines[] = {7,8,9,19};
Secuencia sec(pines);

void setup() {
  // put your setup code here, to run once:
  sec.begin();
}

void loop() {
  sec.on();
}
