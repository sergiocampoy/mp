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

Pelotas();
Pelotas(Pelota *v, int util);
inline ~Pelotas() {
  liberar(v);
}
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
void borrar(int indice);
void aniadir(const Pelota& pelota);

#endif
