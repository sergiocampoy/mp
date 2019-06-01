#include "simulador.h"

#include "utilidades.h"
#include "definiciones.h"
#include "miniwin.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace miniwin;

Simulador::Simulador(const char* fichero) {
  char cad[20];
  std::ifstream fentrada;
  fentrada.open(fichero);
  if (fentrada.is_open()) {
    fentrada >> cad;
    if (strcmp(cad, PALABRA_CLAVE) == 0) {
      fentrada >> ancho >> alto;
      fentrada >> original;
      actual = original;
    } else {
      std::cerr << "El fichero no es adecuado" << std::endl;
      exit(1);
    }
  } else {
    std::cerr << "Error en la apertura del fichero" << std::endl;
    exit(1);
  }
  fentrada.close();
  vredimensiona(ancho, alto);
}

Simulador::~Simulador() {
  vcierra();
}

/**
 * @brief mueve las pelotas tantas veces como indica @param
 * @param numero de pasos a dar
 */
void Simulador::step(int pasos) {
  for (int i = 0; i < pasos; i++) {
    mover(ancho, alto, actual);
  }
}

/**
 * @brief pinta las pelotas y espera @param tiempo
 * @param tiempo que va a esperar
 */
void pintar(const Simulador& sim, int tiempo) {
  borra();
  pintar(sim.actual);
  refresca();
  espera(tiempo);
}

/**
 * @brief guarda los datos de la partida en un fichero
 * @param fichero en el que se guarda la partida
 */
bool Simulador::salvar(const char* fichero)const {
  bool flag = false;
  std::ofstream fsalida;
  fsalida.open(fichero);
  if (fichero) {
    fsalida << PALABRA_CLAVE << std::endl;
    fsalida << ancho << std::endl << alto << std::endl;
    fsalida << actual.getUtil() << std::endl;
    for (int i = 0; i < actual.getUtil(); i++) {
      fsalida << actual[i] << std::endl;
    }
    flag = true;
  } /*else {
    std::cerr << "Error en la apertura del fichero" << std::endl;
    exit(1);
  }*/
  fsalida.close();
  return flag;
}
