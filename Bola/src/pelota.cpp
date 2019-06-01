// Clase pelota

#include "pelota.h"

#include "definiciones.h"
#include "utilidades.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

float Pelota::aleatorio(float tope) {
  return (rand() % (int)(tope));
}

Pelota::Pelota() {
  x = aleatorio(MIN_X);
  y = aleatorio(MIN_Y);
  dx = aleatorio(MAX_VEL);
  dy = aleatorio(MAX_VEL);
  radio = 30;
  c = PColor::VERDE;
}

Pelota::Pelota(float x, float y, float dx, float dy, float radio, PColor c) {
  this->x = x;
  this->y = y;
  this->dx = dx;
  this->dy = dy;
  this->radio = radio;
  this->c = c;
}

// Sobrecarga de operadores

// operator<< de Pelota
std::ostream& operator<<(std::ostream& fsalida, const Pelota& pelota) {
  fsalida << pelota.x << " " << pelota.y << " ";
  fsalida << pelota.dx << " " << pelota.dy << " ";
  fsalida << pelota.radio << " " << colorToString(pelota.c);
  return fsalida;
}

// operator>> de Pelota
const std::istream& operator>>(std::istream& fentrada, Pelota& pelota) {
  std::string cad;
  fentrada >> pelota.x >> pelota.y;
  fentrada >> pelota.dx >> pelota.dy;
  fentrada >> pelota.radio >> cad;
  pelota.c = stringToColor(cad);
  return fentrada;
}

// operator== de Pelota
bool Pelota::operator==(const Pelota& otra)const {
  return (radio == otra.radio && c == otra.c);
}
