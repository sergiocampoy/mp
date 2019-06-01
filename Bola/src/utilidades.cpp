// Funciones varias

#include "utilidades.h"

#include "pelota.h"
#include "pelotas.h"
#include "definiciones.h"
#include "miniwin.h"

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace miniwin;

//////// Funciones de pelota ////////////

/**
 * @brief calcula la distancia entre dos pelotas
 * @param una Primera pelota
 * @param otra Segunda pelota
 * @return distancia entre los centros de las pelotas
 */
float distancia(const Pelota& una, const Pelota& otra) {
  float deltaX = una.x - otra.x;
  float deltaY = una.y - otra.y;

  return (sqrt(deltaX*deltaX + deltaY*deltaY));
}

/**
 * @brief comprueba si dos pelotas han colisionado
 * @param una Primera pelota
 * @param otra Segunda pelota
 * @return @retval true si han colisionado
 */
bool colisionado(const Pelota& una, const Pelota& otra) {
  return (distancia(una, otra) <= una.radio + otra.radio);
}

/**
 * @brief hace los cálculos del choque (intercambia la velocidad)
 * @param una Primera pelota
 * @param otra Segunda pelota
 */
void colisionar(int ancho, int alto, Pelota& una, Pelota& otra) {
  float dx = una.getDx();
  una.setDx(otra.getDx());
  otra.setDx(dx);

  float dy = una.getDy();
  una.setDy(otra.getDy());
  otra.setDy(dy);
  
  while(colisionado(una, otra)){
    mover(ancho, alto, una);
    mover(ancho, alto, otra);
  }
}

/**
 * @brief Mueve la pelota y comprueba si choca con la pared
 * @param ancho Ancho de la pantalla
 * @param alto Alto de la pantalla
 * @param pelota
 */
void mover(int ancho, int alto, Pelota& pelota) {
  pelota.x += pelota.dx;
  pelota.y += pelota.dy;

  if (pelota.x > ancho - pelota.radio) {
    pelota.dx = -pelota.dx * FACTOR;
    pelota.x = ancho - pelota.radio;
  } else if (pelota.x < pelota.radio) {
    pelota.dx = -pelota.dx * FACTOR;
    pelota.x = pelota.radio;
  }

  if (pelota.y > alto - pelota.radio) {
    pelota.dy = -pelota.dy * FACTOR;
    pelota.y = alto - pelota.radio;
  } else if (pelota.y < pelota.radio) {
    pelota.dy = -pelota.dy * FACTOR;
    pelota.y = pelota.radio;
  }

  if (FISICAS) {
    //pelota.dy += 10; // Gravedad
    pelota.dy += pelota.y/100; // Gravedad Oscar
    pelota.dx *= 0.99; // Rozamiento
  }
}

void pintar(const Pelota& pelota) {
  color((int) pelota.c);
  circulo_lleno(pelota.x, pelota.y, pelota.radio);
}

//////// Funciones de pelotas ////////////

/**
 * @brief Mueve todas las pelotas y las hace colisionar entre si
 * @param ancho Ancho de la pantalla
 * @param alto Alto de la pantalla
 * @param pelotas
 */
void mover(int ancho, int alto, Pelotas& pelotas) {
  bool choque = false;
  for (int i = 0; i < pelotas.util; i++) {
    mover(ancho, alto, pelotas[i]);
    for (int j = 0; j < pelotas.util && !choque; j++) {

      if (i != j && colisionado(pelotas[i], pelotas[j])) {
        if (pelotas[i] != pelotas[j]) {
          choque = true; // un poco ortopédico, pero funciona

          //Cuando son una es verde y otra es roja
          if (pelotas[i].getColor() == PColor::VERDE) {
            pelotas.borrar(i);
          } else {
            pelotas.borrar(j);
          }

        } else {
          //Cuando son verdes
          if (pelotas[i].getColor() == PColor::VERDE && pelotas.util < MAX_PEL) {
            Pelota aux;
            bool choca;
            do {
              choca = false;
              aux = Pelota();
              for (int i = 0; i < pelotas.util; i++) {
                if (colisionado(aux, pelotas[i])) {
                  choca = true;
                }
              }
            } while (choca);

            pelotas += aux;
          }
          colisionar(ancho, alto, pelotas[i], pelotas[j]);
        }
      }
    }
  }
}

/**
 * @brief Pinta todas las pelotas
 * @param pelotas
 */
void pintar(const Pelotas& pelotas) {
  for(int i=0; i < pelotas.util; i++){
    pintar(pelotas[i]);
  }
}

////// Funciones auxiliares /////////

void printPartida(std::ostream& fsalida, float ancho, float alto, const Pelotas& partida) {
  fsalida << PALABRA_CLAVE << std::endl;
  fsalida << ancho << std::endl << alto << std::endl;
  fsalida << partida << std::endl;
}

/**
 * @brief convierte de PColor a char[]
 * @param c
 */
const std::string colorToString(const PColor& c){
  std::string color;

  switch (c) {
  case PColor::NEGRO: color = "NEGRO";
    break;
  case PColor::VERDE: color = "VERDE";
    break;
  case PColor::AZUL: color = "AZUL";
    break;
  case PColor::AMARILLO: color = "AMARILLO";
    break;
  case PColor::MAGENTA: color = "MAGENTA";
    break;
  case PColor::CYAN: color = "CYAN";
    break;
  case PColor::BLANCO: color = "BLANCO";
    break;
  default: color = "ROJO";
    break;
  }

  return color;
}

/**
 * @brief convierte de char[] a PColor
 * @param cad
 */
const PColor stringToColor(std::string & str){
  PColor c;
  
  if (str.compare("NEGRO") == 0 )
    c = PColor::NEGRO;
  else if (str.compare("VERDE") == 0 )
    c = PColor::VERDE;
  else if (str.compare("AZUL") == 0 )
    c = PColor::AZUL;
  else if (str.compare("AMARILLO") == 0 )
    c = PColor::AMARILLO;
  else if (str.compare("MAGENTA") == 0 )
    c = PColor::MAGENTA;
  else if (str.compare("CYAN") == 0 )
    c = PColor::CYAN;
  else if (str.compare("BLANCO") == 0 )
    c = PColor::BLANCO;
  else
    c = PColor::ROJO;

  return c;
}
