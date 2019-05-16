#ifndef UTILIDADES_H_
#define ULTIDADES_H_

#include <cmath>
#include "pelota.h"
#include "pelotas.h"
#include "miniwin.h"

float distancia(const Pelota & una, const Pelota & otra){
  return(sqrt((una.getX()-otra.getX())*(una.getX()-otra.getX())+(una.getY()-otra.getY())*(una.getY()-otra.getY())));
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

#endif