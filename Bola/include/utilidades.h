#ifdef UTILIDADES_H_
#define ULTIDADES_H_

#include <cmath>

float distancia(const Bola & una, const Bola & otra){
  return(sqrt((una.GetX-otra.GetX)*(una.GetX-otra.GetX)+(una.GetY-otra.GetY)*(una.GetY-otra.GetY)))
}

bool colision(const Bola & una, const Bola & otra){
  return(distancia(una, otra) <= una.radio+otra.radio)
}
