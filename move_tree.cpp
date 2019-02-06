#include "move_tree.hpp"
#include <iostream>

void gen_children(node* n){
		// Generates the children moves for a node
		int bit;
		unsigned int side = 1 - (n->m.side);
		U64 available_squares = board_after_move(n->m).get_available_squares();
		U64 squares = available_squares;
		//Counts the number of ones (available squares for our children number
		int nb_ones = 0;
		std::cout << available_squares << std::endl;
		while(squares != 0){
			bit = squares & 1;
			if(bit == 1)
				nb_ones++;
			squares >>= 1;
		}
		std::cout << "we have " << nb_ones << " possible moves\n" << std::endl;

		// Generates all children
		// may be errors of same references for the board in multiple moves
		n->children = std::vector<node>(nb_ones);
		int i = 0;
		int j = 0;
		while(available_squares != 0){
			bit = available_squares & 1;
			if(bit == 1){
				std::cout << "Creating child move :" << i <<" Side:"  << side << std::endl;
				n->children[j].parent = n;
				n->children[j].m.board = board_after_move(n->m);	
				n->children[j].m.index = i;
				n->children[j].m.side = side;
				j++;
			}
			available_squares >>= 1;
			i++;
		}
}

void print_node(node* n){
	for(int i = 0; i < n->children.size(); ++i){
		std::cout << "Children " << i << ":\n"<<std::endl;
		board_after_move(n->children[i].m).print_board();		
	}
}
