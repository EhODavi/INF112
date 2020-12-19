all: vetorInteiros.o main.o
	g++ -o main vetorInteiros.o main.o

vetorInteiros.o: vetorInteiros.cpp vetorInteiros.h
	g++ -c vetorInteiros.cpp

main.o: main.cpp
	g++ -c main.cpp
