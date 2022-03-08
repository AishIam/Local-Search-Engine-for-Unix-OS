CC=gcc
BIN=../bin
SRC=../src
OBJ=../obj
INC=../inc
CFLAGS= -c -g -Wall
IFLAGS= -I $(INC)


$(BIN)/out:$(OBJ)/localSearchEngine.o $(OBJ)/utility.o
	$(CC)  $(LFLAGS) $(OBJ)/localSearchEngine.o $(OBJ)/utility.o -o $(BIN)/main

$(OBJ)/localSearchEngine.o:$(SRC)/localSearchEngine.c $(INC)/utility.h
	$(CC) $(CFLAGS) $(SRC)/localSearchEngine.c $(IFLAGS) 
	mv -f *.o $(OBJ)/

$(OBJ)/utility.o:$(SRC)/utility.c $(INC)/utility.h
	$(CC) $(CFLAGS) $(SRC)/utility.c $(IFLAGS)
	mv -f *.o $(OBJ)/

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/string_prg 
