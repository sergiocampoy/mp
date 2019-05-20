#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "pelota.h"
#include "pelotas.h"
#include "definiciones.h"

float distancia(const Pelota & una, const Pelota & otra);

bool colisionado(const Pelota & una, const Pelota & otra);

void mover(int ancho, int alto, Pelota& pelota);

void mover(int ancho, int alto, Pelotas& pelotas);

void pintar(const Pelotas& pelotas);

void printPartida(std::ostream& fsalida, float ancho, float alto, const Pelotas& partida);

const char* colorToCadena(const PColor& c);

const PColor cadenaToColor(const char * cad);

#endif
