/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on 25 de marzo de 2019, 9:46
 */

void hallarMinMax(const int *array, int utilArray, const int *&pmin, const int *&pmax){
    
    const int *p;
    pmin = array;
    pmax = array;
    
    for(p = array; p < (array+utilArray); p++){
        if(*p < *pmin)
            pmin = p;
        else if(*p > *pmax)
            pmax = p;
    }
}

void obtenerMayorSecuenciaMonotonaCreciente(const int *array, int utilArray,
                                            const int *&secuenciaCreciente, int &utilSecuenciaCreciente){
    
    secuenciaCreciente = array;             //Pos inicio cadena max
    int *p;                                 //Apuntador
    utilSecuenciaCreciente = 1;             //Long cadena max
    int *posRacha;                          //Pos inicio cadena auxiliar
    posRacha = array;
    int utilRacha = 1;
    
    for(p = array+1; (p+utilSecuenciaCreciente-1) < array+utilArray; p++){
        if(*(posRacha+p) >= *posRacha)
            utilRacha++;
        else{
            if(utilRacha > utilSecuenciaCreciente){
                utilSecuenciaCreciente = utilRacha;
                secuenciaCreciente = posRacha;
            }
            utilRacha = 1;
            posRacha = p;
        }
    }
    
    if(utilRacha > utilSecuenciaCreciente){
                utilSecuenciaCreciente = utilRacha;
                secuenciaCreciente = posRacha;
            }
}

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int v[] ={1,2,3,4,5};
    int util = 5;
    const int *min;
    const int *max;
    const int *
    
    hallarMinMax(v, util, min, max);
    
    cout << *min << " " << *max << endl<< endl;
    
    
    obtenerMayorSecuenciaMonotonaCreciente(v, util,)
    
    return 0;
}

