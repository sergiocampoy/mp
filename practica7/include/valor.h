
#ifndef VALOR_H
#define VALOR_H

#include <iostream>


struct Valor{
    int fila;
    int columna;
    double valor;
Valor();
Valor(int , int, double );
void mostrar() const; 
};
#endif //VALOR_H
