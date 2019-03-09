# Metodología de la Programación :octocat:

## *[<img src="/data/viyuela.png" width="50" height="50"/>Óscar Antúnez Martinaitis](https://es.pornhub.com/users/oscarntnz "Perfil de github")* y *[<img src="/data/sgcm.png" width="50" height="50"/>Sergio Campoy Maldonado](https://github.com/sergioguaka "Perfil de github")*




## 1. [Prática 1](./practica1) (22/02/19)
* Clase intervalo

    Implementa la clase intervalo básica
* Compilación separada (ubuntu)

```shell
# Crea ficheros objeto
g++ -c -std=c++11 src/*.cpp -o obj/*.o -Iinclude

# Crea librerías a partir de los objetos
ar rvs lib/*.a obj/*.o

# Crea el binario
g++ src/main.cpp -l* -o bin/*.bin -Llib

# Ejecuta el binario
./bin/*.bin
```

## 2. [Práctica 2](./practica2) (01/03/19)
* Clase intervalo II

    Añade el método interseccion a la clase intervalo de la prática 1
* Makefile

```makefile
regla : dependencias
    comando

# Ejecutar makefile
make nombreRegla
```

## 3. [Práctica 3](./practica3) (08/03/19)
* Struct valor
* [NetBeans](https://netbeans.org "Yay")


## 4. [Práctica 4](./practica4) (15/03/19)
* Ordenación y concatenación de arrays

```c++
#include "pepeViyuela.h"
```
