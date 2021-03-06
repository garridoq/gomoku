#include "move_tree.hpp"
#include <iostream>
#include <limits>
#include "evaluation.hpp"

void gen_children(node* n){
		// Generates the children moves for a node
		if(hasWon(board_after_move(n->m).get_bitboards()[n->m.side]))
			return;
		int bit;
		unsigned int side = 1 - (n->m.side);
		U64 available_squares = board_after_move(n->m).get_available_squares();
		U64 squares = available_squares;
		//Counts the number of ones (available squares for our children number
		int nb_ones = 0;
		while(squares != 0){
			bit = squares & 1;
			if(bit == 1)
				nb_ones++;
			squares >>= 1;
		}
		// Generates all children
		// may be errors of same references for the board in multiple moves
		n->children = std::vector<node>(nb_ones);
		int i = 0;
		int j = 0;
		while(available_squares != 0){
			bit = available_squares & 1;
			if(bit == 1){
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

void copy_node(node* n_in, node* n_out){

	n_in->parent = n_out->parent;
	n_in->m = n_out->m;
	n_in->children = n_out->children;	
}

void print_node(node* n){
	for(int i = 0; i < n->children.size(); ++i){
		std::cout << "Children " << i << ":\n"<<std::endl;
		board_after_move(n->children[i].m).print_board();		
	}
}

int negamax(node* n, int depth){
	
	//Negamax is a version of minmax
	//based on the relation : max(a,b) = - min(-a,-b)
	//Allowing us to use only one routine
	//instead of two
	
	if(depth == 0){ 
		return evaluate(n->m);;
	}
	int max = -10000000;
	gen_children(n);
	for(auto &child : n->children){
	
		int score = -negamax(&child, depth-1);
		if(score > max){
			max = score;
		}
	}
	return max;
}

void rootNegamax(node* n,int depth,move* best_move){
	//This is the Rootcall of the negamax function
	//For a more complete decription, refer to the negamax function
	//
	//This root call will be used to get the best move
	//it is a simplified version of negamax where whe know
	//we wont evaluate a position right now.
	
	
	int max = -10000000;
	gen_children(n);
	for(auto &child : n->children){
	
		int score = -negamax(&child, depth-1);
		if(score > max){
			max = score;
			copy(best_move, &child.m);
		}
	}
}

int alphaBeta(node* n,int alpha, int beta, int depth){
	
	if(depth == 0)
		return -evaluate(n->m);	
	gen_children(n);
	if(n->children.empty()){
			return -evaluate(n->m);
	}
	for(auto &child : n->children){
		int score = -alphaBeta(&child,-beta, -alpha, depth-1);
		if(score >= beta)
			return beta;
		if(score > alpha)
			alpha = score;
	}
	return alpha;
}

void rootAlphaBeta(node* n, int alpha, int beta, int depth, move* best_move){
	
	gen_children(n);
	for(auto &child : n->children){
		int score = -alphaBeta(&child,alpha, beta, depth-1);
		if(score > alpha){
			alpha = score;
			copy(best_move, &child.m);	
		}
	}
}


int get_best_move(node* n, int depth, move* best_move, int algorithm){
	
	//Main function call to get the best move out
	//out of a position
	
	if(algorithm == NEGAMAX)
		rootNegamax(n, depth, best_move);
	else if(algorithm == ALPHA_BETA)
		rootAlphaBeta(n, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()-1, depth, best_move);
	else{
		std::cout << "Error : unknown move finding algorithm" << std::endl;
		return -1;
	}
	return 0;
}



