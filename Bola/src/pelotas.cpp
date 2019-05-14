// Clase pelotas

#include "pelota.h"
#include "pelotas.h"

Pelotas::Pelotas() {
  v = new Pelota[10];
  capacidad = 10;
  util = 10;
}

Pelotas::Pelotas(int capacidad) {
  v = new Pelota[capacidad];
  this->capacidad = capacidad;
  util = 0;
}

Pelotas::Pelotas(Pelota *v, int util) {
  this->util = util;
  capacidad = util + 5;
  this->v = reservar(capacidad);
  for (int i = 0; i < util; i++) {
    this->v[i] = v[i];
  }
}

Pelotas::Pelotas(const Pelotas& otra) {
  capacidad = otra.capacidad;
  util = otra.util;
  v = new Pelota[capacidad];
  for (int i = 0; i < util; i++) {
    v[i] = otra.v[i];
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

void Pelotas::mover() {
  for (int i = 0; i < util; i++) {
    v[i].mover();
    v[i].pintar();
  }
}
