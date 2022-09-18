CXX = g++

main: main.o lista.o no.o
	${CXX} main.o lista.o no.o -o main

main.o: main.cpp
	g++ -c main.cpp

lista.o: lista.cpp lista.hpp
	g++ -c lista.cpp

no.o: no.cpp no.hpp
	g++ -c no.cpp

.PHONY: clean run

run: main
	./main

clean:
	rm *.o main