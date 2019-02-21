#include "evaluation.hpp"
#include "patterns.hpp"
#include "Pattern.hpp"
#include <string>


int evaluate(move m){
	int score = 0;
	Board position =  board_after_move(m);
	U64 *bitboards = position.get_bitboards();
	int side = m.side;
	int won = hasWon(bitboards[side]);

	if(won == 1){
		score = 10000;
	}
	
	else{
		score += determineScore(bitboards, side);
		score -= determineScore(bitboards, 1 - side);
		
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


	// For a straight four : win at the next round
	for (int i = 0; i < 4; i++){
		score += 50 * pattern_match(playingBB, patterns_length_4_playing[i], opponentBB, patterns_length_4_opponent_v1[i]);
		score += 50 * pattern_match(playingBB, patterns_length_4_playing[i], opponentBB, patterns_length_4_opponent_v2[i]);
	}

	// For a broken four : may win at the next round
	for (int i = 0; i < 12; i++){
		score += 50 * pattern_match(playingBB, patterns_length_4_broken[i], opponentBB, patterns_length_4_broken_opponent[i]);
	}

	// For a straight three : win in two plays
	for (int i = 0; i < 4; i++){
		score += 20 * pattern_match(playingBB, patterns_length_3[i], opponentBB, patterns_length_3_opponent[i]);
	}

	// For a broken three
	for (int i = 0; i < 8; i++){
		score += 19 * pattern_match(playingBB, patterns_length_3_broken[i]);
	}

	// For two aligned
	for (int i = 0; i < 4; i++){
		score += 5 * pattern_match(playingBB, patterns_length_2[i]);
	}

	// For single or isolated points
	score += pattern_match(playingBB, pattern_single_or_isolated);



	return score;
}