//
// Created by mgomez on 16/02/17.
// adapted by acid on 1/03/19
//

#include "utilidades.h"
using namespace std;


/**
 * @brief reserva el espacio para un vector de util_array componentes
 * @param array vector de entreda/salida
 * @param util_array
 */

void reservar(Valor *&array, int util_array) {
  array = new Valor [util_array];
}

/**
 * @brief libera el espacio reservado
 * @param array vector de entreda/salida
 * @param util_array
 */
void liberar(Valor *&array) {
  delete []array;
  array = nullptr;
}

void leerContenido(Valor *coleccion, int  util) {
  int fila,columna;
  double valor;

  if (coleccion != nullptr) {
    for(int i = 0; i < util; i++){
      cin >> fila;
      cin >> columna;
      cin >> valor;
      coleccion[i]= Valor(fila, columna, valor);
    }
  }

}
void mostrarContenido(Valor const coleccion[], int util) {
  cout << util << " ";
  for(int i=0; i < util; i++) {
    coleccion[i].mostrar();
    if(i < (util-1)){
      cout << " -- ";
    }
  }
  cout << endl;
}


/**
 * @brief Funcion para combinar elementos Valor, almacenados en dos vectores
 * @param coleccion1
 * @param util1
 * @param coleccion2
 * @param util2
 * @param resultado
 * @precond Suponemos que los valores en coleccion 1 y 2 son unicos
 * @return el numero de componentes del vector resultado
 */
int combinarSuma(Valor *coleccion1, int util1, Valor *coleccion2, int util2, Valor *&resultado) {
  int utilResultado = 0;
  resultado = nullptr;
  if (util1 + util2 > 0) {
    resultado = new Valor[util1 + util2];
    for (int i = 0; i < util1; i++) {
      resultado[i] = coleccion1[i];
    }
    utilResultado = util1;
    int pos;
    for (int posLectura = 0; posLectura < util2; posLectura++) {
      pos = buscarPareja(coleccion2[posLectura], resultado, utilResultado);
      if (pos != -1) {
        // Sumamos el resultado
        resultado[pos].valor += coleccion2[posLectura].valor;
      } else {
        // Añadimos otro valor
        resultado[utilResultado] = coleccion2[posLectura];
        utilResultado++;
      }
    }
  }
  return utilResultado;
}

int buscarPareja(const Valor &aBuscar, const Valor *array, int util) {
  int pos = -1;
  for (int i = 0; i < util && pos == -1; i++) {
    if (aBuscar.fila == array[i].fila && aBuscar.columna == array[i].columna) {
      pos = i;
    }
  }
  return pos;
}
