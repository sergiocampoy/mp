// Clase pelotas

#include "pelotas.h"

#include "pelota.h"
#include "utilidades.h"

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

const Pelotas& Pelotas::operator=(const Pelotas& otra) {
  // Liberamos this
  this->liberar(this->v);

  // Copiamos datos miembro
  this->capacidad = otra.capacidad;
  this->util = otra.util;
  this->v = this->reservar(capacidad);

  // Copiamos el contenido de v
  for (int i = 0; i < this->util; i++) {
    this->v[i] = otra.v[i];
  }

  return *this;
}
