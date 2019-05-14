// decsai.ugr.es
// 25/04/19

#include "miniwin.h"
#include "pelota.h"
#include "pelotas.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace miniwin;

const int RADIO = 20;
/*
enum class PColor {
  NEGRO, ROJO, VERDE, AZUL,
  AMARILLO, MAGENTA, CYAN, BLANCO
};
*/
/* "Color" es un tipo enumerado definido en Miniwin.h.
Una variable de tipo Color puede tomar los siguientes valores:
NEGRO, ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO
No queremos que el diseño del los objetos dependan del interfaz gráfico por lo que se define
PColor un enumerado propio que coincide... por "pura coincidencia"!
*/

struct Bola {
   float x, y;
   float dx, dy;
   PColor c;
};

void pinta_pelota(const Bola& P) {
   color((int) P.c);
   circulo_lleno(P.x, P.y, RADIO);
}

void mueve_pelota(Bola& P) {
   const float factor = 0.97;
   P.x += P.dx;
   P.y += P.dy;
   if (P.x > vancho() - RADIO) {
      P.dx = -P.dx * factor;
      P.x = vancho() - RADIO;
   }
	else if (P.x < RADIO) {
      P.dx = -P.dx * factor;
      P.x = RADIO;
   }
	else if (P.y > valto() - RADIO) {
      P.dy = -P.dy * factor;
      P.y = valto() - RADIO;
   }
	else if (P.y < RADIO) {
      P.dy = -P.dy * factor;
      P.y = RADIO;
   }
   P.dy += 10;
   P.dx *= 0.95;
}

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

  std::ifstream fentrada;
  fentrada.open("data/pelotas.txt");
  if (fentrada) {
    fentrada >> cad;
    std::cout << cad << std::endl;
    if (strcmp(cad, "MP-PELOTAS-T-1.0") == 0) {
      fentrada >> ancho >> alto;
      fentrada >> numeroPelotas;
      partida = new Pelotas(numeroPelotas);
      for (int i = 0; i < numeroPelotas; i++) {
        fentrada >> x >> y >> dx >> dy >> radio;
        fentrada >> cad;
        std::cout << x << " " << cad << std::endl;
        if (strcmp(cad, "ROJO") == 0) {
          color = PColor::ROJO;
        } else if (strcmp(cad, "VERDE") == 0){
          color = PColor::VERDE;
        } else {
          std::cout << "YOU FUCKED BROOOOO" << std::endl;
        }
        // Asignación
        partida->aniadir(Pelota(x, y, dx, dy, radio, color));
      }
    } else {
      std::cerr << "El fichero no es adecuado" << std::endl;
      return 1;
    }
  } else {
    std::cerr << "Error de apertura del fichero" << std::endl;
    return 47;
  }
  fentrada.close();


  vredimensiona(800, 600);
  //  Pelota a(50.0, 50.0, 4.0, 8.0, 15, PColor::VERDE);
  //  Pelota b(175.0, 370.0, 16.0, 17.0, 10, PColor::ROJO);
  //   Pelota c(20.0, 40.0, 100.0, 12.0, 20, PColor::AZUL);

//  std::cout << a.getX() << ", " << a.getY() << std::endl;

  while (tecla() != ESCAPE) {
    borra();
    /*
    a.mover();
    b.mover();
    c.mover();
    a.pintar();
    b.pintar();
    c.pintar();
    */
    partida->mover();
    refresca();
    espera(25);
  }
  vcierra();
  return 0;
}
