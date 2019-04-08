# Metodología de la Programación :octocat:

## *[<img src="/data/viyuela_.png" width="50" height="50"/>Óscar Antúnez Martinaitis](https://github.com/oscarntnz "Perfil de github")* y *[<img src="/data/sgcm_.png" width="50" height="50"/>Sergio Campoy Maldonado](https://github.com/sergioguaka "Perfil de github")*




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

```makefile
# Copiar en todos los makefiles para entregar
zip: clobber
	rm -rf zip/*
	rm -rf dist/*
	rm -rf doc/html doc/latex
	zip -r zip/practicaX.zip * -x nbproject/private/*
```


## 4. [Práctica 4](./practica4) (15/03/19)
* Ordenación y concatenación de arrays

## 5. [Práctica 5](./practica5) (23/03/19)
* Búsqueda de subcadenas
* Inserción de cadenas en otras cadenas

## 6. [Práctica 6](./practica6) (29/03/19)
* Recorrido de arrays con punteros

## 7. [Práctica 7](./practica7) (05/04/19)
* Ordenación de un array de Valores con punteros

## 8. [Práctica 8](./practica8) (12/04/19)
* [Práctica 3](./practica3) pero con memoria dinámica
