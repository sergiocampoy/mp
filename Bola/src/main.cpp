// decsai.ugr.es
// 25/04/19

#include "definiciones.h"
#include "miniwin.h"
#include "pelota.h"
#include "pelotas.h"
#include "utilidades.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace miniwin;

int main() {
  // Inicializa la semilla para aleatorio()
  srand(time(0));

  // Variables auxiliares para la lectura
  char cad[64];
  int ancho;
  int alto;
  int numeroPelotas;
  float x, y, dx, dy, radio;
  PColor color;

  Pelotas* partida;

	// Lectura del fichero
  std::ifstream fentrada;
  fentrada.open("data/salida.txt");
  if (fentrada) {
    fentrada >> cad;
    if (strcmp(cad, PALABRA_CLAVE) == 0) {
      fentrada >> ancho >> alto >> numeroPelotas;
      partida = new Pelotas(numeroPelotas);
      for (int i = 0; i < numeroPelotas; i++) {
        fentrada >> x >> y >> dx >> dy >> radio >> cad;
        if (strcmp(cad, "ROJO") == 0) {
          color = PColor::ROJO;
        } else {
          color = PColor::VERDE;
        }
        // Asignación
        partida->aniadir(Pelota(x, y, dx, dy, radio, color));
      }
    } else {
      std::cerr << "El fichero no es adecuado" << std::endl;
      exit(1);
    }
  } else {
    std::cerr << "Error de apertura del fichero" << std::endl;
    exit(1);
  }
  fentrada.close();

//  ancho=400;
//  alto=300;

  vredimensiona(ancho, alto);

  while (tecla() != ESCAPE) {
    borra();
    pintar(*partida);
    mover(ancho, alto, *partida);
    refresca();
    espera(25);
  }

  std::ofstream fsalida;
  fsalida.open("data/salida.txt");
  printPartida(fsalida, ancho, alto, *partida);
  fsalida.close();

  vcierra();
  return 0;
}
