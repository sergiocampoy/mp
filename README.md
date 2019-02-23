# Metodología de la Programación

## *[Óscar Antúnez Martinaitis](https://github.com/oscarntnz "Perfil de github")* y *[Sergio Campoy Maldonado](https://github.com/sergioguaka "Perfil de github")*

![Imagen de Dios](https://pbs.twimg.com/media/Dklf765WsAAR3Tp.jpg)

## 1. [Pratica 1](./practica1) (22/02/19)
* Clase intervalo
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
