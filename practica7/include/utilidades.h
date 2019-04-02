//
// Editado por acid 25/02/19
//

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>

#include "valor.h"

const int CAPACIDAD = 20;
/**
 * @brief lee un vector de valores
 * @param coleccion
 * @param util
 * @pre no hay valores repetidos en un vector
 */
void leerContenido(Valor coleccion[], int & util);

/**
 * @brief muestra el contenido de un vector de valores, numero de componentes y cada struct valor
 * @param coleccion vector de entrada
 * @param util numero de componentes validos
 */
void mostrarContenido( Valor const coleccion[], int util);

/**
* @brief muestra el contenido de un vector de valores, numero de c
* @param coleccion vector de punteros a los registros
* @param util numero de componentes validos
*/
void mostrarContenido( Valor const **coleccion, int util);
/**
* @brief monta un indice ordenado en orden creciente por el campo
* @param array contiene los registros tipo Valor
* @param parray vector de punteros a registros tipo Valor
* @param util numero de componentes validos en el vector de regist
*/
void ordenarPunteros(const Valor *array, const Valor **parray, int util);
#endif //UTILIDADES_H
