CC = gcc

CFLAGS = -c -g -Wall
#VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes
BIN = bin
INC = -I../inc -I./
HEADER = ../inc
SRC = ../src
OBJ = obj
IFLAGS= $(INC) -I /usr/include/glib-2.0 -I /usr/lib/x86_64-linux-gnu/glib-2.0/include/ -I /user/lib/glib-2.0/include
LFLAGS = -lglib-2.0
CUNIT_LIB_DIR = -L/usr/lib 
CUNIT_INC_DIR = /usr/include/CUnit
AUT_INC = -I$(CUNIT_INC_DIR)

all: $(BIN)/lse_test

$(BIN)/lse_test: $(OBJ)/lse_test_main.o $(OBJ)/lse_test_functions.o $(OBJ)/localSearchEngine.o
	$(CC) $(OBJ)/lse_test_main.o $(OBJ)/lse_test_functions.o $(OBJ)/localSearchEngine.o -o minmax_test $(LFLAGS) $(CUNIT_LIB_DIR) -lcunit
	mv lse_test $(BIN)

$(OBJ)/lse_test_main.o: lse_test_main.c $(HEADER)/utility.h lse_test_functions.h
	$(CC) $(CFLAGS) lse_test_main.c $(IFLAGS) $(AUT_INC)
	mv lse_test_main.o $(OBJ)

$(OBJ)/lse_test_functions.o: lse_test_functions.c $(HEADER)/utility.h lse_test_functions.h
	$(CC) $(CFLAGS) lse_test_functions.c $(IFLAGS) $(AUT_INC)
	mv lse_test_functions.o $(OBJ)

$(OBJ)/localSearchEngine.o: $(SRC)/localSearchEngine.c $(HEADER)/utility.h
	$(CC) $(CFLAGS) $(SRC)/localSearchEngine.c $(IFLAGS)
	mv localSearchEngine.o $(OBJ)

