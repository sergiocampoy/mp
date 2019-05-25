// Clase pelotas

#include "pelotas.h"

#include "pelota.h"
#include "utilidades.h"

#include "miniwin.h"

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
  capacidad = util + 10;
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

/**
 * @brief borra la pelota del índice
 * @param indice
 */
void Pelotas::borrar(int indice) {
  if (0 <= indice && indice < util) {
    util--;
    for (int i = indice; i < util; i++) {
      v[i] = v[i+1];
    }
  }
}

/**
 * @brief añade la pelota al final (reserva espacio si es necesario)
 * @param pelota
 */
void Pelotas::aniadir(const Pelota& pelota) {
  if (util < capacidad) {
    v[util] = pelota;
    util++;
  } else {
    Pelota* nuevoV = nullptr;
    nuevoV = reservar(capacidad + 10);
    // Bucle de copia de los datos
    for (int i = 0; i < util; i++) {
      nuevoV[i] = v[i];
    }
    nuevoV[util] = pelota;
    util++;
    capacidad += 10;
    liberar(v);
    v = nuevoV;
  }
}

// Sobrecarga de operadores

// operator<< de Pelotas
std::ostream& operator<<(std::ostream& fsalida, const Pelotas& pelotas) {
  fsalida << pelotas.util << std::endl;
  for (int i = 0; i < pelotas.util; i++) {
    fsalida << pelotas[i] << std::endl;
  }
  return fsalida;
}

// operator>> de Pelotas
const std::istream& operator>>(std::istream& fentrada, Pelotas& pelotas) {
  // "Reset" de pelotas
  pelotas.liberar(pelotas.v);
  pelotas.util = 0;
  pelotas.capacidad = 0;

  Pelota aux;
  int total;

  fentrada >> total;
  pelotas.v = pelotas.reservar(total);
  for (int i = 0; i < total; i++) {
    fentrada >> aux;
    pelotas.aniadir(aux);
  }

  return fentrada;
}

// operator= de Pelotas
const Pelotas& Pelotas::operator=(const Pelotas& otra) {
  // Comprobamos que this y otra son distintos
  if (this != &otra) {
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
  }
  return *this;
}

// operator+= de Pelotas
const Pelotas& Pelotas::operator+=(const Pelota& pelota) {
    this->aniadir(pelota);

    return *this;
}

// operator[] de Pelotas
Pelota& Pelotas::operator[](int indice) {
  if (indice < 0 || indice >= util) {
    throw std::invalid_argument("Indice invalido en Pelotas::operator[]");
    std::cout << indice << " " << v[indice] << std::endl;
    std::cout << util << " " << capacidad << std::endl;
    //miniwin::espera(10000);
  }
  return v[indice];
}

// operator[] constante de Pelotas
Pelota Pelotas::operator[](int indice)const {
  if (indice < 0 || indice >= util) {
    throw std::invalid_argument("Indice invalido en Pelotas::operator[]const");
  }
  return v[indice];
}
