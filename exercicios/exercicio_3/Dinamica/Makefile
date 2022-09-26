CXX = g++

main: main.o pilha.o no.o
	${CXX} main.o pilha.o no.o -o main

main.o: main.cpp
	g++ -c main.cpp

pilha.o: pilha.cpp pilha.hpp
	g++ -c pilha.cpp

no.o: no.cpp no.hpp
	g++ -c no.cpp

.PHONY: clean run

run: main
	./main

clean:
	rm *.o main