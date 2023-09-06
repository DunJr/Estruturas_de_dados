

main: main.o pilhaES.o
	g++ main.o pilhaES.o -o main

main.o: main.cpp
	g++ -c main.cpp

pilhaES.o: pilhaES.cpp pilhaES.hpp
	g++ -c pilhaES.cpp

.PHONY: clean run

run: main
	./main

clean:
	rm *.o main