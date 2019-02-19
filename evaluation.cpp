#include "evaluation.hpp"
#include "patterns.hpp"
#include "Pattern.hpp"
#include <string>
#include <limits>

int evaluate(move m){
	int score;
	Board position =  board_after_move(m);
	U64 *bitboards = position.get_bitboards();
	int side = m.side;
	int won = hasWon(bitboards[side]);

	if(won == 1){
		score = 10000;
	}
	
	else{
		score = determineScore(bitboards, side);
	}

	return score;
}








int hasWon(U64 bitboard){
	for (int i = 0; i < 4; i++){
		  if( pattern_match(bitboard, winning_patterns[i]) > 0){
			  return 1;
		  }
	}
	return 0;
}




int determineScore(U64 *bitboards, int side){
	U64 playingBB = bitboards[side];
	U64 opponentBB = bitboards[1-side];

	int score = 0;
	for (int i = 0; i < 4; i++){
		score += 50 * pattern_match(playingBB, patterns_length_4[i]);
		
	}

	for (int i = 0; i < 4; i++){
		score += 20 * pattern_match(playingBB, patterns_length_3[i]);
		
	}



	return score;
}