//Alumno1: Campoy Maldonado, Sergio
//Alumno2: Antúnez Martinaitis, Óscar

#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "pelota.h"
#include "pelotas.h"
#include "definiciones.h"

void printPartida(std::ostream& fsalida, float ancho, float alto, const Pelotas& partida);

const std::string colorToString(const PColor& c);

PColor stringToColor(std::string & cad);

#endif
