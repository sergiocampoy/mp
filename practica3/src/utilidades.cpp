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


int combinarSuma(const Valor coleccion1 [], int util1, const Valor coleccion2 [], int util2, Valor resultado []) {
    // Copia los datos de coleccion1 a resultado
    for (int i = 0; i < util1; i++) {
        resultado [i] = coleccion1 [i];
    }
    int totalUtilizados = util1;
    
    int posicion;

    for (int i = 0; i < util2; i++) {
        if (buscarPareja (resultado, util1, coleccion2 [i], posicion))
            // Modifica el valor
            resultado [posicion].valor += coleccion2 [i].valor;
        else {
            // Añade un nuevo objeto al array
            resultado [totalUtilizados] = coleccion2 [i];
            totalUtilizados++;
        }
    }

    return totalUtilizados;
}

bool buscarPareja (const Valor vector [], int totalUtilizados, const Valor & aBuscar, int & posicion) {

    bool encontrado = false;

    for (int i = 0; i < totalUtilizados && !encontrado; i++) {
        if (vector [i].fila == aBuscar.fila) {
            if (vector [i].columna == aBuscar.columna) {
                encontrado = true;
                posicion = i;
            }
        }
    }

    return encontrado;
}
