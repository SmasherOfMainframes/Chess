// CHESS
#include <iostream>
#include <vector>
#include <string>

#define RESET   "\033[0m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"

#include "globals.hpp"			// Contains cosmetic info (colors, tile chars, etc)

#include "Piece.hpp"
#include "Coordinate.hpp"
#include "Pawn.hpp"

#include "move_list_fns.hpp"
#include "init_board.hpp"		// initializes board
#include "draw_fns.hpp"			// functions for drawing and creates main objects of Coordinate
#include "setup_fns.hpp"
#include "coord_conversion.hpp"	// for converting a 2 character string into a board coordinate
#include "narrator.hpp"




int main(){

	freopen("output.txt", "w", stderr);

	// initialize_regular();
	initialize_pawn_move_check();

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