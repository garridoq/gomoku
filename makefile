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

move_tree.o: move_tree.hpp Board.hpp
	g++ -c move_tree.cpp

main: main.o Board.o move.o evaluation.o move_tree.o
	g++ main.o Board.o move.o evaluation.o move_tree.o -o main
