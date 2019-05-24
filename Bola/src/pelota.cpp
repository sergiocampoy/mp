// Clase pelota

#include "pelota.h"

#include "definiciones.h"

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

float Pelota::aleatorio(float tope) {
  return (rand() % (int)(tope) + 1);
}

Pelota::Pelota() {
  x = aleatorio(MIN_X);
  y = aleatorio(MIN_Y);
  dx = aleatorio(100);
  dy = aleatorio(100);
  radio = UMBRAL/2;
  c = PColor::ROJO;
}

Pelota::Pelota(float x, float y, float dx, float dy, float radio, PColor c) {
  this->x = x;
  this->y = y;
  this->dx = dx;
  this->dy = dy;
  this->radio = radio;
  this->c = c;
}
