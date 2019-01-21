all: main

clean:
	rm -r *.o

Board.o: Board.hpp Board.cpp
	g++ -c Board.cpp

move.o: move.hpp move.cpp Board.hpp
	g++ -c move.cpp

evaluation.o: evaluation.hpp evaluation.cpp move.hpp
	g++ -c evaluation.cpp

main.o: Board.hpp main.cpp
	g++ -c main.cpp

main: main.o Board.o move.o evaluation.o
	g++ main.o Board.o move.o evaluation.o -o main
