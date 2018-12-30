#include <iostream>
#include <string>
#include "Board.hpp"

Board::Board(){
	bitboards[WHITE_BOARD] = 0x0ULL;
	bitboards[BLACK_BOARD] = 0x0ULL;
	bitboards[FULL_BOARD] = bitboards[WHITE_BOARD] | bitboards[BLACK_BOARD];
}

Board::Board(U64 board_w, U64 board_b){
	bitboards[WHITE_BOARD] = board_w;
	bitboards[BLACK_BOARD] = board_b;
	bitboards[FULL_BOARD] = board_w | board_b;
}

U64 Board::get_available_squares(){
	return ~bitboards[FULL_BOARD];
}

void Board::print_board(){
	int i, j;
	U64 board, bit;
	char motif;
	char motifs[3] = "OX";
	std::string out = "----------------------------------------------------------------";
	for(i = 0; i<2; i++){
		j = 0;
		board = bitboards[i];
		motif = motifs[i];
		while(board != 0){
			bit = board & 1;
			if(bit == 1)
				out[63-j] = motif;
			board >>= 1;			
			j++;
		}
	}


	for(i = 0; i<8; i++){
		std::cout << out.substr(8*i,8) <<std::endl;
	}

}
