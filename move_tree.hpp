#ifndef MOVE_TREE_H
#define MOVE_TREE_H

#include <vector>
#include "move.hpp"
#include "evaluation.hpp"

struct node{

		node* parent = nullptr;
		move m;
		std::vector<node> children;
};

void gen_children(node* n);
void print_node(node* n);
int negamax(node* n, int depth, move* best_move);
move get_best_move(node* n, int depth);

#endif
