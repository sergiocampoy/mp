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
void reservar(Valor * array, int util_array){
}

/**
 * @brief libera el espacio reservado 
 * @param array vector de entreda/salida
 * @param util_array
 */
void liberar(Valor *array){
}

void leerContenido(Valor *coleccion, int  util){
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
void mostrarContenido(Valor const coleccion[], int util){
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
 * @return el numero de componentes del vector resultado
 */
int combinarSuma(Valor *coleccion1, int util1, Valor *coleccion2, int util2, Valor *resultado){

}
