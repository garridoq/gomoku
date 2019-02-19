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
};

Pattern patterns_length_3[4] = {
	{ 0xE000000000000000ULL, 3, 1},
	{ 0x8080800000000000ULL, 1, 3},
	{ 0x8040200000000000ULL, 3, 3},
	{ 0x2040800000000000ULL, 3, 3},
};

Pattern patterns_length_2[4] = {
	{ 0xC000000000000000ULL, 2, 1},
	{ 0x8080000000000000ULL, 1, 2},
	{ 0x8040000000000000ULL, 2, 2},
	{ 0x4080000000000000ULL, 2, 2},
};

int value_coef[64] = {
		1,1,1,1,1,1,1,1,
		1,2,2,2,2,2,2,1,
		1,2,3,3,3,3,2,1,
		1,2,3,4,4,3,2,1,
		1,2,3,4,4,3,2,1,
		1,2,3,3,3,3,2,1,
		1,2,2,2,2,2,2,1,
		1,1,1,1,1,1,1,1
};
