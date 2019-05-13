#ifndef PELOTA_H_
#define PELOTA_H_
enum class PColor {
  NEGRO,
  ROJO,
  VERDE,
  AZUL,
  AMARILLO,
  MAGENTA,
  CYAN,
  BLANCO
};

class Pelota {
private:
  float x, y; // Posición del centro de la pelota
  float dx, dy; // Velocidad de la pelota
  float radio; // Radio de la pelota
  PColor c; // Color de la pelota
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
  // Métodos
  float distancia(const Pelota& otra)const;
  bool colisionado(const Pelota& otra)const;
  void mover();
  void pintar();
};

#endif

// Clase pelotas

#ifndef PELOTAS_H_
#define PELOTAS_H_

class Pelotas {
private:
  Pelota* v;
  int capacidad;
  int util;
  Pelota* reservar(int n);
  void liberar(Pelota*& array);
public:
  // Constructores
  Pelotas();
  Pelotas(Pelota *v, int util);

  // Destructor
  ~Pelotas();

  inline int obtenerUtil()const {
    return util;
  }

  inline Pelota obtenerPelota(int indice)const {
    return v[indice];
  }

  void borrar(int indice);
  void aniadir(const Pelota& pelota);
};

#endif
