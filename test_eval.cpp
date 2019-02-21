#include <iostream>
#include "Board.hpp"
#include "move.hpp"
#include "move_tree.hpp"

int main(){

/*00000000
  01010101
  10101010
  01010101
  10101010
  00000000
  10101010
  01010101

  00000000
  10101010
  01010101
  10101010
  01010101
  00000000
  01010101
  10101010

  Board board1{0x55AA55AA00AA55ULL,0xAA55AA550055AAULL};	

  0000000001010101101010100101010110101010000000001010101001010101

10AA0F0000000 : 9
C5500E000000 : 9

  0000000010101010010101011010101001010101000000000101010110101010*/	

	Board board1{0xF000ULL,0x20400000080020ULL};	
	
	std::cout << "\nBoard=================================\n" << std::endl;
	board1.print_board();

	move mv = {
		board1,
		8,
		WHITE
	};

	node last;
	last.m = mv;
	
	std::cout << "Getting best move..." << std::endl;

	move best_move; 
	get_best_move(&last, 2, &best_move, ALPHA_BETA);

	std::cout << "=================Best move==============\n" << std::endl;
	board_after_move(best_move).print_board();

}
