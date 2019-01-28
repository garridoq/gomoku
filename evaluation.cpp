#include "evaluation.hpp"

int evaluate(move m){

	Board position =  board_after_move(m);
	U64 *bitboards = position.get_bitboards();
	int side = m.side;
	int won = hasWon(bitboards[side]);

	return 0;
}

int hasWon(U64 bitboard){

	for(int i  = 0; i < 8; i++){
		for (int j= 0; j < 8-5; j++){
			if ((bitboard && 0x1F)==0x1F){
				return 1;
			}
			bitboard >> 1;
		}
		bitboard >> 5;
	}



	for(int i  = 0; i < 8*(8-5+1); i++){
			if ((bitboard && 0x8080808080)==0x8080808080){
				return 1;
		}
		bitboard >> 1;
	}



	for(int i  = 0; i < 8-5 ; i++){
		for (int i= 0; i < 8-5; i++){
			if ((bitboard && 0x100804020100)==0x100804020100){
				return 1;
			}
		bitboard >> 1;
		}
	bitboard >> 5+1;
	}



	for(int i  = 0; i < 8-5 ; i++){
		for (int i= 0; i < 8-5; i++){
			if ((bitboard && 20820820)==0x20820820){
				return 1;
			}
		bitboard >> 1;
		}
	bitboard >> 5+1;
	}

	return 0;
}