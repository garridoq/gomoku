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
	int over= 0;

	while(1){
		
		//We play
		m.board.print_board();
		std::cout << "Quel case voulez vous jouer ?\n";
		int legal_play = 0;
		while(legal_play != 1){
			std::cout << "x: ";
			std::cin >>	x;
			std::cout << "y: ";
			std::cin >> y;
			index = 8*(y-1) + 7 - x+1;
			if(m.board.is_legal_move(index,m.side) == 1 && x < 9 && x > 0 && y > 0 && y < 9){
				legal_play = 1;
			}
			else{
				std::cout << "Error, the square is alreay occupied or not on the board" << std::endl;
			}
		}
		m.side = side_to_play;
		m.index = index;
		if((over = is_game_over(board_after_move(m))))
			break;
		
		//AI play
		std::cout << "L'IA réfléchit" << std::endl;
		last.m = m;			
		get_best_move(&last, 4, &m, ALPHA_BETA);
		if((over = is_game_over(board_after_move(m))))
			break;
		m.board = board_after_move(m);
	}
}
