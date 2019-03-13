/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ejercicio1.cpp
 * Author: acid
 *
 * Created on 15 de febrero de 2019, 11:01
 */

#include <iostream>
#include "utilidades.h"
using namespace std;

/*
 * 
 */
int main()
{
    const int DIM_ARRAY_SALIDA=20; 
    
    double arraySalida[DIM_ARRAY_SALIDA], arrayL1[DIM_ARRAY_SALIDA/2], arrayL2[DIM_ARRAY_SALIDA/2];
    int utilArraySalida;
    int utilArrayL1, utilArrayL2;
    
    leer(arrayL1,utilArrayL1);
    leer(arrayL2,utilArrayL2);
    mezclarUnico(arrayL1,utilArrayL1,arrayL2,utilArrayL2, arraySalida, utilArraySalida);
    imprimirArray(arraySalida, utilArraySalida);

}

