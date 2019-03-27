#include "utilidades.h"

void leerContenido(int *coleccion, int & util){
    do{
//      cout << "Introduce cuantos: ";
      cin >> util;
    }while (util > CAPACIDAD);

    for(int i = 0; i < util; i++){
        cin >> coleccion[i];
    }
}

/**
 * @brief Muestra los elementos del array en la salida estandar
 * @param array array a imprimir
 * @param utilArray numero de elementos utiles en el array
 * @pre array debería contener al menos un elemento
 */
void imprimirArray(const int *array, int utilArray) {
    cout << utilArray << ' ';
    for (int i = 0; i < utilArray; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

/**
  * @brief Obtiene un array con la secuencia más larga creciente de números enteros
  * @param array puntero a primer componente del array de entrada
  * @param utilArray numero de elementos utiles en el array
  * @param secuenciaCreciente puntero a primer componente de salida con la secuencia más larga creciente
  * @param util_secuenciaCreciente numero de elementos utiles en secuenciaCreciente
 */

void obtenerMayorSecuenciaMonotonaCreciente(const int *array, int utilArray, const int *&secuenciaCreciente, int &utilSecuenciaCreciente) {
    const int *p;           // Apuntador

    const int *posRacha;    // Pos inicio de la cadena con mejor racha temp
    posRacha = array;
    int utilRacha = 1;       // Longitud de la cadena con mejor racha temp

    secuenciaCreciente = array; // Pos inicio de la cadena con mejor racha
    utilSecuenciaCreciente = 1; // Longitud de la cadena con mejor racha


    for (p = array + 1; p < array + utilArray; p++) {
        if (*p > *(p-1)) {
            utilRacha++;
        }
        else {
            if (utilRacha > utilSecuenciaCreciente) {
                utilSecuenciaCreciente = utilRacha;
                secuenciaCreciente = posRacha;
            }
            utilRacha = 1;
            posRacha = p;
        }
    }

    if (utilRacha > utilSecuenciaCreciente) {
        utilSecuenciaCreciente = utilRacha;
        secuenciaCreciente = posRacha;
    }
}


void hallarMinMax(const int *array, int utilArray, const int *&pmin, const int *&pmax){
    const int *p;

    pmin = array;
    pmax = array;

    for (p = array; p < (array + utilArray); p++) {
        if (*p < *pmin)
            pmin = p;

        else if (*p > *pmax)
            pmax = p;
    }
}
