// CHESS

/*
TODO:

-Implement Checkmate game state (in progress)
-Implement Stalemate game state

BUGS

-probably lots but i havent found any yet lmaoooo

-AI????
*/

#include <iostream>
#include <vector>
#include <deque>
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
#include "src/movesets/check_wrap.hpp"

#include "src/movesets/moveset_pawn.hpp"
#include "src/movesets/moveset_rook.hpp"
#include "src/movesets/moveset_bshp.hpp"
#include "src/movesets/moveset_quen.hpp"
#include "src/movesets/moveset_kngt.hpp"
#include "src/movesets/moveset_king.hpp"
#include "src/movesets/display_moves.hpp"

#include "src/public/king_check.hpp"

#include "src/public/narrator.hpp"

int main(){

	freopen("debug/output.txt", "w", stderr);

	// initialize_regular();				// regular chess layout
	// pawn_firstmov_obst();				// test double first move and obstruction
	// pawn_capture_wrap();					// test to make sure diagonal capture doesnt wrap around the board
	// pawn_promote();						// test pawn promotion
	// rook_move_test();
	// bshp_move_test();
	// quen_move_test();
	// kngt_move_test();
	// king_move_test();
	// check_test();
	checkmate_test();

	bool run {true};
	// bool run {false};

	system("clear");

	// Need to add a pre-game menu for selecting...
	//		-Human v Human
	//		-Human v AI
	//		-AI v AI

	while(run){
		// team_vector_cleaner(teamW);
		// team_vector_cleaner(teamB);

		// std::cerr << "TEAM BLACK\n";
		// for(size_t i = 0; i < teamB.size(); i++){
		// 	if(teamB.at(i) -> get_coord() != -2){
		// 		std::cerr << teamB.at(i) << " " << teamB.at(i) -> get_symbol() << "\n";
		// 	}
		// }
		// std::cerr << "TEAM WHITE\n";
		// for(size_t i = 0; i < teamW.size(); i++){
		// 	if(teamW.at(i) -> get_coord() != -2){
		// 		std::cerr << teamW.at(i) << " " << teamW.at(i) -> get_symbol() << "\n";
		// 	}
		// 

		title();
		draw_board();
		if(narrator() == 420){
			run == false;
			return 0;
		}
		system("clear");
	}

	return 0;
}