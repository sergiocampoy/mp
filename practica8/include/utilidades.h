//
// Editado por acid 25/02/19
//

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>

#include "valor.h"


/**
 * @brief reserva el espacio para un vector de util_array componentes
 * @param array vector de entreda/salida
 * @param util_array
 */
void reservar(Valor *array, int util_array);

/**
 * @brief libera el espacio reservado 
 * @param array vector de entreda/salida
 * @param util_array
 */
void liberar(Valor *array);
/**
 * @brief rellena un vector de valores con util valores
 * @param coleccion
 * @param util parametro de entrada
 * @pre no hay valores repetidos en un vector
 */
void leerContenido(Valor coleccion[], int util);

/**
 * @brief muestra el contenido de un vector de valores, numero de componentes y cada struct valor
 * @param coleccion vector de entrada
 * @param util numero de componentes validos
 */
void mostrarContenido( Valor const coleccion[], int util);

/**
 * @brief Funcion para combinar elementos Valor, almacenados en dos vectores
 * @param coleccion1
 * @param util1
 * @param coleccion2
 * @param util2
 * @param resultado
 * @return el numero de componentes del vector resultado
 */
int combinarSuma(Valor *coleccion1, int util1, Valor  *coleccion2, int util2, Valor *resultado);
#endif //UTILIDADES_H
