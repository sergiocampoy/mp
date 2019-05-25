// decsai.ugr.es
// 25/04/19

#include "definiciones.h"
#include "miniwin.h"
#include "pelota.h"
#include "pelotas.h"
#include "simulador.h"
#include "utilidades.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace miniwin;

int main() {
  srand(time(0));
  Simulador partida("data/pelotas.txt");
  while (tecla() != ESCAPE) {
    partida.step(1);
    pintar(partida, 25);
  }
  partida.salvar("data/salida.txt");
  vcierra();
  //delete partida;
  return 0;
}
/*
int main() {
  // Inicializa la semilla para aleatorio()
  srand(time(0));

  // Variables auxiliares para la lectura
  char cad[64];
  float ancho, alto;

  Pelotas partida(1);

	// Lectura del fichero
  std::ifstream fentrada;
  if (LOAD){
    fentrada.open("data/salida.txt");
  } else {
    fentrada.open(FICHERO);
  }
  if (fentrada) {
    fentrada >> cad;
    if (strcmp(cad, PALABRA_CLAVE) == 0) {
      fentrada >> ancho >> alto;
      fentrada >> partida;
    } else {
      std::cerr << "El fichero no es adecuado" << std::endl;
      exit(1);
    }
  } else {
    std::cerr << "Error de apertura del fichero" << std::endl;
    exit(1);
  }
  fentrada.close();
  vredimensiona(ancho, alto);

  while (tecla() != ESCAPE) {
    borra();
    pintar(partida);
    mover(ancho, alto, partida);
    refresca();
    espera(25);
  }

  std::ofstream fsalida;
  fsalida.open("data/salida.txt");
  printPartida(fsalida, ancho, alto, partida);
  fsalida.close();

  vcierra();

  return 0;
}
*/
