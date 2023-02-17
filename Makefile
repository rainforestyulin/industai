CC=g++
OBJ=bench_tools
CFLAGS = -std=c++11
PATH = ./
SRC = $(PATH)$(OBJ).cc
#bench_tools:bench_tools.cc
#	g++ -std=c++11 bench_tools.cc -o bench_tools
OBJ:$(SRC)
	$(CC) $(CFLAGS)  $(SRC) -o $(OBJ) 
clean:
	rm $(OBJ)
