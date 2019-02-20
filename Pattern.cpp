#include "Pattern.hpp"
#include <iostream>

int pattern_match(U64 bitboard, Pattern pattern ){
	
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


int pattern_match(U64 bitboard1, Pattern pattern1, U64 bitboard2, Pattern pattern2){
	
	//Will return the number of times a pattern
	//matches in a given bitboard.
		
	int count = 0;
	int width = std::max(pattern1.width, pattern2.width);
	int height = std::max(pattern1.height, pattern2.height);
	U64 p1 = pattern1.board;
	U64 p2 = pattern2.board;

	for(int i=0; i <= 8-height; ++i){
		for(int j = 0; j <= 8-width; ++j){
			if(((U64)(p1 & bitboard1) == p1) && ((U64)(p2 & bitboard2) == p2))
				count++;
			p1 >>= 1;
			p2 >>= 1;
		}
		p1 >>= width-1;
		p2 >>= width-1;
	}
	return count;
}
