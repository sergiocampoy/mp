// Funciones varias

#include "utilidades.h"

#include "pelota.h"
#include "pelotas.h"
#include "definiciones.h"
#include "miniwin.h"

#include <iostream>
#include <cmath>
#include <cstring>

float distancia(const Pelota & una, const Pelota & otra){
  float deltaX = una.getX() - otra.getX();
  float deltaY = una.getY() - otra.getY();

  return (sqrt(deltaX*deltaX + deltaY*deltaY));
}

bool colisionado(const Pelota & una, const Pelota & otra){
  return(distancia(una, otra) <= una.getRadio()+otra.getRadio());
}

void colisionar(Pelota& una, Pelota& otra) {
  float dx = una.dx;
  float dy = una.dy;

  una.dx = otra.dx;
  una.dy = otra.dy;

  otra.dx = dx;
  otra.dy = dy;
}

void mover(int ancho, int alto, Pelota& pelota) {

  const float FACTOR = 0.97;
  const float RADIO = pelota.getRadio();
  pelota.setX(pelota.getX()+pelota.getDx());
  pelota.setY(pelota.getY()+pelota.getDy());
  if (pelota.getX() > ancho - RADIO) {
    pelota.setDx(-(pelota.getDx() * FACTOR));
    pelota.setX(ancho - RADIO);
  } else if (pelota.getX() < RADIO) {
    pelota.setDx(-(pelota.getDx() * FACTOR));
    pelota.setX(RADIO);
  } else if (pelota.getY() > alto - RADIO) {
    pelota.setDy(-(pelota.getDy() * FACTOR));
    pelota.setY(alto - RADIO);
  } else if (pelota.getY() < RADIO) {
    pelota.setDy(-(pelota.getDy() * FACTOR));
    pelota.setY(RADIO);
  }

  if (PHIZEOUT) {
    pelota.setDy(pelota.getDy() + 10);
    pelota.setDx(pelota.getDx() * 0.99);
  }

}

void mover(int ancho, int alto, Pelotas& pelotas) {
  for (int i = 0; i < pelotas.getUtil(); i++) {
    //v[i].mover(alto, ancho);
    mover(ancho, alto, *pelotas.getElemento(i));
    for (int j = 0; j < pelotas.getUtil(); j++) {
      if (i != j && colisionado(*pelotas.getElemento(i), *pelotas.getElemento(j))){
        //if(pelotas.)
        colisionar(*pelotas.getElemento(i), *pelotas.getElemento(j));
      }
    }
  }
}

void pintar(const Pelotas & pelotas) {
  for(int i=0; i < pelotas.getUtil(); i++){
    miniwin::color((int) pelotas.getElemento(i)->getColor());
    miniwin::circulo_lleno(pelotas.getElemento(i)->getX(), pelotas.getElemento(i)->getY(), pelotas.getElemento(i)->getRadio());
    }
}

// Sobrecarga de operadores
// operator<< de Pelota
std::ostream& operator<<(std::ostream& fsalida, const Pelota& pelota) {
  fsalida << pelota.x << " " << pelota.y << " ";
  fsalida << pelota.dx << " " << pelota.dy << " ";
  fsalida << pelota.radio << " ";
  return fsalida;
}

// operator<< de Pelotas
std::ostream& operator<<(std::ostream& fsalida, const Pelotas& pelotas) {
  fsalida << pelotas.util << std::endl;
  for (int i = 0; i < pelotas.util; i++) {
    fsalida << pelotas.v[i] << std::endl;
  }
  return fsalida;
}

void printPartida(std::ostream& fsalida, float ancho, float alto, const Pelotas& partida) {
  fsalida << PALABRA_CLAVE << std::endl;
  fsalida << ancho << std::endl << alto << std::endl;
  fsalida << partida << std::endl;
}

const char* colorToCadena(const PColor& c){
    const char* color = new char[8];
    
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

const PColor cadenaToColor(const char * cad){
    PColor c;
    
      if(strcmp(cad, "NEGRO") == 0)
        c = PColor::NEGRO;
      else if(strcmp(cad, "VERDE")  == 0)
        c = PColor::VERDE;
      else if(strcmp(cad, "AZUL")  == 0)
        c = PColor::AZUL;
      else if(strcmp(cad, "AMARILLO")  == 0)
        c = PColor::AMARILLO;
      else if(strcmp(cad, "MAGENTA")  == 0)
        c = PColor::MAGENTA;
      else if(strcmp(cad, "CYAN")  == 0)
        c = PColor::CYAN;
      else if(strcmp(cad, "BLANCO")  == 0)
        c = PColor::BLANCO;
      else
        c = PColor::ROJO;
      
    return c;
}