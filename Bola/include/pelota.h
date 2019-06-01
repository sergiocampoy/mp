//Alumno1: Campoy Maldonado, Sergio
//Alumno2: Antúnez Martinaitis, Óscar

#ifndef PELOTA_H_
#define PELOTA_H_

#include "definiciones.h"

#include <iostream>

class Pelota {
  // Funciones amigas
  friend float distancia(const Pelota&, const Pelota&);
  friend bool colisionado(const Pelota&, const Pelota&);
  friend void colisionar(Pelota&, Pelota&);
  friend void mover(int, int, Pelota&);
  friend void pintar(const Pelota&);

  // Sobrecarga entrada/salida
  friend std::ostream& operator<<(std::ostream&, const Pelota&);
  friend const std::istream& operator>>(std::istream&, Pelota&);
private:
  float x, y; // Posición del centro de la pelota
  float dx, dy; // Velocidad de la pelota
  float radio; // Radio de la pelota
  PColor c; // Color de la pelota
  // Métodos privados
  float aleatorio(float tope);
  float aleatorio(float, float);
public:
  // Constructores
  Pelota();
  Pelota(float x, float y, float dx = 1.0, float dy = 1.0,
         float radio = 30, PColor c = PColor::ROJO);

  // Métodos get
  inline float getX()const {
    return x;
  }
  inline float getY()const {
    return y;
  }
  inline float getDx()const {
    return dx;
  }
  inline float getDy()const {
    return dy;
  }
  inline float getRadio()const {
    return radio;
  }
  inline PColor getColor()const {
    return c;
  }

  // Métodos set
  inline void setX(float x){
      this->x=x;
  }
  inline void setY(float y){
      this->y=y;
  }
  inline void setDx(float dx){
      this->dx=dx;
  }
  inline void setDy(float dy){
      this->dy=dy;
  }

  // Sobrecarga de operadores
  bool operator==(const Pelota&)const;
  inline bool operator!=(const Pelota& otra)const {
    return !(*this == otra);
  }
};

#endif
