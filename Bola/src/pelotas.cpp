// Clase pelotas

#include "pelota.h"
#include "pelotas.h"

Pelotas::Pelotas() {
  v = new Pelota[10];
  capacidad = 10;
  util = 10;
}

Pelotas::Pelotas(Pelota *v, int util) {
  this->util = util;
  capacidad = util + 5;
  this->v = reservar(capacidad);
  for (int i = 0; i < util; i++) {
    this->v[i] = v[i];
  }
}

Pelotas::~Pelotas() {
  liberar(v);
}

Pelota* Pelotas::reservar(int n) {
  Pelota* array = nullptr;
  array = new Pelota[n];
  return array;
}

void Pelotas::liberar(Pelota*& array) {
  if (array != nullptr) {
    delete[] array;
  }
}

void Pelotas::borrar(int indice) {
  if (0 <= indice && indice < util) {
    for (int i = indice; i < util-1; i++) {
      v[i] = v[i+1];
    }
  }
}

void Pelotas::aniadir(const Pelota& pelota) {
  if (util < capacidad) {
    v[util] = pelota;
    util++;
  } else {
    Pelota* nuevoV = nullptr;
    nuevoV = reservar(capacidad + 5);
    for (int i = 0; i < util; i++) {
      nuevoV[i] = v[i];
    }
    nuevoV[util] = pelota;
    util++;
    capacidad += 5;
    liberar(v);
    v = nuevoV;
  }
}
