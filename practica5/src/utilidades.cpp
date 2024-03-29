#include "utilidades.h"

int localizarSubcadena (const char cadena[], const char subcadena[]) {
    int posLectura = 0;
    int pos2;
    bool encontrado = false;

    while (cadena[posLectura] != '\0' && !encontrado) {
        if (*subcadena == cadena[posLectura]) {
            pos2 = 0;

            while (subcadena[pos2] == cadena[posLectura + pos2] &&
                   cadena[posLectura + pos2] != '\0' &&
                   subcadena[pos2] != '\0') {
                pos2++;
            }
            if (subcadena [pos2] == '\0') {
                encontrado = true;
            }
        }

        posLectura++;
    }

    if (encontrado) {
        // Corrige el posLectura++ que se produce en la última iteración
        posLectura--;
    }
    else {
        posLectura = -1;
    }

    return posLectura;
}

bool insertarCadena (const char cadenaBase[], const char aInsertar[], int posicion, char resultado[]){

    int utilBase = 0;
    bool flag = false;
    

    while(cadenaBase[utilBase] != '\0'){    //Calcular util de la cadena base
        utilBase++;
    }
    
    if(posicion >=0 && posicion <= utilBase){

	int pos_base = 0;       //Apuntador de cadena base
        int utilResultado = 0;  //Util de cadena resultado
        
        for(; utilResultado < posicion; pos_base++){
            resultado[utilResultado] = cadenaBase[pos_base];
            utilResultado++;
        }
        
        for(int pos_insertada = 0; aInsertar[pos_insertada] != '\0'; pos_insertada++){
            resultado[utilResultado] = aInsertar[pos_insertada];
            utilResultado++;
        }
        
        for(; pos_base <= utilBase; pos_base++){
            resultado[utilResultado] = cadenaBase[pos_base];
            utilResultado++;
        }
        
        flag = true;
    }
    
    return flag;
}
