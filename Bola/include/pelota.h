#ifndef PELOTA_H_
#define PELOTA_H_

#include <iostream>
#include <definiciones.h>


class Pelota {

  // Funciones amigas
  friend void colisionar(Pelota& una, Pelota& otra);
  friend std::ostream& operator<<(std::ostream&, const Pelota&);
private:
  float x, y; // Posición del centro de la pelota
  float dx, dy; // Velocidad de la pelota
  float radio; // Radio de la pelota
  PColor c; // Color de la pelota
  // Métodos privados
  float aleatorio(float tope);
public:
  // Constructores
  Pelota();
  Pelota(float x, float y);
  Pelota(float x, float y, float dx = 1.0, float dy = 1.0,
         float radio = 10, PColor c = PColor::ROJO);

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
};

#endif
