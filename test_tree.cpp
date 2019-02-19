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
		m
	};	
	std::cout << "Generating children\n" << std::endl;
	gen_children(&n);

	print_node(&n);	

	gen_children(&(n.children[0]));
	print_node(&(n.children[0]));
	
	std::cout << "base node: "<< &n << "chidren's father node:" << n.children[0].parent << std::endl;
}
