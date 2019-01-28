#include "evaluation.hpp"

int evaluate(move m){

	Board position =  board_after_move(m);
	U64 *bitboards = position.get_bitboards();
	int side = m.side;
	int won = hasWon(bitboards[side]);

	return 0;
}

int hasWon(U64 bitboard){

	// We try to match the board with a five dots horizontally aligned pattern
	// 0x1F = 11111
	//This pattern is compared to every possible location if it is on a straight line
	for(int i  = 0; i < 8; i++){
		for (int j= 0; j < 8-5; j++){
			if ((bitboard && 0x1F)==0x1F){
				return 1;
			}
			bitboard >> 1;
		}
		bitboard >> 5;
	}


	// We try to match the board with a five dots vertically aligned pattern
	// 0x8080808080 = 1000 0000 
	//		 		  1000 0000
	//		 		  1000 0000
	//		 		  1000 0000
	//		 		  1000 0000
	//This pattern is compared to every possible location if it is on a straight line
	for(int i  = 0; i < 8*(8-5+1); i++){
			if ((bitboard && 0x8080808080)==0x8080808080){
				return 1;
		}
		bitboard >> 1;
	}





	// We try to match the board with a five dots diagonally aligned pattern to the rght
	// 0x100804020100 = 1 0000 0000
	//		 		      1000 0000
	//		 		      0100 0000
	//		 		      0010 0000
	//		 		      0001 0000
	//This pattern is compared to every possible location if it is on a straight line
	for(int i  = 0; i < 8-5 ; i++){
		for (int i= 0; i < 8-5; i++){
			if ((bitboard && 0x100804020100)==0x100804020100){
				return 1;
			}
		bitboard >> 1;
		}
	bitboard >> 5+1;
	}





	// We try to match the board with a five dots diagonally aligned pattern to the left
	//      0x102040810 = 0000 0001
	//		 		      0000 0010
	//		 		      0000 0100
	//		 		      0000 1000
	//		 		      0001 0000
	//This pattern is compared to every possible location if it is on a straight line

	for(int i  = 0; i < 8-5 ; i++){
		for (int i= 0; i < 8-5; i++){
			if ((bitboard && 0x102040810)==0x102040810){
				return 1;
			}
		bitboard >> 1;
		}
	bitboard >> 5+1;
	}

	return 0;
}