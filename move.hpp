#ifndef MOVE_H 
#define MOVE_H

#include "Board.hpp"

struct move{

	Board board;
	int index;
	int side;
	int evaluation = -1000000;
};

Board board_after_move(move m);

#endif
