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
};// not shifted version

Pattern patterns_length_4_playing[4] = {
	{ 0x7800000000000000ULL, 5, 1},
	{ 0x0080808080000000ULL, 1, 5},
	{ 0x0040201008000000ULL, 5, 5},
	{ 0x0008102040000000ULL, 6, 6},
};

Pattern patterns_length_4_opponent_v1[4] = {
	{ 0x8000000000000000ULL, 1, 1},
	{ 0x8000000000000000ULL, 1, 1},
	{ 0x8000000000000000ULL, 1, 1},
	{ 0x0400000000000000ULL, 6, 6},
};

Pattern patterns_length_4_opponent_v2[4] = {
	{ 0x0400000000000000ULL, 4, 1},
	{ 0x0000000000800000ULL, 1, 4},
	{ 0x0000000000040000ULL, 4, 4},
	{ 0x0000000000800000ULL, 6, 6},
};

Pattern patterns_length_4_broken[12] = {
	{ 0xB800000000000000ULL, 5, 1},
	{ 0xD800000000000000ULL, 5, 1},
	{ 0xE800000000000000ULL, 5, 1},

	{ 0x8000808080000000ULL, 1, 5},
	{ 0x8080008080000000ULL, 1, 5},
	{ 0x8080800080000000ULL, 1, 5},

	{ 0x8000201008000000ULL, 5, 5},
	{ 0x8040001008000000ULL, 5, 5},
	{ 0x8040200008000000ULL, 5, 5},

	{ 0x0800204080000000ULL, 4, 4},
	{ 0x0810004080000000ULL, 4, 4},
	{ 0x0810200080000000ULL, 5, 5},
};

Pattern patterns_length_4_broken_opponent[12] = {
	{ 0x4000000000000000ULL, 5, 1},
	{ 0x2000000000000000ULL, 5, 1},
	{ 0x1000000000000000ULL, 5, 1},

	{ 0x0080000000000000ULL, 1, 5},
	{ 0x0000800000000000ULL, 1, 5},
	{ 0x0000008000000000ULL, 1, 5},

	{ 0x0040000000000000ULL, 5, 5},
	{ 0x0000200000000000ULL, 5, 5},
	{ 0x0000001000000000ULL, 5, 5},

	{ 0x0010000000000000ULL, 5, 5},
	{ 0x0000200000000000ULL, 5, 5},
	{ 0x0000004000000000ULL, 5, 5},
};

Pattern patterns_length_3[4] = {
	{ 0xE000000000000000ULL, 3, 1},
	{ 0x8080800000000000ULL, 1, 3},
	{ 0x8040200000000000ULL, 3, 3},
	{ 0x2040800000000000ULL, 3, 3},
}; // shift all of 1 bit to account for the opponent check

Pattern patterns_length_3_opponent[4] = {
	{ 0xE000000000000000ULL, 3, 1},
	{ 0x8080800000000000ULL, 1, 3},
	{ 0x8040200000000000ULL, 3, 3},
	{ 0x2040800000000000ULL, 3, 3},
}; // TODO

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

Pattern patterns_length_3_broken_opponent[8] = {
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
		5,6,7,8,8,7,6,5,
		6,7,8,9,9,8,7,6,
		7,8,9,10,10,9,8,7,
		8,9,10,11,11,10,9,8,
		8,9,10,11,11,10,9,8,
		7,8,9,10,10,9,8,7,
		6,7,8,9,9,8,7,6,
		5,6,7,8,8,7,6,5
};



#endif
