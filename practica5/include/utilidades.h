//Alumno1: Campoy Maldonado, Sergio
//Alumno2: Antunez Martinaitis, Oscar

#ifndef _UTILIDADES_H_
#define _UTILIDADES_H_

/**
 * @brief comprueba si subcadena esta contenida en cadena y devuelve la posición
 * @param cadena
 * @param subcadena
 * @return posición donde se encuentra o @retval -1 si no se encuentra
 */
int localizarSubcadena (const char cadena[], const char subcadena[]);

/**
 * @brief
 * @param cadenaBase cadena en la que se hace la insercion
 * @param aInsertar cadena a insertar
 * @param posicion posicion en cadenaBase donde se hace la insercion
 * @param resultado cadena resultante (se asume con tam. suficiente)
 * @return
 *///Algoritmo que copia cadenaBase a resultado y en funcion de que si posicion
    //es valido, inserta aInsertar. Devuelve un bool segun si se ha procesado 
    //correctamente
bool insertarCadena (const char cadenaBase[], const char aInsertar[], int posicion, char resultado[]);

#endif
