// CHESS
#include <iostream>
#include <vector>
#include <memory>

#include "Piece.hpp"
#include "Coordinate.hpp"

#include "narrator.hpp"
#include "init_board.hpp"	// initializes board
#include "draw_fns.hpp"		// functions for drawing and creates main objects of Coordinate
#include "setup_fns.hpp"

int main(){

	draw_board();



	initialize_regular();

	draw_board();

	// narrator();
	
	return 0;
}