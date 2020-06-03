// CHESS

/*
TODO:

-AI is in place but is totally random. Add some minimax

-Implement Stalemate game state? Maybe later not high priority.

BUGS

-In the checkmate_test() configuration, the kings moveset is not working properly, shows one 
 move that is actually illegal. The game will yell at you if you try to make that move, but its
 still weird that it even shows up as being possible.

OPTIMIZATIONS
-We can definitely optimize how we check for checkmate. Currently, we are simply looking
 through al available moves. 
 	-Maybe we could start by first checking if the king can move 
 	 himself out of check, then check if we can kill the piece causing check, THEN go through
 	 all possible moves.

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

#include "src/ai/ai.hpp"

#include "src/public/narrator.hpp"

int main(){

	srand(time(NULL));

	freopen("debug/output.txt", "w", stderr);

	initialize_regular();				// regular chess layout
	// pawn_firstmov_obst();				// test double first move and obstruction
	// pawn_capture_wrap();					// test to make sure diagonal capture doesnt wrap around the board
	// pawn_promote();						// test pawn promotion
	// rook_move_test();
	// bshp_move_test();
	// quen_move_test();
	// kngt_move_test();
	// king_move_test();
	// check_test();
	// checkmate_test();
	// what_the_hell_is_happening();
	// bshp_checkmate();
	// rook_checkmate();
	// kngt_checkmate();
	// pawn_checkmate();

	piece_value_assign();

	bool run {true};
	// bool run {false};

	system("clear");

	int choice;
	std::cout << " ~ Bashful Chess ~ \n";
	std::cout << "1. Human v Human\n2. Human v AI\n3. AI v AI\n";
	std::cout << "Please enter a choice between 1 and 3 : ";
	std::cin >> choice;
	system("clear");

	// 1 = White, -1 = black
	int turn {1};

	switch(choice){
		case 1:
			while(run){
				draw_board();
				if(narrator("human") == 420){
					return 0;
				}
				system("clear");

			}
			break;

		case 2:
			while(run){
				
				while(true){
					system("clear");
					draw_board();
					if(narrator("human") == 1)
						break;
					
				}

				draw_board();
				narrator("bot");
				system("clear");
			}

		// broken as fuck rn not at all usable
		case 3:
			while(run){
				
				draw_board();
				narrator("bot");
				system("clear");

				draw_board();
				narrator("bot");
				system("clear");
			}

	} 

	

	return 0;
}