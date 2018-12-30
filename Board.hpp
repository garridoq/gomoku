#ifndef BOARD_H
#define BOARD_H

#include <cstdint>

#define WHITE_BOARD 0
#define BLACK_BOARD 1
#define FULL_BOARD 2


typedef std::uint64_t U64;

class Board{

	public:
		Board();
		Board(U64 board_w, U64 board_b);
		U64 get_available_squares();
		void print_board();
	private:
		U64 bitboards[3] = {};

};

#endif
