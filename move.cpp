#include "move.hpp"

Board board_after_move(move m){
	Board board = Board(m.board);
	board.make_move(m.index, m.side);
	return board;	
}
