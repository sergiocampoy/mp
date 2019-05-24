#ifndef PELOTAS_H_
#define PELOTAS_H_

#include "pelota.h"

#include <iostream>

class Pelotas {
  // Funciones amigas
  friend void mover(int, int, Pelotas&);
  friend void pintar(const Pelotas&);
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream&, const Pelotas&);
  friend const std::istream& operator>>(std::istream&, Pelotas&);
private:
  // Datos miembro
  Pelota* v;
  int capacidad;
  int util;

  // Métodos privados
  inline Pelota* reservar(int n) {
    Pelota* array = nullptr;
    array = new Pelota[n];
    return array;
  }
  inline void liberar(Pelota*& array) {
    if (array != nullptr) {
      delete[] array;
    }
  }
public:
  // Constructores y destructores
  Pelotas();
  Pelotas(int);
  Pelotas(Pelota*, int);
  Pelotas(const Pelotas&);
  inline ~Pelotas(){
    liberar(this->v);
  }

  // Métodos get
  inline int getUtil()const {
    return util;
  }
  inline int getCapacidad()const {
    return capacidad;
  }
  inline Pelota& getElemento(int indice)const {
      Pelota& resultado = v[indice];
    return resultado;
  }

  void borrar(int indice);
  void aniadir(const Pelota& pelota);

  // Sobrecarga de operadores
  const Pelotas& operator=(const Pelotas&);
  const Pelotas& operator+=(const Pelota&);
  Pelota& operator[](int);
  Pelota operator[](int)const;
};


#endif
