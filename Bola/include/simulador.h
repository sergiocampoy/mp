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
  void step(int);
  //void pintar(int)const;
  void salvar(const char*)const;
};

//void pintar(const Simulador&, int);
#endif
