#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "pelota.h"
#include "pelotas.h"
#include "miniwin.h"

#include <cmath>
#include <iostream>

float distancia(const Pelota & una, const Pelota & otra){
  float deltaX = una.getX() - otra.getX();
  float deltaY = una.getY() - otra.getY();

  return (sqrt(deltaX*deltaX + deltaY*deltaY));
}

bool colision(const Pelota & una, const Pelota & otra){
  return(distancia(una, otra) <= una.getRadio()+otra.getRadio());
}

/*void mover(int alto, int ancho) {
  const float FACTOR = 1.03;
  x += dx;
  y += dy;
  if (x > ancho - radio) {
    dx = -dx * FACTOR;
    x = ancho - radio;
  } else if (x < radio) {
    dx = -dx * FACTOR;
    x = radio;
  } else if (y > alto - radio) {
    dy = -dy * FACTOR;
    y = alto - radio;
  } else if (y < radio) {
    dy = -dy * FACTOR;
    y = radio;
  }
  dy += 0.001;
}*/

void pintar(const Pelotas & pelotas) {
    for(int i=pelotas; i < pelotas.getUtil; i++){
        color((int) pelotas[i].getColor(c));
        circulo_lleno(pelotas[i].getX, pelotas[i].getY, pelotas[i].getRadio());
    }
}

void printPartida(float ancho, float alto, const Pelotas& partida);

#endif
