CPP = g++
FLAGS = -fopenmp -pthread -std=c++17
SRC = Project2.cpp
EXE = ./a.out

exe:
	$(CPP) $(FLAGS) $(SRC) -o $(EXE)
all: exe
