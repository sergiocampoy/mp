#ifndef UTILIDADES_H_
#define UTILIDADES_H_

#include "pelota.h"
#include "pelotas.h"

float distancia(const Pelota & una, const Pelota & otra);

bool colision(const Pelota & una, const Pelota & otra);

void mover(int ancho, int alto, Pelota& pelota);

void mover(int ancho, int alto, Pelotas& pelotas);

void pintar(const Pelotas& pelotas);

void printPartida(float ancho, float alto, const Pelotas& partida);

#endif
