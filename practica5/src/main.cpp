#include <iostream>
#include "utilidades.h"
using namespace std;

int main (){

    const int TAM = 100;

    // Se declarala cadena base
    char base[] = "cadena base para prueba de insercion";
    // Se declarala cadena que se inserta
    char aInsertar[] = "−agregado−";

    char resultado[TAM];

    int pos;

    cin >> pos;

    bool proceso;

    proceso = insertarCadena(base, aInsertar, pos, resultado);

    if(proceso){
        for(int i=0; resultado[i] != 0; i++){
            cout << resultado[i];
        }
    }
    else
        cout << "La insercion no ha sido posible";

    return 0;
}
