#include "utilidades.h"
#include "pelotas.h"
#include "pelota.h"
#include "definiciones.h"

#include <iostream>

// Sobrecarga de operadores
// operator<< de Pelota
std::ostream& operator<<(std::ostream& fsalida, const Pelota& pelota) {
  fsalida << pelota.x << " " << pelota.y << " ";
  fsalida << pelota.dx << " " << pelota.dy << " ";
  fsalida << pelota.radio << " ";
  switch (pelota.c) {
    case PColor::NEGRO: fsalida << "NEGRO";
      break;
    case PColor::VERDE: fsalida << "VERDE";
      break;
    case PColor::AZUL: fsalida << "AZUL";
      break;
    case PColor::AMARILLO: fsalida << "AMARILLO";
      break;
    case PColor::MAGENTA: fsalida << "MAGENTA";
      break;
    case PColor::CYAN: fsalida << "CYAN";
      break;
    case PColor::BLANCO: fsalida << "BLANCO";
      break;
    default: fsalida << "ROJO";
      break;
  }
  return fsalida;
}

// operator<< de Pelotas
std::ostream& operator<<(std::ostream& fsalida, const Pelotas& pelotas) {
  fsalida << pelotas.util << endl;
  for (int i = 0; i < pelotas.util; i++) {
    fsalida << v[i] << endl;
  }
  return fsalida;
}

void printPartida(std::ostream& fsalida, float ancho, float alto, const Pelotas& partida) {
  fsalida << PALABRA_CLAVE << std::endl;
  fsalida << ancho << std::endl << alto << std::endl;
  fsalida << partida << endl;
}
