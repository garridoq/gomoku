#ifndef MOVE_TREE_H
#define MOVE_TREE_H

#include "move.hpp"

struct node{

		node* parent = nullptr;
		move m;
		node** children = nullptr;
};

void gen_children(node* n);



#endif
