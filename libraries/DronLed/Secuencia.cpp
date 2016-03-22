#include "Secuencia.h"
#include "Arduino.h"

// constructor
Estado::Estado(bool ledState[CANTLED],int intencidad[CANTLED],unsigned long intervaloCambio)
  {
    //*ledState_ = ledState;

    for (int j=0; j<CANTLED ; j++)
    {
      Serial.println(intencidad[j]);
    }

    for (int i = 0; i < CANTLED; i++)
    {

      intencidad_[i] = intencidad[i];
      ledState_[i] = ledState[i];

    }
    
    intervaloCambio_ = intervaloCambio;
  }

  void Estado::estList()
  {
    Serial.println("Listado Estados");

   for (int i = 0; i < 4; i++)
    {
      Serial.println(intencidad_[i]);
    }
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
 
