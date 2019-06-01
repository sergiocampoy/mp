//Alumno1: Campoy Maldonado, Sergio
//Alumno2: Antúnez Martinaitis, Óscar

#ifndef SIMULADOR_H_
#define SIMULADOR_H_

#include "pelotas.h"

class Simulador {
  friend void pintar(const Simulador&, int);
private:
  int ancho, alto;
  Pelotas original;
  Pelotas actual;
public:
  // Constructores/destructor
  Simulador(const char*);
  ~Simulador();

  // Métodos get
  inline int getAncho()const {
    return ancho;
  }
  inline int getAlto()const {
    return alto;
  }
  inline Pelotas getActual() const {
      return actual;
  }
  inline Pelotas getOriginal() const{
      return original;
  }
  void step(int);
  //void pintar(int)const;
  bool salvar(const char*)const;
};

//void pintar(const Simulador&, int);
#endif
