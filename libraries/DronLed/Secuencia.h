#ifndef Secuencia_h
#define Secuencia_h

#define CANTLED 4
#define CANTSEC 10


  class Estado 
  {
  public:
    
    Estado();
    Estado(bool ledState[CANTLED],int intencidad[CANTLED],unsigned long intervaloCambio);
    Estado(bool ledState[CANTLED],int intencidad[CANTLED]);
    void estList();
    unsigned long getIntervalo();
    int getIntencidad(int);
    bool getLedState(int);

  private:
    bool ledState_[CANTLED];
    int intencidad_[CANTLED];
    unsigned long intervaloCambio_;
  };

class Secuencia 
  {
  public:

    // constructor
    Secuencia(int pines[CANTLED]);
    
    void begin ();
    void update ();
    void on ();
    void off ();
    bool isOn ();
    void agregaEstado(Estado e);
    void listPines();
    void listEstados();
 
   private:
     
     int pines_[CANTLED];
     Estado estados_[CANTSEC];
     bool secActive_;
     unsigned long ultimoMillis_;        // when we last changed state
     int estadoActual_;
     int cantEstados_;
  };  // end of Secuencia class

#endif