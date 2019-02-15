#ifndef MOVE_TREE_H
#define MOVE_TREE_H

#include <vector>
#include "move.hpp"

struct node{

		node* parent = nullptr;
		move m;
		std::vector<node> children;
};

void gen_children(node* n);
void print_node(node* n);

#endif
