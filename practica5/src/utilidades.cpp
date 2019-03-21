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
    int utilResultado = 0;
    bool flag = false;
    
    while(cadenaBase[utilBase] != '/0'){    //Calcular util de la cadena base
        utilBase++;
    }
    
    if(posicion >=0 && posicion <= utilBase){
        
        int pos_base = 0;
        
        for(; pos_base < posicion; pos_base++){
            resultado[pos_base] = cadenaBase[pos_base];
            utilResultado++;
        }
        
        for(int pos_insertada = 0; aInsertar[utilResultado] != '/0'; pos_insertada++){
            resultado[utilResultado] = aInsertar[pos_insertada];
            utilResultado++;
            pos_base++;
        }
        
        for(; cadenaBase[pos_base] != '/0'; utilResultado++){
            resultado[utilResultado] = cadenaBase[pos_base];
            pos_base++;
        }
        
        flag = true;
    }
    
    return flag;
}
