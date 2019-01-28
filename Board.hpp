#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

#define WHITE_BOARD 0
#define BLACK_BOARD 1
#define FULL_BOARD 2

#define WHITE 0
#define BLACK 1

typedef std::uint64_t U64;

class Board{
	// A board will be represented as an 8x8 square
	// the bottom right corner will be our 0,0 and or 0th bit
	// as such the integer aaaaaaaabbbbbbb......hhhhhhhh wil be
	// aaaaaaaa
	// bbbbbbbb
	// ........
	// hhhhhhhh
	public:
		Board();
		Board(U64 board_w, U64 board_b);
		Board(const Board & obj);
		U64 get_available_squares();
		void print_board();
		int make_move(int bit, int side);
		U64* get_bitboards();
	private:
		U64 bitboards[3] = {};

};

#endif
