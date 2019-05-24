#ifndef DEFINICIONES_H_
#define DEFINICIONES_H_

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

// TOGGLES
const bool FISICAS = false;
const bool LOAD = false;

// Físicas
const float FACTOR = 0.97; // Rebote

// Lectura del fichero
const char FICHERO[] = "data/pelotas.txt";
const char PALABRA_CLAVE[] = "MP-PELOTAS-T-1.0";

const float UMBRAL = 20.0; // Tamaño minimo del radio

// Dimensión mínima de la pantalla
const float MIN_X = 400.0;
const float MIN_Y = 300.0;

const float MAX_VEL = 10.0; // Velocidad terminal

#endif
