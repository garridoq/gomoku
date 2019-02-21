#include <iostream>
#include "Board.hpp"
#include "move_tree.hpp"
#include "move.hpp"
int main(){
	
	Board board{};

	int side_to_play = WHITE;
	move m;
	m.board = board;
	int x = 0;
	int y = 0;
	int index = 0;
	node last;
	
	while(1){
		
		//We play
		m.board.print_board();
		std::cout << "Quel case voulez vous jouer ? \nx: ";
		std::cin >>	x;
		std::cout << "y: ";
		std::cin >> y;
		index = 8*y + 7 - x;

		m.side = side_to_play;
		m.index = index;
		
		//AI play
		std::cout << "L'IA réfléchit" << std::endl;
		last.m = m;			
		get_best_move(&last, 2, &m, ALPHA_BETA);
		m.board = board_after_move(m);
	}
}
