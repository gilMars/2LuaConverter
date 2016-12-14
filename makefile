CC = g++
FLAGS = -O2 -Wall -std=c++11 -static-libstdc++ -pthread
INC = header
SRC = source
OBJ = obj
APP = Conversor
RE = release
	
main: filereader item
	$(CC) -c $(SRC)/$(APP).cpp -o $(OBJ)/$(APP).o -I$(INC) -O2 -Wall -std=c++11
	$(CC) -o $(RE)/$(APP).exe $(OBJ)/$(APP).o $(OBJ)/filereader.o $(OBJ)/item.o  -I$(INC) $(FLAGS)

filereader: $(INC)/filereader.h $(SRC)/filereader.cpp
	$(CC) -c $(SRC)/filereader.cpp -o $(OBJ)/filereader.o -I$(INC) -O2 -Wall -std=c++11
	
item: $(INC)/item.h $(SRC)/item.cpp
	$(CC) -c $(SRC)/item.cpp -o $(OBJ)/item.o -I$(INC) -O2 -Wall -std=c++11

.SILENT:clean	
clean:
ifeq ($(OS),Windows_NT)
	del /Q $(RE)\*.exe $(OBJ)\*.o
else
	rm $(RE)/*.exe $(OBJ)/*.o
endif