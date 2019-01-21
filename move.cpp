#include "move.hpp"

Board board_after_move(move m){

	m.board.make_move(m.index, m.side);
	return m.board;	
}
