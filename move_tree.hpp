#ifndef MOVE_TREE_H
#define MOVE_TREE_H

#define ALPHA_BETA 1
#define NEGAMAX 0

#include <vector>
#include "move.hpp"
#include "evaluation.hpp"

typedef struct node{

		node* parent = nullptr;
		move m;
		std::vector<node> children;
}Node;

void gen_children(node* n);
void copy_node(node* n_in, node* n_out);
void print_node(node* n);
//Negamax
int negamax(node* n, int depth);
void rootNegamax(node* n,int depth,move* best_move);

//Alpha Beta
int alphaBeta(node* n,int alpha, int beta, int depth);
void rootAlphaBeta(node* n, int alpha, int beta, int depth, move* best_move);

int get_best_move(node* n, int depth, move* best_move, int algorithm);

#endif
