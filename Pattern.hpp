#ifndef PATTERN_H
#define PATTERN_H

#include "Board.hpp"

//Patterns will be used as a convenient
//way to evaluate a position, and will
//mainly be represented by a 64 bit int
//representing a board.
//
//A pattern must start on the top left of 
//the board ( or as close to it as possible)
//which is the MSB of our board.
//
//for example:
//X-------
//-X------
//--------
//---X----
//--------
//--------
//--------
//Will be a pattern with a width of 3
//and a height of 3

struct Pattern{
	U64 board;
	int width;
	int height;
};

int pattern_match(U64 bitboard, Pattern pattern);
int pattern_match(U64 bitboard1, Pattern pattern1, U64 bitboard2, Pattern pattern2);


#endif
