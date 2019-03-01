/** profesor
 * **
   @file main.cpp
   @brief Se proporciona parte de la clase intervalo y es necesario revisar la declaración y definir la función intersección
   @author MP Grupos B, C de GIInformatica
   @warning Módulo definitivo (creado para no ser modificado)

   Un ejemplo de ejecución es:

    Cuantos intervalos (max 10):2
    Introduce [ o ( cotaInferior, cotaSuperior ) o ]: [0,10] (0,10]
    Da como salida:  (0,10]

 */

#include <iostream>

#include "intervalo.h"

using namespace std;


int main(){
    const int CAPACIDAD = 10;
    int i, nintervalos=0;
    Intervalo i1, i2, resultado;

    do {
//        cout << "Cuantos intervalos (max 10):";
        cin >> nintervalos;
    } while ((nintervalos < 2) || (nintervalos > CAPACIDAD));

//    cout << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]";

    leer (i1);
    // Lee un nuevo intervalo y hace la intersección entre este y el resultado anterior
    for(i=0; i < nintervalos - 1; i++) {
        leer(i2);
        resultado = interseccion (i1, i2);
        i1 = resultado;
    }

    escribir(resultado);
    cout << endl;
    return 0;
}
