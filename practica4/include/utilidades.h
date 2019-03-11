/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   utilidades.h
 * Author: acid
 *
 * Created on 15 de febrero de 2019, 11:07
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

/**
 * @brief lee el vector y devuelve el numero de componentes en util_array
 * @param array vector de entreda/salida
 * @param util_array
 */
void leer(double array[], int &util_array);
/**
@brief Escribe la longitud y los elementos del array en la salida estándar
@param array El array a imprimir
@param util_array Número de elementos útiles en el array
@pre array puede no contener ningun elemento
*/
void imprimirArray(const double array[],int util_array);
/**
 * @brief Realiza una mezcla sin introducir elementos comunes en arraySalida
 * @param array1 vector de entrada
 * @param utilArray1
 * @param array2 vector de entrada
 * @param utilArray2
 * @param arraySalida vector de salida
 * @param util_salida de salida
 * @pre los dos arrays deben estar ordenados
 */
void  mezclarUnico(double [], int ,  double [], int , double [], int  );
/**
 * @brief un método de ordenacion que reciba
 * @param v vecotr de double
 * @param util_v entero numero de elementos utiles
 * @param asc bool ascendente, false si es descendente
 */
void ordenar(double [], int , bool asc);

/**
 * @brief devuelve sobre el mismo vector el resultado sin valores repetidos
 * @param array1 vector de entrada/salida
 * @param utilArray1 numero de componentes actuales de salida
 */
void unico (double array1 [], int &utilArray1);

/**
 * @brief concatena en un tercer vector  el contenido de dos arrays
 * @param array1 vector de entrada
 * @param utilArray1
 * @param array2 vector de entrada
 * @param utilArray2
 * @param arraySalida vector de salida
 * @param util_salida numero de componentes de vector arraySalida,  de salida
 */
void concatenar(const double array1 [], int utilArray1, const double array2 [], int utilArray2, double arraySalida [], int &util_salida);


#endif /* UTILIDADES_H */
