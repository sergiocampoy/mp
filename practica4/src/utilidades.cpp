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
void unico (double [], int ){
    
}
void concatenar( double [], int ,  double [], int , double [], int ){
    
}

