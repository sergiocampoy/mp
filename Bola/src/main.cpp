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

  // Loop principal
  while (tecla() != ESCAPE) {
    partida.step(1);
    pintar(partida, 25);
  }
  // Guarda la partida
  bool ok = partida.salvar("./data/salida.txt");
  if (!ok) std::cerr << "Error de escritura";
  
  // Comprobaciones de la sobrecarga de operadores
  Pelotas local = partida.getActual();
  std::cout << "Estado final: \n";
  std::cout << local << std::endl;
  Pelota p1 = partida.getOriginal()[0];
  Pelota p2 = partida.getActual()[0];
    std::cout << p1 << "\n" << p2 << "\nson ";
  if (p1==p2)
      std::cout << "Iguales \n";
  else
      std::cout << "Diferentes \n";

  vcierra();
  return 0;
}
