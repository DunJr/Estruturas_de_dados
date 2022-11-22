CXX = g++

main: main.o grafo.o
	${CXX} main.o grafo.o -o main

main.o: main.cpp
	g++ -c main.cpp

grafo.o: grafo.cpp grafo.hpp
	g++ -c grafo.cpp
	

.PHONY: clean run

run: main
	./main

clean:
	rm *.o main