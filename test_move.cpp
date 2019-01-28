#include <iostream>
#include "Board.hpp"
#include "move.hpp"

int main(){
	
	Board board{};
	Board board2{0x101C2422200000ULL,0x2028201A00020200ULL};	
	
	Board board3{board2};
	
	
	std::cout << "\nBoard3=================================\n" << std::endl;
	board3.print_board();



	std::cout <<"\nBoard=============================\n" << std::endl;
	board.print_board();
	
	int x_move = 1;
	int y_move = 7;
	int bit = 8*y_move + (7-x_move);
	board2.make_move(bit, WHITE);
	std::cout <<"\nBoard2=============================\n" << std::endl;
	board2.print_board();

	std::cout << "===========Move===========\n" << std::endl;

	move mv = {
		board3,
		62,
		WHITE
	};

	Board board4 = board_after_move(mv);

	std::cout <<"\nBoard4=============================\n" << std::endl;
	board4.print_board();

	std::cout << "Board : "<< &board << "\nBoard2 : "<< &board2 << "\nBoard3 : "<< &board3 << "\nBoard4 : " << &board4 << std::endl;

}
