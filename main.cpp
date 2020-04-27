// CHESS
#include <iostream>
#include <vector>
#include <string>

#include "Piece.hpp"
#include "Coordinate.hpp"

#include "init_board.hpp"	// initializes board
#include "draw_fns.hpp"		// functions for drawing and creates main objects of Coordinate
#include "setup_fns.hpp"
#include "coord_conversion.hpp"
#include "narrator.hpp"


int main(){

	initialize_regular();

	bool run {true};
	// bool run {false};

	system("clear");

	while(run){
		title();
		draw_board();
		narrator();
		system("clear");
	}

	return 0;
}