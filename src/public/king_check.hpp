#ifndef __KING_CHECK__
#define __KING_CHECK__

bool king_check(int _team){
	std::vector<std::vector<int>> king_vec;
	int king_coord;
	if(_team == 1){
		king_coord = KING_COORD_W;
		check_vec_w.clear();
	} else {
		king_coord = KING_COORD_B;
		check_vec_b.clear();
	}

	// Check if Bishop or Queen can capture
	bshp_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if Rook or Queen can capture
	rook_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if Knight can capture
	kngt_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if Pawn can capture
	pawn_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);

	// Check if other King can capture
	king_moves(king_vec, _team, king_coord, true);
	apply_moves(king_vec, king_coord);
	clear_moves(king_vec, king_coord);
	
	if(_team == 1 && check_vec_w.size() > 0){
		return true;
	} else if(_team == -1 && check_vec_b.size() > 0){
		return true;
	} else {
		return false;
	}
}


bool is_checkmate(int _team){
	std::vector<std::vector<int>> temp_move_vec;
	std::vector<Piece*> temp_team_vec;

	if( (_team == 1 && check_vec_w.size() > 0) || (_team == -1 && check_vec_b.size() > 0) ){

		if(_team == 1){
			temp_team_vec = teamW;
		} else {
			temp_team_vec = teamB;
		}

		for(size_t i = 0; i < temp_team_vec.size(); i++){
			if(temp_team_vec.at(i)->get_coord() == -2){break;}
			// coordinate of piece being evaluated
			int temp_piece_coord = temp_team_vec.at(i) -> get_coord();
			// return a vector of moves to iterate through to see if any will resolve check
			temp_move_vec = display_moves(temp_piece_coord, _team, "coord1");
			
			for(size_t j = 0; j < temp_move_vec.size(); j++){
				// coordinate of move
				int temp_coord = temp_piece_coord + temp_move_vec.at(j).at(0) + (8 * temp_move_vec.at(j).at(1));
				// store potential enemy piece incase we need to revert
				Piece* temp_piece {nullptr};
				if(main_board.at(temp_coord).get_tenant_team() == (_team*-1)){
					temp_piece = main_board.at(temp_coord).get_tenant();
				}

				// apply move
				move(temp_piece_coord, temp_coord, _team);

				// check if it resolves check
				// if yes, revert move and return false
				// else revert move and put captured piece back if necesary
				std::string dummy_message {""};
				if(!king_check(_team)){
					move(temp_coord, temp_piece_coord, _team);
					main_board.at(temp_coord).set_tenant(temp_piece);
					return false;
				} else {
					move(temp_coord, temp_piece_coord, _team);
					main_board.at(temp_coord).set_tenant(temp_piece);
				}
			}
			temp_move_vec = display_moves(temp_piece_coord, _team, "coord2");
		}
		// At this point, all current moves have been evaluated and none resolve check.
		// Therefor, checkmate
		return true;
	}
	return false;
}

// checks if moving a certain piece opens you up to check. if so, 
bool is_barrier(int _coord1, int _coord2, int _team, bool _king_check){
	// store potential enemy piece
	Piece* enemy = main_board.at(_coord2).get_tenant();

	// move actual piece to coord2
	move(_coord1, _coord2, _team);

	// king check
	if(!_king_check && king_check(_team)){
		move(_coord2, _coord1, _team);
		main_board.at(_coord2).set_tenant(enemy);
		return true;
	} else {
		move(_coord2, _coord1, _team);
		main_board.at(_coord2).set_tenant(enemy);
		return false;
	}
}

#endif