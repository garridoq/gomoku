#ifndef EVALUATION_H
#define EVALUATION_H

#include "move.hpp"

int evaluate(move m);
int hasWon(U64 bitboard);
int determineScore(U64 *bitboards, int side);
int is_game_over(Board board);
#endif
