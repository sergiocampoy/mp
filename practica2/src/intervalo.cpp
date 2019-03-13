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
    // Si no es válido, no modifica el intervalo
    if (valido (cinf, csup, cerrinf, cerrsup)) {
        cotaInf = cinf;
        cotaSup = csup;
        cerradoInf = cerrinf;
        cerradoSup = cerrsup;
    }
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

void comprobarVacio (Intervalo i) {
    escribir (i);
    if (i.esVacio())
        cout << " es vacio" << endl;
    else
        cout << " no es vacio" << endl;
}

//COMPLETAR TOMANDO COMO REFERENCIA .h

bool Intervalo::esVacio ()const {
    return ((cotaInf == cotaSup) && (cerradoInf == false) && (cerradoInf == false));
}

bool Intervalo::estaDentro (double n)const {
    bool flag = false;

    if (cotaInf < n && n < cotaSup)
        flag = true;
    if (n == cotaInf && cerradoInf)
        flag = true;
    if (n == cotaSup && cerradoSup)
        flag = true;

    return flag;
}

Intervalo interseccion(Intervalo i1, Intervalo i2) {
    double cotaInf, cotaSup;
    bool cerradoInf, cerradoSup;

    // Cálculo de la cota inferior
    if (i1.getCotaInf() > i2.getCotaInf()) {
        cotaInf = i1.getCotaInf();
        cerradoInf = i1.dentroCotaInf();
    }
    else if (i2.getCotaInf() > i1.getCotaInf()) {
        cotaInf = i2.getCotaInf();
        cerradoInf = i2.dentroCotaInf();
    }
    else {
        cotaInf = i1.getCotaInf();
        cerradoInf = (i1.dentroCotaInf() && i2.dentroCotaInf());
    }

    // Cálculo de la cota superior
    if (i1.getCotaSup() < i2.getCotaSup()) {
        cotaSup = i1.getCotaSup();
        cerradoSup = i1.dentroCotaSup();
    }
    else if (i2.getCotaSup() < i1.getCotaSup()) {
        cotaSup = i2.getCotaSup();
        cerradoSup = i2.dentroCotaSup();
    }
    else {
        cotaSup = i1.getCotaSup();
        cerradoSup = (i1.dentroCotaSup() && i2.dentroCotaSup());
    }

    return (Intervalo (cotaInf, cotaSup, cerradoInf, cerradoSup));
}
