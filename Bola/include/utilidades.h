#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "pelota.h"
#include "pelotas.h"
#include "definiciones.h"

void printPartida(std::ostream& fsalida, float ancho, float alto, const Pelotas& partida);

const char* colorToCadena(const PColor& c);

const PColor cadenaToColor(const char * cad);

#endif
