#include "evaluation.hpp"
#include <string>
#include <limits>

int evaluate(move m){
	int score;
	Board position =  board_after_move(m);
	U64 *bitboards = position.get_bitboards();
	int side = m.side;
	int won = hasWon(bitboards[side]);
	if(won == 1){
		std::string out = "Le joueur a gagné"; //TODO : le muméro du joueur
		exit;
	}
	else{
		int score;
		score = determineScore(bitboards, side);

	}

	return 0;
}








int hasWon(U64 bitboard){
 	// The variable checkVariable is used to determine if one of the methods (verti, horiz or diago) has detected a win for the player
	 int checkVariable = 0;


	// We try to match the board with a five dots horizontally aligned pattern
	// 0x1F = 11111
	//This pattern is compared to every possible location if it is on a straight line
	checkVariable = checkHorizontal(bitboard,0x1F,8);

	if(checkVariable != std::numeric_limits<int>::max()){
		return 1;
	}

	// We try to match the board with a five dots vertically aligned pattern
	// 0x8080808080 = 1000 0000 
	//		 		  1000 0000
	//		 		  1000 0000
	//		 		  1000 0000
	//		 		  1000 0000
	//This pattern is compared to every possible location if it is on a straight line
	
	checkVariable = checkVertical(bitboard,0x8080808080,8);
	
	if(checkVariable != std::numeric_limits<int>::max()){
		return 1;
	}

	// We try to match the board with a five dots diagonally aligned pattern to the rght
	// 0x100804020100 = 1 0000 0000
	//		 		      1000 0000
	//		 		      0100 0000
	//		 		      0010 0000
	//		 		      0001 0000
	//This pattern is compared to every possible location if it is on a straight line
	checkVariable = checkDiagRight(bitboard, 0x100804020100, 8);
	
	if(checkVariable != std::numeric_limits<int>::max()){
		return 1;
	}




	// We try to match the board with a five dots diagonally aligned pattern to the left
	//      0x102040810 = 0000 0001
	//		 		      0000 0010
	//		 		      0000 0100
	//		 		      0000 1000
	//		 		      0001 0000
	//This pattern is compared to every possible location if it is on a straight line
	checkVariable = checkDiagLeft(bitboard,0x102040810,8);
	
	if(checkVariable != std::numeric_limits<int>::max()){
		return 1;
	}

	return 0;
}












int determineScore(U64 *bitboards, int side){
	// Setup playing bitboard and opponent bitboard
	U64 playingBB = bitboards[side];
	U64 opponentBB = bitboards[1 - side];
	int checkVariable = 0;
	int score = 0;



	// BEGIN BY CHECKING WINNING FOURS
	// Guaranteed win for the next round
	// +1000 points

		// Horizontal
	checkVariable = checkHorizontal(playingBB,0x1F,8);

	if(checkVariable != std::numeric_limits<int>::max()){
		if( CheckSingle(opponentBB,0,checkVariable) || CheckSingle(opponentBB,0,checkVariable + 3) )
			score = score + 1000;
	}

		//Vertical
	checkVariable = checkVertical(playingBB,0x8080808080,8);
	
	if(checkVariable != std::numeric_limits<int>::max()){
		score = score + 1000;
	}





	// CHECK THREES
	// Possible win in two moves
	// + 300 points





	// CHECK OPPONENT THREES TO BLOCK
	// Decreases score if threats are on the board
	// - 300 points


	// GET OPPORTUNITIES



}






















int checkHorizontal(U64 bitboard, int mask, int boardSize){
	int n = 0;
	for(int i  = 0; i < boardSize; i++){
		for (int j= 0; j < boardSize-5; j++){
			if ((bitboard && mask)==mask){
				return n;
			}
			n = n+1;
			bitboard >> 1;
		}
		n = n+5;
		bitboard >> 5;
	}
	return std::numeric_limits<int>::max();
}




int checkVertical(U64 bitboard, int mask, int boardSize){
	int n = 0;
	for(int i  = 0; i < boardSize*(boardSize-5+1); i++){
		if ((bitboard && mask)==mask){
			return n;
		}
		n = n+1;
		bitboard >> 1;
	}
	return std::numeric_limits<int>::max();
}



int checkDiagRight(U64 bitboard, int mask, int boardSize){
	int n = 0;
	for(int i  = 0; i < boardSize-5 ; i++){
		for (int i= 0; i < boardSize-5; i++){
			if ((bitboard && mask)== mask){
				return n;
			}
		n = n+1;	
		bitboard >> 1;
		}

	n =	n+5+1;
	bitboard >> 5+1;
	}
	return std::numeric_limits<int>::max();
}



int checkDiagLeft(U64 bitboard, int mask, int boardSize){
	int n = 0;
	for(int i  = 0; i < boardSize-5 ; i++){
		for (int i= 0; i < boardSize-5; i++){
			if ((bitboard && mask)== mask){
				return n;
			}

		n = n+1;	
		bitboard >> 1;
		}

	n = n+5+1;	
	bitboard >> 5+1;
	}
	return std::numeric_limits<int>::max();
}

int CheckSingle(U64 bitboard, bool mask, int nPosition ){
	bitboard >> nPosition;
	if ((bitboard && 0x1)== mask){
		return 1;
	}
	return 0;
}

