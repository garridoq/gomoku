#include <iostream>
#include "Board.hpp"
#include "move.hpp"
#include "evaluation.hpp"

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

  0000000001010101101010100101010110101010000000001010101001010101

  0000000010101010010101011010101001010101000000000101010110101010*/	

	Board board1{0x55AA55AA00AA55ULL,0xAA55AA550055AAULL};	
	
	std::cout << "\nBoard=================================\n" << std::endl;
	board1.print_board();

	move mv = {
		board1,
		63,
		WHITE
	};

  int won = hasWon(board_after_move(mv).get_bitboards()[mv.side]);
  int score = determineScore(board_after_move(mv).get_bitboards(), mv.side);

	
	std::cout << "Won ? :" << won << std::endl;
  std::cout << "score :" << score << std::endl;

}
