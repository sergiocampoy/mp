#include <iostream>
# include "utilidades.h"

int main() {
    const int CAPACIDAD = 20;
    Valor array1[CAPACIDAD/2];
    Valor array2[CAPACIDAD/2]; // ={Valor(0, 0, 10), Valor(1, 1, 0.3), Valor(1, 2, 4.3), Valor(2, 2, 1.5), Valor(3, 2, 0.25)};
    Valor resultado1[CAPACIDAD];
    int util1, util2;

    leerContenido(array1, util1);
    mostrarContenido(array1, util1);
    leerContenido(array2, util2);
    mostrarContenido(array2, util2);
    int utilR = combinarSuma(array1, util1, array2, util2, resultado1);
    mostrarContenido(resultado1, utilR);
}