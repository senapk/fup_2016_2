all: main.o minha_lib.o
	g++ main.o minha_lib.o -o main
main.o: main.cpp minha_lib.h 
	g++ -c main.cpp
minha_lib.o: minha_lib.cpp minha_lib.h
	g++ -c minha_lib.cpp
	
