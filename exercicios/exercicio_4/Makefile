CXX = g++

main: main.o arv.o no.o
	${CXX} main.o arv.o no.o -o main

main.o: main.cpp
	g++ -c main.cpp

arv.o: arv.cpp arv.hpp
	g++ -c arv.cpp

no.o: no.cpp no.hpp
	g++ -c no.cpp

.PHONY: clean run

run: main
	./main

clean:
	rm *.o main