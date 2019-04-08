#
/*
 * File:   ejercicio1.cpp
 * Author: acid
 *
 * Created on 1 marzo de 2019, 11:01
 */

#include <iostream>
#include "utilidades.h"
#include "valor.h"
using namespace std;

/*
 *
 */
int main()
{

    Valor  *arrayL1 = nullptr, *arrayL2 = nullptr, *arraySalida = nullptr;
    int utilArraySalida;
    int utilArrayL1, utilArrayL2;

    cout << "Cuantos: ";
    do{
       cin >> utilArrayL1;
    } while(utilArrayL1 <0);

    reservar(arrayL1, utilArrayL1);
    leerContenido(arrayL1,utilArrayL1);

    cout << "Cuantos: ";
    do{
      cin >> utilArrayL2;
    } while(utilArrayL2 <0);

    reservar(arrayL2, utilArrayL2);
    leerContenido(arrayL2,utilArrayL2);

    utilArraySalida = combinarSuma(arrayL1,utilArrayL1,arrayL2,utilArrayL2, arraySalida);
    mostrarContenido(arraySalida, utilArraySalida);
    liberar(arrayL1);
    liberar(arrayL2);
    liberar(arraySalida);

}
