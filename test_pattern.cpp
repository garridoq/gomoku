#include <iostream>
#include "Board.hpp"
#include "Pattern.hpp"

int main(){
	
	U64 b = 0xC060600000020101ULL;
	Pattern pat{
			0x8040400000000000ULL,
			2,
			3
	};

	for(int i = 0; i < 100000000; i++){
		int count = pattern_match(b, pat);
//		std::cout << "On a matché :" << count << " fois" << std::endl;
	}
}
