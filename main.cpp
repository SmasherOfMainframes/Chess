// CHESS

#include <iostream>
#include <vector>
#include <string>

#include "src/public/globals.hpp"			// Contains cosmetic info (colors, tile chars, etc)

#include "src/classes/Piece.hpp"
#include "src/classes/Coordinate.hpp"
#include "src/classes/Pawn.hpp"

#include "src/public/board_init.hpp"		// fn for initializes board
#include "src/public/board_draw.hpp"		// fn for drawing board
#include "src/public/board_setup.hpp"		// fn for setting up pieces on board

#include "src/movesets/pawn_movesets.hpp"

#include "src/public/coord_conversion.hpp"	// for converting a 2 character string into a board coordinate
#include "src/public/narrator.hpp"



int main(){

	freopen("output.txt", "w", stderr);

	initialize_regular();
	// initialize_pawn_move_check();

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