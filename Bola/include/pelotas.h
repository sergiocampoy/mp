#ifndef PELOTAS_H_
#define PELOTAS_H_

#include <iostream>

class Pelotas {
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream&, const Pelotas&);

private:
  Pelota* v;
  int capacidad;
  int util;
  inline Pelota* reservar(int n) {
    Pelota* array = nullptr;
    array = new Pelota[n];
    return array;
  }
  inline void liberar(Pelota*& array) {
    if (array != nullptr) {
      delete[] array;
    }
  }
public:
// TODO operator= & copia
Pelotas();
Pelotas(int capacidad);
Pelotas(Pelota *v, int util);
Pelotas(const Pelotas& otra);
inline ~Pelotas() {
  liberar(v);
}
inline int getUtil(){
  return(util);
}
void borrar(int indice);
void aniadir(const Pelota& pelota);
void mover(int alto, int ancho);
};


#endif
