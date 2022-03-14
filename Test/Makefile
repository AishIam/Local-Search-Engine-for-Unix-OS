CC = gcc

CFLAGS = -Wall -c -g 
OFLAGS = -o
#VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes
BIN = bin/
INC = -I../inc/ -I./
HEADER = ../inc/
SRC = ../src/
OBJ = obj/
IFLAGS= $(INC) -I /usr/include/glib-2.0 -I /usr/lib/x86_64-linux-gnu/glib-2.0/include/ -I /user/lib/glib-2.0/include
LFLAGS = -lglib-2.0
CUNIT_LIB_DIR = -L/home/usr/local/lib/ 
CUNIT_INC_DIR = /home/usr/local/include/CUnit/
AUT_INC = -I$(CUNIT_INC_DIR)

all: $(BIN)lse_test

$(BIN)lse_test: $(OBJ)lse_test_main.o $(OBJ)lse_test_functions.o $(OBJ)utility.o
	$(CC) $(OFLAGS)lse_test $(OBJ)utility.o $(OBJ)lse_test_main.o $(OBJ)lse_test_functions.o $(LFLAGS) $(CUNIT_LIB_DIR) -lcunit
	mv lse_test $(BIN)

$(OBJ)lse_test_main.o: lse_test_main.c $(HEADER)utility.h lse_test_functions.h
	$(CC) $(CFLAGS) lse_test_main.c $(IFLAGS) ${AUT_INC}
	mv lse_test_main.o $(OBJ)

$(OBJ)lse_test_functions.o: lse_test_functions.c $(HEADER)utility.h
	$(CC) $(CFLAGS) lse_test_functions.c $(IFLAGS) ${AUT_INC}
	mv lse_test_functions.o $(OBJ)

$(OBJ)utility.o: $(SRC)utility.c $(HEADER)utility.h
	$(CC) $(CFLAGS) $(SRC)utility.c $(IFLAGS)
	mv utility.o $(OBJ)

clean:
	rm -f $(BIN)lse_test
	rm -f $(OBJ)*.o

