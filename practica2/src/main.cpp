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
/*
    const int CAPACIDAD = 10;
    int i, nintervalos=0;

    cout << "Cuantos intervalos (max 10):";

    cin >> nintervalos;

    cout << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]";
    for(i=0; i < nintervalos; i++)
        leer();

...
    escribir(resultado);
    }
*/
    Intervalo i1, i2;
/*
    cout << "Introduce 2 intervalos:" << endl;
    cout << "\tIntroduce el primer intervalo: ";
    leer(i1);
    cout << "\tIntroduce el segundo intervalo: ";
    leer(i2);
*/
    int n;
    cin >> n;

    leer (i1);
    leer (i2);

    Intervalo resultado = interseccion (i1, i2);

    escribir (resultado);
    cout << endl;
    return 0;
}
