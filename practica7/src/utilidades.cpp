//
// Created by mgomez on 16/02/17.
// editado by acid on 27/02/19
//

#include "utilidades.h"
using namespace std;

void leerContenido(Valor coleccion[], int & util){
    int fila,columna;
    double valor;
    cout << "Nuevo vector" << endl;
    do{
      cout << "Introduce cuantos: ";
      cin >> util;
    }while (util > CAPACIDAD/2);

    for(int i = 0; i < util; i++){
        cin >> fila;
        cin >> columna;
        cin >> valor;
        coleccion[i]= Valor(fila, columna, valor);
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

void mostrarContenido (Valor const **coleccion, int util) {

}

void ordenarPunteros (const Valor *array, const Valor **parray, int util) {

}
