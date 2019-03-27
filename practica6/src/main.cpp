#include "utilidades.h"

int main () {
    const int TAM = 100;
    int totalUtilizados;
    int array [TAM];
    const int *resultado;
    int utilResultado;

    leerContenido (array, totalUtilizados);

   /* const int *min, *max;

    hallarMinMax (array, totalUtilizados, min, max);

    cout << "min: " << *min << ", max: " << *max << endl;*/

   obtenerMayorSecuenciaMonotonaCreciente (array, totalUtilizados, resultado, utilResultado);

   imprimirArray (resultado, utilResultado);
}
