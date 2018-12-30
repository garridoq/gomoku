#include <iostream>
#include "Board.hpp"

int main(){
	
	Board board{};
	Board board2{0x101C2422200000ULL,0x2028201A00020200ULL};	
	
	board.print_board();
	std::cout <<"\n=============================\n" << std::endl;
	board2.print_board();

}
