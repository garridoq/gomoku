#ifndef PATTERN_H
#define PATTERN_H

#include "Board.hpp"

struct Pattern{
	U64 board;
	int width;
	int height;
};

int pattern_match(U64 bitboard, Pattern pattern);

#endif
