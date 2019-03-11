/**
 * Fichero de implementacion de las funciones que se piden
 */
#include <iostream>
#include "utilidades.h"
using namespace std;

/**
 * @brief lee el vector y devuelve el numero de componentes en util_array
 * @param array
 * @param util_array
 */
void leer(double array[], int &util_array){
    cout << "Cuantos: ";
    cin >> util_array;
    for(int i=0; i<util_array; ++i)
    {
        cin >> array[i];
    }
    cout<<endl;
}

/**
@brief Escribe la longitud y los elementos del array en la salida estándar
@param array El array a imprimir
@param util_array Número de elementos útiles en el array
@pre array puede no contener ningun elemento
*/
void imprimirArray(const double array[],int util_array){
    cout << util_array << " ";
    for(int i=0; i<util_array; ++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void  mezclarUnico(double [], int ,  double [], int , double [], int  ){

}

void ordenar(double [], int , bool asc){

}

void unico (double array1 [], int &utilArray1) {
    int totalUtilizados = 1;
    bool duplicado;

    for (int i = 1; i < utilArray1; i++) {
        duplicado = false;

        for (int j = 0; j < totalUtilizados && !duplicado; j++)
//            duplicado = (array1 [i] == array1 [j]);
            if (array1 [i] == array1 [j])
                duplicado = true;

        if (!duplicado)
            array1 [totalUtilizados++] = array1 [i];
    }

    utilArray1 = totalUtilizados;
}

void concatenar(const double array1 [], int utilArray1, const double array2 [], int utilArray2, double arraySalida [], int &util_salida){
    for (util_salida = 0; util_salida < utilArray1; util_salida++)
        arraySalida [util_salida] = array1 [util_salida];

    for (; util_salida < utilArray1 + utilArray2; util_salida++)
        arraySalida [util_salida] = array2 [util_salida - utilArray1];
}
