all: main test_move test_tree test_pattern test_eval test_won

clean:
	rm -r *.o

Board.o: Board.hpp Board.cpp
	g++ -std=c++14 -c Board.cpp -O3

move.o: move.hpp move.cpp Board.hpp
	g++ -std=c++14 -c move.cpp
	
evaluation.o: evaluation.hpp evaluation.cpp move.hpp patterns.hpp Pattern.hpp
	g++ -std=c++14 -c evaluation.cpp

main.o: Board.hpp main.cpp move_tree.hpp move.hpp
	g++ -std=c++14 -c main.cpp

Pattern.o: Pattern.hpp Pattern.cpp Board.hpp
	g++ -std=c++14 -c Pattern.cpp -O3

test_move.o: Board.hpp move.hpp test_move.cpp
	g++ -std=c++14 -c test_move.cpp

test_tree.o: Board.hpp move.hpp move_tree.hpp test_tree.cpp
	g++ -std=c++14 -c test_tree.cpp

test_eval.o: Board.hpp move.hpp move_tree.hpp test_eval.cpp
	g++ -std=c++14 -c test_eval.cpp -O3

test_won.o: Board.hpp move.hpp test_eval.cpp evaluation.hpp Pattern.hpp
	g++ -std=c++14 -c test_won.cpp -O3

move_tree.o: move_tree.hpp Board.hpp move_tree.cpp evaluation.hpp
	g++ -std=c++14 -c move_tree.cpp -O3

main: main.o Board.o move.o evaluation.o move_tree.o Pattern.o 
	g++ -std=c++14 main.o Board.o move.o evaluation.o move_tree.o Pattern.o -o main

test_move: test_move.o move.o Board.o
	g++ -std=c++14 test_move.o Board.o move.o -o test_move

test_tree: test_tree.o move.o Board.o move_tree.o evaluation.o Pattern.o
	g++ -std=c++14 test_tree.o Board.o move.o move_tree.o evaluation.o Pattern.o -o test_tree

test_eval: test_eval.o move.o Board.o move_tree.o evaluation.o Pattern.o
	g++ -std=c++14 test_eval.o Board.o move.o move_tree.o evaluation.o Pattern.o -o test_eval

test_won: test_won.o move.o Board.o evaluation.o Pattern.o
	g++ -std=c++14 test_won.o Board.o move.o evaluation.o Pattern.o -o test_won

test_pattern.o: test_pattern.cpp Pattern.hpp
	g++ -std=c++14 -c test_pattern.cpp -O3

test_pattern: test_pattern.o Pattern.o Board.o
	g++ -std=c++14 test_pattern.o Pattern.o Board.o -o test_pattern -O3
