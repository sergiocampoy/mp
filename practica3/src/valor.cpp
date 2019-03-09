
#include <iostream>
#include "valor.h"


    /**
     * Constructor por defecto
     */
    Valor::Valor():fila(0), columna(0), valor(-1){
    }

    /**
     * Constructor del struct
     * @param fila
     * @param columna
     * @param valor
     */
    Valor::Valor(int _fila, int _columna, double _valor){
        fila =_fila;
        columna =_columna;
        valor =_valor;
    }

    /**
     * Metodo paa mostrar el contenido de un elemento
     */
    void Valor::mostrar() const{
        std::cout << "{" << fila << ", " << columna << ", " << valor << "} ";
    }
