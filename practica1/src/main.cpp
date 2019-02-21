#include <iostream>
#include "intervalo.h"
using namespace std;

int main(){
    const int CAPACIDAD = 10;
    int i, nintervalos, nvalores;
    Intervalo vacio;
    Intervalo punto(1,1); // intervalo formado por un punto
    Intervalo interv[CAPACIDAD];
    double v[CAPACIDAD];

    cout << "Cuantos intervalos (max 10):";
    do{
        cin >> nintervalos;
    } while (nintervalos >10);

    cout << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]";
    for(i=0; i < nintervalos; i++)
        leer(interv[i]);

    cout << "Cuantos valores reales (max 10):";
    do{
        cin >> nvalores;
    } while (nvalores >10);

    cout << "Introduce valor real: ";
    for(i = 0; i < nvalores; i++)
        cin >> v[i];

    for(i = 0; i < nintervalos; i++){
      escribir(interv[i]);
      cout << " : ";
      for (int j = 0; j < nvalores; j++){
        if (interv[i].estaDentro(v[j]))
            cout << v[j] <<" ";
      }
      cout << endl;
    }
}
