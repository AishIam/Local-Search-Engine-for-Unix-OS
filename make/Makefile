CC=gcc
BIN=../bin
SRC=../src
OBJ=../obj
INC=../inc
IFLAGS= -I $(INC) -I /usr/include/glib-2.0 -I /usr/lib/x86_64-linux-gnu/glib-2.0/include/ -I /user/lib/glib-2.0/include 
CFLAGS= -c -g -Wall -Wno-unused-variable
LFLAGS = -lglib-2.0

#CFLAGS = -c -g -Wall pkg-config --cflags glib-2.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include pkg-config --libs glib-2.0 -L/usr/lib -lm -lglib-2.0

#all1:$(OBJ)/localSearchEngine.o

$(BIN)/out:$(OBJ)/utility.o $(OBJ)/localSearchEngine.o
	$(CC) $(OBJ)/localSearchEngine.o $(OBJ)/utility.o $(LFLAGS) -o $(BIN)/main

$(OBJ)/localSearchEngine.o:$(SRC)/localSearchEngine.c $(INC)/utility.h
	$(CC) $(SRC)/localSearchEngine.c $(IFLAGS) $(CFLAGS) 
	mv -f *.o $(OBJ)/

$(OBJ)/utility.o:$(SRC)/utility.c $(INC)/utility.h
	$(CC) $(SRC)/utility.c $(IFLAGS) $(CFLAGS)
	mv -f *.o $(OBJ)/

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/string_prg

splint:
	splint $(SRC)/localSearchEngine.c $(SRC)/utility.c $(IFLAGS) -DSPLINT_FLAG_ENABLED > splint_report	

valgrind:
	valgrind $(BIN)/main 2> valgrind_report
