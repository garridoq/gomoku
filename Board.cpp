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

Board::Board(const Board & obj){
	int i = 0;
	for(i; i < 3; i++){
		bitboards[i] = obj.bitboards[i];		
	}
}

U64 Board::get_available_squares(){
	return ~bitboards[FULL_BOARD];
}

U64* Board::get_bitboards(){
	return bitboards;
}

void Board::print_board(){
	// We will print the board using Os for white and Xs for black
	int i, j;
	U64 board, bit;
	char motif;
	char motifs[3] = "OX";
	std::string out = "|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|";
	for(i = 0; i<2; i++){
		j = 0;
		board = bitboards[i];
		motif = motifs[i];
		while(board != 0){
			bit = board & 1;
			if(bit == 1)
				out[2*(63-j)+1] = motif;
			board >>= 1;			
			j++;
		}
	}


	for(i = 0; i<8; i++){
		std::cout << 8-i<< "  " <<out.substr(16*i,16) <<"|" <<std::endl;
	}
	std::cout << "   |1|2|3|4|5|6|7|8|" <<std::endl;
}

int Board::make_move(int bit, int side){
	// Checking if inputs are correct
	// The coordinates must be converted to the corresponding bit
	if(bit < 0 || bit > 63){
		std::cout << "Error, the square is not on the board" << std::endl;
		return 1;
	}
	if(side != WHITE && side != BLACK){
		std::cout << "Error, you must chose a correct side" << std::endl;
		return 2;
	}
	// Checking if the move is pseudo legal
	// We will check if the position is won in th evaluation function
	if(is_legal_move(bit, side) == 0){
		
		return 3;
	}
	
	// We set the nth bit to 1 ( n = bit )	
	bitboards[side] |= 1ULL << bit;

	// Then update the full boardi
	// We can directly set the appropriate bit an not recalculate 
	// the combination of both sides
	bitboards[2] |= 1ULL << bit;
	
	return 0;
}

int Board::is_legal_move(int bit, int side){
	// Checking if the move is pseudo legal
	if(((bitboards[2] >> bit) & 1ULL) == 1){
		//std::cout << "Error, the square is alreay occupied" << std::endl;
		return 0;
	}
	return 1;
}

void print_bitboard(U64 b){
	// We will print the board using Os for white and Xs for black
	int i, j;
	U64 bit,board;
	board = b;
	char motif = 'X';
	std::string out = "----------------------------------------------------------------";
	for(i = 0; i<2; i++){
		j = 0;
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
