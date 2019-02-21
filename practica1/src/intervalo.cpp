#include "intervalo.h"
#include <iostream>

bool Intervalo::valido (double cinf, double csup, bool cerrinf, bool cerrsup) {
    return ((cinf < csup) || (cinf == csup && cerrinf == cerrsup));
}

Intervalo::Intervalo () {
    cotaInf = cotaSup = 0;
    cerradoInf = cerradoSup = false;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior)
:   cotaInf (cotaInferior), cotaSup (cotaSuperior),
    cerradoInf (false), cerradoSup (false)
{}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior)
:   cotaInf (cotaInferior), cotaSup (cotaSuperior),
    cerradoInf (cerradoInferior), cerradoSup (cerradoSuperior)
{}

double Intervalo::getCotaInf()const {
    return cotaInf;
}

double Intervalo::getCotaSup()const {
    return cotaSup;
}

bool Intervalo::dentroCotaInf()const {
    return cerradoInf;
}

bool Intervalo::dentroCotaSup()const {
    return cerradoSup;
}

void Intervalo::setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior) {
    cotaInf = cotaInferior;
    cotaSup = cotaSuperior;
    cerradoInf = cerradoInferior;
    cerradoSup = cerradoSuperior;
}

bool Intervalo::esVacio()const {
    bool flag = false;

    if (cotaInf == cotaSup && !cerradoInf && !cerradoSup)
        flag = true;

    return flag;
}

bool Intervalo::estaDentro(double n)const {
    bool flag = false;

    if (cerradoInf && cerradoSup)
        if (cotaInf <= n && n <= cotaSup)
            flag = true;

    else if (cerradoInf && !cerradoSup)
        if (cotaInf <= n && n < cotaSup)
            flag = true;

    else if (!cerradoInf && cerradoSup)
        if (cotaInf < n && n <= cotaSup)
            flag = true;
    else
        if (cotaInf < n && n < cotaSup)
            flag = true;

    return flag;
}

void escribir(const Intervalo & obj) {
    if (obj.esVacio())
        std::cout << "(0)";
    else {
        if (obj.dentroCotaInf())
         std::cout << '[';
        else std::cout << '(';
        std::cout << obj.getCotaInf() << "," << obj.getCotaSup();
        if (obj.dentroCotaSup())
            std::cout << ']';
        else std::cout << ')';
    }
}

void leer(Intervalo & obj){
    // Formato de lectura del intervalo: [|( x,y )|]
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;
    std::cin >> car;
    if (car == '(')
        cerradoInf = false;
    std::cin >> cotaInf;
    std::cin >> car;
    std::cin >> cotaSup;
    std::cin >> car;
    if (car == ')')
        cerradoSup = false;
    obj.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);
}

void comprobarVacio(Intervalo obj){
	 escribir(obj);
    if (obj.esVacio())
        std::cout << " Vacio";
    else  std::cout << " NO Vacio";
    std::cout << std::endl;
}
