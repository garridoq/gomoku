#include "move.hpp"

Board board_after_move(move m){
	Board board = Board(m.board);
	board.make_move(m.index, m.side);
	return board;	
}

void copy(move* m_in, move* m_out){

	m_in->board = m_out->board;	
	m_in->index = m_out->index;	
	m_in->side = m_out->side;	
	m_in->evaluation = m_out->evaluation;	
	
}
