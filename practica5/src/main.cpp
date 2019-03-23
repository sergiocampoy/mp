#include <iostream>
#include "utilidades.h"
using namespace std;

int main (){

    const int TAM = 100;

    /*// Se declarala cadena base
    char base[] = "cadena base para prueba de insercion";
    // Se declarala cadena que se inserta
    char aInsertar[] = "−agregado−";

    char resultado[TAM];

    int pos;

    cin >> pos;

    bool proceso;

    proceso = insertarCadena(base, aInsertar, pos, resultado);

    if(proceso){
        for(int i=0; resultado[i] != 0; i++){
            cout << resultado[i];
        }
    }
    else
        cout << "La insercion no ha sido posible, posicion invalida";*/
    
    char cadena[] = "Hola, primera cadena de ejemplo";
    //char subcadena[] = "no coincide";
    //char subcadena[] = "Hol";
    //char subcadena[] = "plo";
    //char subcadena[] = "cad";
    char subcadena[] = "cadenita";
    
    
    
    int pos_contenida;
    
    pos_contenida = localizarSubcadena(cadena, subcadena);
    
    if(pos_contenida >= 0){
        for(int i=0; subcadena[i] != '\0'; i++)
            cout << subcadena[i];
        
        cout << " es subcadena de ";
        
        for(int i=0; cadena[i] != '\0'; i++)
            cout << cadena[i];
    }
    else{
        for(int i=0; subcadena[i] != '\0'; i++)
            cout << subcadena[i];
        
        cout << " no es subcadena de ";
        
        for(int i=0; cadena[i] != '\0'; i++)
            cout << cadena[i];
    }

    return 0;
}
