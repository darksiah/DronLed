#include <Secuencia.h>

// constructor
Estado::Estado(bool ledState[],int intencidad[],unsigned long intervaloCambio)
  {
    ledState_ = ledState;
    intencidad_ = intencidad;
    intervaloCambio_ = intervaloCambio;
  }

Secuencia::Secuencia (int pines[])
   {
    estados_ = NULL;
    pines_ = pines;
    estadoActual_ = 0;
    ultimoMillis_ = 0;
    cantEstados_ = 0;
    secActive_ = false;
   } 

//Setea las salidas y el tiempo en que comenzo toda la secuencia

void Secuencia::begin ()
  {
     for (int i = 0; i < CANTLED; ++i)
    {
      pinMode (pines_[i], OUTPUT);
    }
  
    ultimoMillis_ = millis ();  
  }

void Secuencia::agregaEstado()
  {
  }  
  
// call from loop to flash the LED
void Secuencia::update ()
  {
  } 
 
 // activate this LED
 void Secuencia::on ()
   {  
    secActive_ = true;
    ultimoMillis_ = millis (); 
   }  // end of Secuencia::on

 // deactivate this LED
 void Secuencia::off ()
   {
    secActive_ = false;
   for (int i = 0; i < CANTLED ; ++i)
    {
      digitalWrite(pines_[i], LOW);
    }
   }  
   
 bool Secuencia::isOn ()
   {
    return secActive_;
   }  // end of Secuencia::isOn
 
