#ifndef __BOARD_SETUP__
#define __BOARD_SETUP__



std::vector<int> check_vec_w;
std::vector<int> check_vec_b;

void team_vector_cleaner(std::vector<Piece*> &_vec){
	for(size_t i = 0; i < _vec.size() ; i++){
		if(_vec.at(i) -> get_coord() == -2){
			delete _vec.at(i);
			_vec.erase(_vec.begin()+i);
			i--;
		}
	}
}

std::vector<Piece*> teamB {
	new Pawn(1, 'p', -1),	// 0
	new Pawn(1, 'p', -1),	// 1
	new Pawn(1, 'p', -1),	// 2
	new Pawn(1, 'p', -1),	// 3
	new Pawn(1, 'p', -1),	// 4
	new Pawn(1, 'p', -1),	// 5
	new Pawn(1, 'p', -1),	// 6
	new Pawn(1, 'p', -1),	// 7
	new Piece(2, 'R', -1),	// 8
	new Piece(3, 'K', -1),	// 9
	new Piece(4, 'B', -1),	// 10
	new Piece(5, 'Q', -1),	// 11
	new Piece(6, '$', -1),	// 12
	new Piece(4, 'B', -1),	// 13
	new Piece(3, 'K', -1),	// 14
	new Piece(2, 'R', -1),	// 15
	
};
int KING_COORD_B;

std::vector<Piece*> teamW {
	new Piece(2, 'R', 1), 	// 0
	new Piece(3, 'K', 1), 	// 1
	new Piece(4, 'B', 1), 	// 2
	new Piece(6, '$', 1), 	// 3
	new Piece(5, 'Q', 1), 	// 4
	new Piece(4, 'B', 1), 	// 5
	new Piece(3, 'K', 1), 	// 6
	new Piece(2, 'R', 1), 	// 7
	new Pawn(1, 'p', 1),  	// 8
	new Pawn(1, 'p', 1),  	// 9
	new Pawn(1, 'p', 1),  	// 10
	new Pawn(1, 'p', 1),  	// 11
	new Pawn(1, 'p', 1),  	// 12
	new Pawn(1, 'p', 1),  	// 13
	new Pawn(1, 'p', 1),  	// 14
	new Pawn(1, 'p', 1),  	// 15
};
int KING_COORD_W;

void cerr_teams(){
	for(size_t i = 0; i < teamW.size(); i++){
		std::cerr << teamW.at(i)->get_coord() << " ";
	}
	std::cerr << "\n";
	for(size_t i = 0; i < teamB.size(); i++){
		std::cerr << teamB.at(i)->get_coord() << " ";
	}
	std::cerr << std::endl << std::endl;
}

void piece_value_assign(){
	for(size_t i = 0; i < teamW.size(); i++){
		switch(teamW.at(i)->get_rank()){
			case 1:
				teamW.at(i)->set_value(10);
				break;
			case 2:
				teamW.at(i)->set_value(50);
				break;
			case 3:
				teamW.at(i)->set_value(30);
				break;
			case 4:
				teamW.at(i)->set_value(30);
				break;
			case 5:
				teamW.at(i)->set_value(90);
				break;
			case 6:
				teamW.at(i)->set_value(900);
				break;
		}
	}
	for(size_t i = 0; i < teamB.size(); i++){
		switch(teamB.at(i)->get_rank()){
			case 1:
				teamB.at(i)->set_value(-10);
				break;
			case 2:
				teamB.at(i)->set_value(-50);
				break;
			case 3:
				teamB.at(i)->set_value(-30);
				break;
			case 4:
				teamB.at(i)->set_value(-30);
				break;
			case 5:
				teamB.at(i)->set_value(-90);
				break;
			case 6:
				teamB.at(i)->set_value(-900);
				break;
		}
	}
}

void initialize_regular(){
	for(int i = 0; i < 16; i++){
		main_board.at(i).set_tenant(teamW.at(i));
	}
	for(int i = 48; i < 64; i++){
		main_board.at(i).set_tenant(teamB.at(i-48));
	}
	KING_COORD_W = 3;
	KING_COORD_B = 60;
}

// void pawn_firstmov_obst(){
// 	// enmy team obstruction
// 	main_board.at(16).set_tenant(teamW.at(8));
// 	main_board.at(17).set_tenant(teamW.at(8));
// 	main_board.at(18).set_tenant(teamW.at(8));
// 	main_board.at(19).set_tenant(teamW.at(8));

// 	main_board.at(16+8).set_tenant(teamB.at(0));
// 	main_board.at(17+16).set_tenant(teamB.at(0));
// 	main_board.at(18+24).set_tenant(teamB.at(0));
// 	main_board.at(19+32).set_tenant(teamB.at(0));

// 	// same team obstruction
// 	main_board.at(20).set_tenant(teamW.at(8));
// 	main_board.at(21).set_tenant(teamW.at(8));
// 	main_board.at(22).set_tenant(teamW.at(8));
// 	main_board.at(23).set_tenant(teamW.at(8));

// 	main_board.at(20+8).set_tenant(teamW.at(8));
// 	main_board.at(21+16).set_tenant(teamW.at(8));
// 	main_board.at(22+24).set_tenant(teamW.at(8));
// 	main_board.at(23+24).set_tenant(teamW.at(9));
// }
// void pawn_capture_wrap(){
// 	main_board.at(7).set_tenant(teamW.at(8));

// 	main_board.at(7+7).set_tenant(teamB.at(0));
// 	main_board.at(7+9).set_tenant(teamB.at(0));

// 	main_board.at(40).set_tenant(teamW.at(8));

// 	main_board.at(40+7).set_tenant(teamB.at(0));
// 	main_board.at(40+9).set_tenant(teamB.at(0));

// 	main_board.at(38).set_tenant(teamW.at(8));
// 	main_board.at(9).set_tenant(teamW.at(8));

// 	main_board.at(3).set_tenant(teamW.at(8));
// 	main_board.at(60).set_tenant(teamB.at(0));
// }
// void pawn_promote(){
// 	main_board.at(40).set_tenant(teamW.at(8));
// 	main_board.at(23).set_tenant(teamB.at(0));
// }

void rook_move_test(){
	main_board.at(16).set_tenant(teamW.at(3));
	KING_COORD_W = 16;

	main_board.at(18).set_tenant(teamW.at(7));
	main_board.at(19).set_tenant(teamW.at(0));

	main_board.at(60).set_tenant(teamB.at(12));
	KING_COORD_B = 60;

	main_board.at(22).set_tenant(teamB.at(8));
	main_board.at(23).set_tenant(teamB.at(15));
}

// void bshp_move_test(){
// 	main_board.at(2).set_tenant(teamW.at(2));
// 	main_board.at(5).set_tenant(teamW.at(2));
// 	main_board.at(58).set_tenant(teamB.at(10));
// 	main_board.at(61).set_tenant(teamB.at(10));

// }


// void quen_move_test(){
// 	main_board.at(2).set_tenant(teamW.at(4));
// 	main_board.at(5).set_tenant(teamW.at(4));
// 	main_board.at(58).set_tenant(teamB.at(11));
// 	main_board.at(61).set_tenant(teamB.at(11));

// }

// void kngt_move_test(){
// 	main_board.at(27).set_tenant(teamW.at(1));
// 	main_board.at(34).set_tenant(teamW.at(1));

// 	main_board.at(42).set_tenant(teamW.at(1));

// }

// void king_move_test(){
// 	main_board.at(0).set_tenant(teamW.at(3));
// 	main_board.at(7).set_tenant(teamW.at(3));
// 	main_board.at(40).set_tenant(teamW.at(3));

// 	main_board.at(47).set_tenant(teamB.at(12));
// 	main_board.at(56).set_tenant(teamB.at(12));
// 	main_board.at(63).set_tenant(teamB.at(12));

// }

void check_test(){
	
	main_board.at(3).set_tenant(teamW.at(3));
	KING_COORD_W = 3;

	main_board.at(51).set_tenant(teamW.at(4));
	main_board.at(61).set_tenant(teamW.at(1));

	main_board.at(51-7-8).set_tenant(teamW.at(8));
	main_board.at(51-9-8).set_tenant(teamW.at(9));
	
	main_board.at(59).set_tenant(teamB.at(12));
	KING_COORD_B = 59;

	// main_board.at(4+17).set_tenant(teamB.at(11));

	main_board.at(18).set_tenant(teamB.at(0));
}

void checkmate_test(){

	main_board.at(3).set_tenant(teamW.at(3));
	KING_COORD_W = 3;

	// main_board.at(55).set_tenant(teamW.at(7));
	// main_board.at(54).set_tenant(teamW.at(0));
	main_board.at(52).set_tenant(teamW.at(8));

	main_board.at(60).set_tenant(teamB.at(12));
	KING_COORD_B = 60;

	main_board.at(9).set_tenant(teamB.at(8));
	main_board.at(8).set_tenant(teamB.at(15));

}

void what_the_hell_is_happening(){
	main_board.at(16).set_tenant(teamW.at(3));
	KING_COORD_W = 16;

	main_board.at(18).set_tenant(teamW.at(7));
	main_board.at(19-8).set_tenant(teamW.at(2));

	main_board.at(60).set_tenant(teamB.at(12));
	KING_COORD_B = 60;

	main_board.at(22).set_tenant(teamB.at(8));
	main_board.at(23).set_tenant(teamB.at(15));
}

void bshp_checkmate(){
	main_board.at(0).set_tenant(teamW.at(3));
	KING_COORD_W = 0;

	main_board.at(1).set_tenant(teamW.at(7));
	// main_board.at(19-8).set_tenant(teamW.at(2));

	main_board.at(23).set_tenant(teamB.at(12));
	KING_COORD_B = 23;

	main_board.at(7).set_tenant(teamB.at(10));
	// main_board.at(23).set_tenant(teamB.at(15));
}

void rook_checkmate(){
	main_board.at(0).set_tenant(teamW.at(3));
	KING_COORD_W = 0;

	main_board.at(1).set_tenant(teamW.at(7));

	main_board.at(23).set_tenant(teamB.at(12));
	KING_COORD_B = 23;

	main_board.at(13).set_tenant(teamB.at(8));
}

void kngt_checkmate(){
	main_board.at(0).set_tenant(teamW.at(0));
	KING_COORD_W = 0;

	main_board.at(1).set_tenant(teamW.at(7));

	main_board.at(23).set_tenant(teamB.at(12));
	KING_COORD_B = 23;

	main_board.at(13).set_tenant(teamB.at(9));
}

void pawn_checkmate(){
	main_board.at(56).set_tenant(teamW.at(3));
	KING_COORD_W = 56;

	main_board.at(1).set_tenant(teamW.at(7));
	main_board.at(41).set_tenant(teamW.at(8));

	main_board.at(23).set_tenant(teamB.at(12));
	KING_COORD_B = 23;

	main_board.at(6+32).set_tenant(teamB.at(0));
	main_board.at(3).set_tenant(teamB.at(8));
}



#endif