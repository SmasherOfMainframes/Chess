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

void pawn_firstmov_obst(){
	// enmy team obstruction
	main_board.at(16).set_tenant(teamW.at(8));
	main_board.at(17).set_tenant(teamW.at(8));
	main_board.at(18).set_tenant(teamW.at(8));
	main_board.at(19).set_tenant(teamW.at(8));

	main_board.at(16+8).set_tenant(teamB.at(0));
	main_board.at(17+16).set_tenant(teamB.at(0));
	main_board.at(18+24).set_tenant(teamB.at(0));
	main_board.at(19+32).set_tenant(teamB.at(0));

	// same team obstruction
	main_board.at(20).set_tenant(teamW.at(8));
	main_board.at(21).set_tenant(teamW.at(8));
	main_board.at(22).set_tenant(teamW.at(8));
	main_board.at(23).set_tenant(teamW.at(8));

	main_board.at(20+8).set_tenant(teamW.at(8));
	main_board.at(21+16).set_tenant(teamW.at(8));
	main_board.at(22+24).set_tenant(teamW.at(8));
	main_board.at(23+24).set_tenant(teamW.at(9));
}
void pawn_capture_wrap(){
	main_board.at(7).set_tenant(teamW.at(8));

	main_board.at(7+7).set_tenant(teamB.at(0));
	main_board.at(7+9).set_tenant(teamB.at(0));

	main_board.at(40).set_tenant(teamW.at(8));

	main_board.at(40+7).set_tenant(teamB.at(0));
	main_board.at(40+9).set_tenant(teamB.at(0));

	main_board.at(38).set_tenant(teamW.at(8));
	main_board.at(9).set_tenant(teamW.at(8));

	main_board.at(3).set_tenant(teamW.at(8));
	main_board.at(60).set_tenant(teamB.at(0));
}
void pawn_promote(){
	main_board.at(40).set_tenant(teamW.at(8));
	main_board.at(23).set_tenant(teamB.at(0));
}



#endif