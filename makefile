all: main

clean:
	rm -r *.o

Board.o: Board.hpp Board.cpp
	g++ -c Board.cpp

main.o: Board.hpp main.cpp
	g++ -c main.cpp

main: main.o Board.o
	g++ main.o Board.o -o main
