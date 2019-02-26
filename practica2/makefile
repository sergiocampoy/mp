# Makefile para el programa intervalo

#Declaracion de marcos
BIN=./bin
DOC=./doc
SRC=./src
OBJ=./obj
INCLUDE=./include
LIB=./lib
COMP=g++
NOM=practica2
ZIP=./zip

all : $(BIN)/intervalo_prog

$(BIN)/intervalo_prog : $(OBJ)/main.o
	$(COMP) -o $(BIN)/intervalo_prog $(OBJ)/main.o

$(OBJ)/main.o : $(SRC)/main.cpp $(INCLUDE)/intervalo.h
	$(COMP) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INCLUDE)

$(OBJ)/intervalo.o : $(SRC)/intervalo.cpp $(INCLUDE)/intervalo.h
	$(COMP) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INCLUDE)

$(LIB)/libinter.a : $(OBJ)/intervalo.o
	ar -rvs $(LIB)/libinter.a $(OBJ)/intervalo.o

clean :
	@echo "Limpiando archivos..."
	rm -f $(OBJ)/* $(BIN)/* $(LIB)/* $(DOC)/latex $(DOC)/html

zip : clean
	@echo "Generando ZIP..."
	zip -r $(ZIP)/$(NOM).zip *

doxy:
	doxygen $(DOC)/intervalo.doxy
