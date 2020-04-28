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

#include "src/public/coord_conversion.hpp"	// for converting a 2 character string into a board coordinate
#include "src/public/coord_checkers.hpp"	// checks validity of entered coordinates

#include "src/movesets/check_obstruction.hpp"
#include "src/movesets/pawn_moveset.hpp"
#include "src/movesets/display_moves.hpp"

#include "src/public/narrator.hpp"

int main(){

	freopen("output.txt", "w", stderr);

	// initialize_regular();			// regular chess layout
	pawn_firstmov_obst();			// test double first move and obstruction
	// pawn_capture_wrap();				// test to make sure diagonal capture doesnt wrap around the board

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