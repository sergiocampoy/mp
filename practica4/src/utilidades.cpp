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

int  mezclarUnico(const double array1[], int utilArray1, const double array2[],
                    int utilArray2, double resultado[], int & utilResultado){

    concatenar(array1, utilArray1, array2, utilArray2, resultado, utilResultado);
    unico(resultado, utilResultado);
    ordenar(resultado, utilResultado, true);


    int util = utilResultado;

    return util;

}

int  mezclarUnico2 (const double array1[], int utilArray1, const double array2[], int utilArray2, double resultado[], int & utilResultado){

int i = 0, j = 0;
utilResultado = 0;

// Escribe el primer valor en el vector resultado
if (utilArray1 > 0 && utilArray2 == 0) {
    resultado [utilResultado++] = array1 [i++];
}
else if (utilArray1 == 0 && utilArray2 > 0) {
    resultado [utilResultado++] = array2 [j++];
}
else if (utilArray1 > 0 && utilArray2 > 0) {
    if (array1 [i] < array2 [j]) {
        resultado [utilResultado++] = array1 [i++];
    }
    else {
        resultado [utilResultado++] = array2 [j++];
    }
}

// Bucle principal
while (i < utilArray1 && j < utilArray2) {
    if (array1 [i] < array2 [j]) {
        if (array1 [i] > resultado [utilResultado - 1]) {
            resultado [utilResultado++] = array1 [i];
        }
        i++;
    }
    else {
        if (array2 [j] > resultado [utilResultado - 1]) {
            resultado [utilResultado++] = array2 [j];
        }
        j++;
    }
}

// Caso: Sale del bucle principal por terminar array2
while (i < utilArray1) {
    if (array1 [i] > resultado [utilResultado - 1])
        resultado [utilResultado++] = array1 [i];
    i++;
}

// Caso: Sale del bucle principal por terminar array1
while (j < utilArray2) {
    if (array2 [j] > resultado [utilResultado - 1])
        resultado [utilResultado++] = array2 [j];
    j++;
}

return utilResultado;
}

/*
int  mezclarUnico2_OG (const double array1[], int utilArray1, const double array2[], int utilArray2, double resultado[], int & utilResultado) {
int i = 0, j = 0;
utilResultado = 0;

if (utilArray1 == 0 && utilArray2 == 0) {
    // No hacer nada
}
else if (utilArray1 == 0) {
    //
    resultado [utilResultado++] = array2 [j++];
}
else if (utilArray2 == 0) {
    resultado [utilResultado++] = array1 [i++];
}
else {
    if (array1 [i] == array2 [j]) {
        resultado [utilResultado++] = array1 [i];
        i++;
        j++;
    }
    else if (array1 [i] < array2 [j])
        resultado [utilResultado++] = array1 [i++];

    else
        resultado [utilResultado++] = array2 [j++];
}


while (i < utilArray1 && j < utilArray2) {
    if (resultado [utilResultado - 1] == array1 [i] && resultado [utilResultado - 1] == array2 [i]) {
        i++;
        j++;
    }
    else {
        if (array1 [i] == array2 [j]) {
            resultado [utilResultado++] = array1 [i];
            i++;
            j++;
        }
        else if (array1 [i] > resultado [utilResultado - 1])
            resultado [utilResultado++] = array1 [i++];
        else if (array2 [j] > resultado [utilResultado - 1])
            resultado [utilResultado++] = array2 [j++];
    }
}

while (i < utilArray1) {
    if (array1 [i] > resultado [utilResultado - 1])
        resultado [utilResultado++] = array1 [i];
    i++;
}

while (j < utilArray2) {
    if (array2 [j] > resultado [utilResultado - 1])
        resultado [utilResultado++] = array2 [j];
    j++;
}

int util = utilResultado;
return util;
}
*/
void ordenar(double array1[], int utilArray1, bool asc){

   double auxiliar;

   if(asc){
    for(int pos_escritura = 0; pos_escritura < utilArray1; pos_escritura++){
        for(int pos_lectura = 0; pos_lectura < utilArray1; pos_lectura++){
            if(array1[pos_lectura] > array1[pos_escritura]){
             auxiliar = array1[pos_escritura];
             array1[pos_escritura] = array1[pos_lectura];
             array1[pos_lectura] = auxiliar;
             }
         }
     }
   }
   else{
       for(int pos_escritura = 0; pos_escritura < utilArray1; pos_escritura++){
        for(int pos_lectura = 0; pos_lectura < utilArray1; pos_lectura++){
            if(array1[pos_lectura] < array1[pos_escritura]){
             auxiliar = array1[pos_escritura];
             array1[pos_escritura] = array1[pos_lectura];
             array1[pos_lectura] = auxiliar;
             }
         }
     }
   }
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
