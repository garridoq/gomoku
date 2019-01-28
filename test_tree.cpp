#include <iostream>
#include "Board.hpp"
#include "move.hpp"
#include "move_tree.hpp"

int main(){
	
	Board board{0x101C2422200000ULL,0x2028201A00020200ULL};	
	
	move m = {
		board,
		62,
		WHITE
	};

	node n = {
		nullptr,
		m,
		nullptr
	};	
	std::cout << "Generating children\n" << std::endl;
	gen_children(&n);
	
	std::cout << n.children << std::endl;
}
