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
    
    cout << "Cuantos intervalos (max 10):";
...

    cout << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]";
    for(i=0; i < nintervalos; i++)
        leer(...);
    
...
    escribir(resultado);
    }
    return 0;   
}
