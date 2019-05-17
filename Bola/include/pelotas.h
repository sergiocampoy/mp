#ifndef PELOTAS_H_
#define PELOTAS_H_

#include "pelota.h"

#include <iostream>

class Pelotas {
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream&, const Pelotas&);

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
  Pelotas(int capacidad);
  Pelotas(Pelota *v, int util);
  Pelotas(const Pelotas& otra);
  inline ~Pelotas() {
    liberar(v);
  }

  // Métodos get
  inline int getUtil()const {
    return util;
  }
  inline int getCapacidad()const {
    return capacidad;
  }
  inline Pelota* getElemento(int indice)const {
    Pelota* resultado = nullptr;
    if (0 <= indice && indice <= util) {
      resultado = &v[indice];
    }
    return resultado;
  }

  void borrar(int indice);
  void aniadir(const Pelota& pelota);

  // Sobrecarga de operadores
  const Pelotas& operator=(const Pelotas&);
};


#endif
