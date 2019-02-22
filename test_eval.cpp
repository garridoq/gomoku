#include <iostream>
#include "Board.hpp"
#include "move.hpp"
#include "move_tree.hpp"

int main(){
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
	get_best_move(&last, 3, &best_move, ALPHA_BETA);

	std::cout << "=================Best move==============\n" << std::endl;
	board_after_move(best_move).print_board();

}
