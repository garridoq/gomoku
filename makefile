all: main test_move test_tree test_pattern

clean:
	rm -r *.o

Board.o: Board.hpp Board.cpp
	g++ -c Board.cpp -O3

move.o: move.hpp move.cpp Board.hpp
	g++ -c move.cpp

evaluation.o: evaluation.hpp evaluation.cpp move.hpp
	g++ -c evaluation.cpp

main.o: Board.hpp main.cpp
	g++ -c main.cpp

Pattern.o: Pattern.hpp Pattern.cpp Board.hpp
	g++ -c Pattern.cpp -O3

test_move.o: Board.hpp move.hpp test_move.cpp
	g++ -c test_move.cpp

test_tree.o: Board.hpp move.hpp move_tree.hpp test_tree.cpp
	g++ -c test_tree.cpp

move_tree.o: move_tree.hpp Board.hpp move_tree.cpp
	g++ -c move_tree.cpp

main: main.o Board.o move.o evaluation.o move_tree.o
	g++ main.o Board.o move.o evaluation.o move_tree.o -o main

test_move: test_move.o move.o Board.o
	g++ test_move.o Board.o move.o -o test_move

test_tree: test_tree.o move.o Board.o move_tree.o
	g++ test_tree.o Board.o move.o move_tree.o -o test_tree

test_pattern.o: test_pattern.cpp Pattern.hpp
	g++ -c test_pattern.cpp -O3

test_pattern: test_pattern.o Pattern.o Board.o
	g++ test_pattern.o Pattern.o Board.o -o test_pattern -O3
