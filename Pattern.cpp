#include "Pattern.hpp"
#include <iostream>

int pattern_match(U64 bitboard, Pattern pattern){
	
	//Will return the number of times a pattern
	//matches in a given bitboard.
		
	int count = 0;
	int width = pattern.width;
	int height = pattern.height;
	U64 p = pattern.board;

	for(int i=0; i <= 8-height; ++i){
		for(int j = 0; j <= 8-width; ++j){
			if((U64)(p & bitboard) == p)
				count++;
			p >>= 1;
		}
		p >>= width-1;
	}
	return count;
}
