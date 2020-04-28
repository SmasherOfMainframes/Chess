#ifndef __BOARD_SETUP__
#define __BOARD_SETUP__

// regular setup

//these should be converted to smart shared pointers for auto deletion
//or maybee it shouldnt for keeping track of shit later idk

/*

MAKE ALL REFERENCES TO TEAMS A STRING, NOT AN INTEGER
THIS IS IMPOSSIBLE TO WORK WITH

*/

std::vector<Piece*> teamB {
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Pawn(1, 'p', -1),
	new Piece(2, 'R', -1),
	new Piece(3, 'K', -1),
	new Piece(4, 'B', -1),
	new Piece(5, 'Q', -1),
	new Piece(6, '$', -1),
	new Piece(4, 'B', -1),
	new Piece(3, 'K', -1),
	new Piece(2, 'R', -1),
	
};
std::vector<Piece*> teamW {
	new Piece(2, 'R', 1),
	new Piece(3, 'K', 1),
	new Piece(4, 'B', 1),
	new Piece(6, '$', 1),
	new Piece(5, 'Q', 1),
	new Piece(4, 'B', 1),
	new Piece(3, 'K', 1),
	new Piece(2, 'R', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
	new Pawn(1, 'p', 1),
};

void initialize_regular(){
	for(int i = 0; i < 16; i++){
		main_board.at(i).set_tenant(teamW.at(i));
	}
	for(int i = 48; i < 64; i++){
		main_board.at(i).set_tenant(teamB.at(i-48));
	}
}

void initialize_pawn_move_check(){
	main_board.at(27).set_tenant(teamW.at(8));
	main_board.at(27-16+2).set_tenant(teamW.at(9));
	main_board.at(27+9).set_tenant(teamB.at(0));
	main_board.at(27+7).set_tenant(teamB.at(1));
	main_board.at(63).set_tenant(teamB.at(2));
}




#endif