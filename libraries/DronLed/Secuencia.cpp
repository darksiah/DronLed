#include "Secuencia.h"
#include "Arduino.h"

// constructor
Estado::Estado()
  {
    intervaloCambio_ = 200;
    for (int i = 0; i < CANTLED; ++i)
    {
      intencidad_[i] = 0;
      ledState_[i] = false;
    }
    
  }
Estado::Estado(bool ledState[CANTLED],int intencidad[CANTLED],unsigned long intervaloCambio)
  {
    for (int i = 0; i < CANTLED; i++)
    {

      intencidad_[i] = intencidad[i];
      ledState_[i] = ledState[i];

    }
    
    intervaloCambio_ = intervaloCambio;
    ejecutado_ = false;
  }

  Estado::Estado(bool ledState[CANTLED],int intencidad[CANTLED])
  {
    for (int i = 0; i < CANTLED; i++)
    {

      intencidad_[i] = intencidad[i];
      ledState_[i] = ledState[i];

    }

    intervaloCambio_ = 200;
    ejecutado_ = false;
  }

  void Estado::estList()
  {
    Serial.println("Listado Estados");

   for (int i = 0; i < 4; i++)
    {
      Serial.print("Encendido:  ");
      Serial.print(ledState_[i]);
      Serial.print("  Intencidad:  ");
      Serial.print(intencidad_[i]);
      Serial.println("");
    }
  }

  unsigned long Estado::getIntervalo()
  {
    return intervaloCambio_;
  }
  
  int Estado::getIntencidad(int x)
  {
    return intencidad_[x];
  }

  bool Estado::getLedState(int x)
  {
    return ledState_[x];
  }
  bool Estado::isEjecutado()
  {
    return ejecutado_;
  }

Secuencia::Secuencia (int pines[CANTLED])
   {
    
    for (int i=0; i<CANTLED ; i++)
    {
      pines_[i] = pines[i];
    }
    
    estadoActual_ = 0;
    ultimoMillis_ = 0;
    cantEstados_ = 0;
    secActive_ = false;
    inic_ = true;
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

void Secuencia::agregaEstado(Estado e)
  {
    estados_[cantEstados_] = e;
    cantEstados_++;
  }

bool Secuencia::isInic()
{
  return inic_;
}
void Secuencia::setInic()
{
  inic_ = true;
}  
// call from loop to flash the LED
void Secuencia::update ()
  {
    //Serial.print("estadoActual_   ");
    //Serial.println(estadoActual_);
    //Serial.print("cantEstados_-1   ");
    //Serial.println(cantEstados_-1);
    //Serial.print("ultimoMillis_   ");
    //Serial.println(ultimoMillis_);
    //Serial.print("millis()   ");
    //Serial.println(millis());
    //Serial.print("estados_[estadoActual_].getIntervalo()  ");
    //Serial.println(estados_[estadoActual_].getIntervalo());
    //Serial.print("estadoActual_  ");
    //Serial.println(estadoActual_);
    //Serial.print("cantEstados_-1  ");
    //Serial.println(cantEstados_-1);


    if(estadoActual_ > (cantEstados_-1) ) estadoActual_ = 0; // Reinicia la secuencia cuando llego a su fin

    if ( estadoActual_ == 0 && isInic() )
    {
      for (int i = 0; i < CANTLED; i++)
      {
        if (estados_[0].getLedState(i))
        {
          //Serial.println("Ejecute el prendido de pin");
          analogWrite(pines_[i],estados_[0].getIntencidad(i));
        }
        else
        {
          //Serial.println("Ejecute el apagado de pin");
          digitalWrite(pines_[i],LOW);
        }
      }

      estadoActual_++;
      ultimoMillis_ = millis();
      setInic();
    }
    if ( estadoActual_ == 0 && !isInic() )
    {
        if( ( (millis() - ultimoMillis_) > estados_[cantEstados_-1].getIntervalo()) && secActive_ && ( !( estados_[estadoActual_].isEjecutado() ) ) )
          {
          //Serial.println("Entre en el IF");
          for (int i = 0; i < CANTLED; i++)
          {
            if (estados_[0].getLedState(i))
            {
            //Serial.println("Ejecute el prendido de pin");
            analogWrite(pines_[i],estados_[0].getIntencidad(i));
            }
        
            else
            {
            //Serial.println("Ejecute el apagado de pin");
            digitalWrite(pines_[i],LOW);
            }
          } 
          estadoActual_++;
          ultimoMillis_ = millis();
          }
    }
    if ( estadoActual_ != 0 )
    {
      if ( ( (millis() - ultimoMillis_) > estados_[estadoActual_-1].getIntervalo()) && secActive_ && ( !( estados_[estadoActual_].isEjecutado() ) ) )
        {
          //Serial.println("Entre en el IF");
          for (int i = 0; i < CANTLED; i++)
          {
            if (estados_[estadoActual_].getLedState(i))
              {
              //Serial.println("Ejecute el prendido de pin");
              analogWrite(pines_[i],estados_[estadoActual_].getIntencidad(i));
              }
            else
              {
              //Serial.println("Ejecute el apagado de pin");
              digitalWrite(pines_[i],LOW);
              }
          }
            estadoActual_++;
            ultimoMillis_ = millis();
        }
    }
}

void Secuencia::listPines()
  {
    Serial.println("Listado de pines");

    for (int i = 0; i < CANTLED; i++)
    {
      Serial.println(pines_[i]);

    }
  }
  void Secuencia::listEstados()
  {
    for (int i = 0; i < cantEstados_; i++)
    {
      estados_[i].estList();
    }
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
 
