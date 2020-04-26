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

	initialize_regular();

	main_board.at(9).move_tenant(main_board.at(17));

	draw_board();

	// narrator();
	
	// std::vector<int*> test {new int(5)};

	return 0;
}