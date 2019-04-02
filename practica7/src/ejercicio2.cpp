#include <iostream>
#include "utilidades.h"
using namespace std;

int main() {
    Valor array[CAPACIDAD];
    const Valor *parray[CAPACIDAD];
    int util;

    leerContenido(array, util);
    cout << endl;
    mostrarContenido(array, util);
    ordenarPunteros(array, parray, util);
    mostrarContenido(parray, util);
}
