# decsai.ugr.es
# fecha: abr 26 2019

# Definición de macros para definir las carpetas de trabajo
BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc
# Opciones de compilación
# -Wall muestra todas las advertencias
# -g compila en modo "depuración"
OPT= -std=c++11 -Wall -g
# Nombre de la práctica
PRJ=Final2

# Las macros se usan en las reglas del makefile como si fuesen variables
# que se sustituyen por su valor definido anteriormente

all : $(BIN)/$(PRJ)

$(BIN)/$(PRJ) : $(OBJ)/main.o $(OBJ)/pelota.o $(OBJ)/pelotas.o $(OBJ)/simulador.o $(OBJ)/utilidades.o $(OBJ)/miniwin.o $(INC)/definiciones.h
	g++ -o $(BIN)/$(PRJ) $(OBJ)/main.o $(OBJ)/pelota.o $(OBJ)/pelotas.o $(OBJ)/simulador.o $(OBJ)/utilidades.o $(OBJ)/miniwin.o -I$(INC) -pthread -lX11

$(OBJ)/miniwin.o : $(SRC)/miniwin.cpp  $(INC)/miniwin.h
	g++ $(OPT) -c $(SRC)/miniwin.cpp -o $(OBJ)/miniwin.o -I$(INC)

$(OBJ)/pelota.o : $(SRC)/pelota.cpp $(INC)/pelota.h
	g++ $(OPT) -c $(SRC)/pelota.cpp -o $(OBJ)/pelota.o -I$(INC)

$(OBJ)/pelotas.o : $(SRC)/pelotas.cpp $(INC)/pelotas.h $(OBJ)/pelota.o
	g++ $(OPT) -c $(SRC)/pelotas.cpp -o $(OBJ)/pelotas.o -I$(INC)

$(OBJ)/simulador.o : $(SRC)/simulador.cpp $(INC)/simulador.h $(OBJ)/pelotas.o
	g++ $(OPT) -c $(SRC)/simulador.cpp -o $(OBJ)/simulador.o -I$(INC)

$(OBJ)/utilidades.o : $(SRC)/utilidades.cpp $(INC)/utilidades.h $(OBJ)/pelotas.o $(INC)/definiciones.h
	g++ $(OPT) -c $(SRC)/utilidades.cpp -o $(OBJ)/utilidades.o -I$(INC)

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/miniwin.h $(INC)/definiciones.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

clean:
	@echo "Limpiando ... "
	rm -rf $(OBJ)/*.o $(BIN)/*
