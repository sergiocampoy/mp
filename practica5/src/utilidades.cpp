#include "utilidades.h"

int localizarSubcadena (const char cadena[], const char subcadena[]) {
    int posLectura = 0;
    int pos2;
    bool encontrado = false;

    while (cadena[posLectura] != '\0' && !encontrado) {
        if (*subcadena == cadena[posLectura]) {
            pos2 = 0;

            while (subcadena[pos2] == cadena[posLectura + pos2] &&
                   cadena[posLectura + pos2] != '\0' &&
                   subcadena[pos2] != '\0') {
                pos2++;
            }
            if (subcadena [pos2] == '\0') {
                encontrado = true;
            }
        }

        posLectura++;
    }

    if (encontrado) {
        // Corrige el posLectura++ que se produce en la última iteración
        posLectura--;
    }
    else {
        posLectura = -1;
    }

    return posLectura;
}
