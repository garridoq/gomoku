#ifndef PATTERNS_H
#define PATTERNS_H

#include "Pattern.hpp"
#include "Board.hpp"

Pattern winning_patterns[4] = {
	{ 0xF800000000000000ULL, 5, 1},
	{ 0x8080808080000000ULL, 1, 5},
	{ 0x8040201008000000ULL, 5 , 5},
	{ 0x810204080000000ULL, 5, 5 },
};

Pattern patterns_length_4[4] = {
	{ 0xF000000000000000ULL, 4, 1},
	{ 0x8080808000000000ULL, 1, 4},
	{ 0x8040201000000000ULL, 4, 4},
	{ 0x1020408000000000ULL, 4, 4},
};// shift all of 1 bit to account for the opponent check

Pattern patterns_length_4_opponent[4] = {
	{ 0x0800000000000000ULL, 4, 1},
	{ 0x8080808000000000ULL, 1, 4},
	{ 0x8040201000000000ULL, 4, 4},
	{ 0x1020408000000000ULL, 4, 4},
};//TODO

Pattern patterns_length_3[4] = {
	{ 0xE000000000000000ULL, 3, 1},
	{ 0x8080800000000000ULL, 1, 3},
	{ 0x8040200000000000ULL, 3, 3},
	{ 0x2040800000000000ULL, 3, 3},
}; // shift all of 1 bit to account for the opponent check

Pattern patterns_length_3_broken[8] = {
	{ 0xB000000000000000ULL, 4, 1},
	{ 0xD000000000000000ULL, 4, 1},
	//{ 0xA800000000000000ULL, 5, 1},
	{ 0x8000808000000000ULL, 1, 4},
	{ 0x8080008000000000ULL, 1, 4},
	//{ 0x8000800080000000ULL, 1, 5},
	{ 0x8000201000000000ULL, 4, 4},
	{ 0x8040001000000000ULL, 4, 4},
	//{ 0x8000200008000000ULL, 5, 5},
	{ 0x1000408000000000ULL, 4, 4},
	{ 0x1020008000000000ULL, 4, 4},
	//{ 0x800200080000000ULL, 5, 5},

};

Pattern patterns_length_2[4] = {
	{ 0xC000000000000000ULL, 2, 1},
	{ 0x8080000000000000ULL, 1, 2},
	{ 0x8040000000000000ULL, 2, 2},
	{ 0x4080000000000000ULL, 2, 2},
};

Pattern pattern_single_or_isolated = {0x8000000000000000ULL, 1, 1};

int value_coef[64] = {
		1,2,3,4,4,3,2,1,
		2,3,4,5,5,4,3,2,
		3,4,5,6,6,5,4,3,
		4,5,6,7,7,6,5,4,
		4,5,6,7,7,6,5,4,
		3,4,5,6,6,5,4,3,
		2,3,4,5,5,4,3,2,
		1,2,3,4,4,3,2,1
};



#endif
