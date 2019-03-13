// Alumno1: Antúnez Martinaitis Óscar
// Alumno1: Campoy Maldonado Sergio

/**
 * **
   @file intervalo.h
   @brief Se proporciona parte de la clase intervalo y es necesario revisar la declaración y definir la función intersección
   @author MP Grupos B, C de GIInformatica
   @warning Módulo no definitivo (creado para ser modificado)

 */

#ifndef _INTERVALO_H
#define _INTERVALO_H

class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;

    /**
     * @brief comprueba que los argumentos definen un intervalo correcto
     * cotaInferior <= cotaSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @return @retval true si correcto
     */
    bool valido(double,double, bool, bool);
public:
    /**
     *  @brief Intervalo vacio por defectoSup
     *  valorInf = valorSup & abiertoInf + abierto
     */
    Intervalo();
    /**
     * @brief Crea un Intervalo  cerrado por defecto
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    Intervalo(double cotaInferior, double cotaSuperior);
    /**
     * @brief Crea Intervalo
     * @param cerradoInferior
     * @param cerradoSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /**
     * @brief Devuelve la cota inferior del intervalo
     * @return El valor de la cota
     */
    double getCotaInf()const ;
    /**
     * @brief Devuelve la cota superior del intervalo
     * @return El valor de la cota
     */
    double getCotaSup()const ;
    /**
     * @brief Consulta si el intervalo es cerrado en su cota inferior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool dentroCotaInf()const ;
    /**
     * @brief Consulta si el intervalo es cerrado en su cota superior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool dentroCotaSup()const ;
    /**
     * @brief Define los valores del intervalo
     * @param cerradoInferior
     * @param cerradoSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    void setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /**
     * @brief Consulta si el intervalo almacenado es vacío o no
     * @return @retval true si es un intervalo vacío, @retval false en otro caso
     */
    bool esVacio()const ;
    /**
     * @brief Consulta si un determinado valor está dentro del intervalo
     * @param n El valor consultado
     * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso
     */
    bool estaDentro(double n)const ;

};

/**
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param i El intervalo
*/
void escribir(const Intervalo &i);

/**
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param i El intervalo
*/
void leer(Intervalo &i);
/**
* @brief Muestra un mensaje en pantalla indicando si el intervalo es vacío o no
* @param i El intervalo
*/
void comprobarVacio(Intervalo i);

/**
 * @brief realiza la interseccion de dos intervalos, puede resultar un intervalo vacío en caso de que no tengan cotas comunes, en caso contrario se revisan las cotas.
 * @param i1 primer intervalo de entrada
 * @param i2 segundo intervalo de entrada
 * @return devuelve el intervalo resultante de realizar la interseccion entre los dos intervalos de entrada
 */
Intervalo interseccion(Intervalo i1, Intervalo i2);
#endif
