#ifndef MOVE_TREE_H
#define MOVE_TREE_H

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
int negamax(node* n, int depth);
void RootNegamax(node* n,int depth,node* best_node);
int get_best_move(node* n, int depth, move* best_move);

#endif
