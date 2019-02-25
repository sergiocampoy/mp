/** alumnos
 * **
   @file intervalo.cpp
   @brief Se proporciona parte de la clase intervalo falta completar un constructor y el método set, además es necesario revisar la declaración y definir la función intersección
   @author MP Grupos B, C de GIInformatica
   @warning Módulo no definitivo (creado para ser modificado buscar "...")

   Un ejemplo de ejecución es:

    Cuantos intervalos (max 10):5
    Introduce [ o ( cotaInferior, cotaSuperior ) o ]: [0,10] (0,10]
    Da como salida:  (0,10]

 */

#include <iostream>
#include "intervalo.h"

using namespace std;

bool Intervalo::valido(double cinf,double csup, bool cerrinf, bool cerrsup){
return (( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup));
}

Intervalo::Intervalo(){
  cotaInf = 0;
  cotaSup = 0;
  cerradoInf = false;
  cerradoSup = false;
}

Intervalo::Intervalo(double cinf,double csup): Intervalo(){
  if (valido(cinf,csup, true, true)){
    cotaInf = cinf;
    cotaSup = csup;
    cerradoInf = true;
    cerradoSup = true;
  }
}

Intervalo::Intervalo(double cinf,double csup, bool cerrinf, bool cerrsup) : Intervalo() {
    if (valido (cinf, csup, cerrinf, cerrsup)) {
        cotaInf = cinf;
        cotaSup = csup;
        cerradoInf = cerrinf;
        cerradoSup = cerrsup;
    }
}

double Intervalo::getCotaInf()const {
    return cotaInf ;
}

double Intervalo::getCotaSup()const {
    return cotaSup ;
}

bool Intervalo::dentroCotaInf()const {
    return cerradoInf;
}

bool Intervalo::dentroCotaSup()const {
    return cerradoSup;
}


void Intervalo::setIntervalo(double cinf, double csup, bool cerrinf, bool cerrsup){
//...
COMPLETAR
}

/*NO CAMBIAR */

void escribir(const Intervalo & obj) {
    if (obj.esVacio())
        cout << "(0)";
    else {
        if (obj.dentroCotaInf())
         cout << '[';
        else cout << '(';
        cout << obj.getCotaInf() << "," << obj.getCotaSup();
        if (obj.dentroCotaSup())
            cout << ']';
        else cout << ')';
    }
}

/*NO CAMBIAR  */

void leer(Intervalo & obj){
    // Formato de lectura del intervalo: [|( x,y )|]
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;
    cin >> car;
    if (car == '(')
        cerradoInf = false;
    cin >> cotaInf;
    cin >> car;
    cin >> cotaSup;
    cin >> car;
    if (car == ')')
        cerradoSup = false;
    obj.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);
}

//COMPLETAR TOMANDO COMO REFERENCIA .h
... interseccion()
