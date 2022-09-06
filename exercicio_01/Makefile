

main: main.o lista_seq.o
	g++ main.o lista_seq.o -o main

main.o: main.cpp
	g++ -c main.cpp

lista_seq.o: lista_seq.cpp lista_seq.hpp
	g++ -c lista_seq.cpp

.PHONY: clean run

run: main
	./main

clean:
	rm *.o main